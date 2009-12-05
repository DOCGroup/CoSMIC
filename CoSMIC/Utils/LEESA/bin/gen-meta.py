#!/usr/bin/python


def remove_cv_qualifiers(raw_type_str):
  strng = raw_type_str.replace("const ","")
  strng = strng.replace("&","")
  return strng.strip()
  

def get_return_type_from_function_node(node):
  raw_type_str = node.xpath("type/text()")[0] 
  type_str = remove_cv_qualifiers(raw_type_str)
  if (len(type_str) > 0):
    return type_str
  else:
    raw_type_str = node.xpath("type/ref/text()")[0] 
    type_str = remove_cv_qualifiers(raw_type_str)
    return type_str


class TypeInfo:
  wrapper = ""
  orig_type = ""
  is_schema_type = False
  typedef = ""
  return_type = "####"


def extract_type_info (typedef_node):

  tinfo = TypeInfo()

  ref_nodes = typedef_node.xpath("type/ref") 
  if(len(ref_nodes) > 0):
    
    tinfo.orig_type = ref_nodes[0].text
    wrapper = typedef_node.xpath("type/text()")[0]
    
    if(wrapper.count("::xsd::cxx::tree::traits") > 0):
      tinfo.is_schema_type = False
      tinfo.wrapper = "::xsd::cxx::tree::traits"
    
    elif(wrapper.count("::xsd::cxx::tree::optional") > 0):
      tinfo.is_schema_type = False
      tinfo.wrapper = "::xsd::cxx::tree::optional"
    
    elif(wrapper.count("::xsd::cxx::tree::sequence") > 0):
      tinfo.is_schema_type = False
      tinfo.wrapper = "::xsd::cxx::tree::sequence"

    elif(wrapper.count("::xsd::cxx::tree::idref") > 0):
      tinfo.is_schema_type = False
      tinfo.wrapper = "::xsd::cxx::tree::idref"

    else:
      tinfo.is_schema_type = True
      tinfo.wrapper = ""

    # The last literal in the typedef is the actual type we are looking for.
    tinfo.typedef = typedef_node.xpath("definition/text()")[0].split()[-1]

  else:
    wrapper = typedef_node.xpath("type/text()")[0]
    m = re.match(".+<(.+)>.*", wrapper)
    if m: 
      tinfo.orig_type = m.group(1).strip()
    else: 
      tinfo.orig_type = ""
    
    if(wrapper.count("::xsd::cxx::tree::traits") > 0):
      tinfo.wrapper = "::xsd::cxx::tree::traits"
    
    elif(wrapper.count("::xsd::cxx::tree::optional") > 0):
      tinfo.wrapper = "::xsd::cxx::tree::optional"
    
    elif(wrapper.count("::xsd::cxx::tree::sequence") > 0):
      tinfo.wrapper = "::xsd::cxx::tree::sequence"

    elif(wrapper.count("::xsd::cxx::tree::idref") > 0):
      tinfo.wrapper = "::xsd::cxx::tree::idref"

    else:
      tinfo.wrapper = ""
      tinfo.orig_type = typedef_node.xpath("type/text()")[0]
    
    tinfo.is_schema_type = False
    tinfo.typedef = typedef_node.xpath("definition/text()")[0].split()[-1]

  return tinfo



def dump_non_inheritable_type (classname, basic_type, header_file):
  
  outstr = """
  struct %(classname)s : public ::xml_schema::simple_type
  {
    public:
    
      %(classname)s(%(basic_type)s x = %(basic_type)s())
        : val_(x) { }
               
      operator %(basic_type)s () {
        // For booleans, safe-bool idiom should be used.
        return this->val_;
      }

      virtual %(classname)s* _clone (::xml_schema::flags f,
                                      ::xml_schema::container * c) const
      {
        return new %(classname)s(this->val_);
      }
    private:
    
      %(basic_type)s val_;
  };
  """ % locals()
  header_file.write (outstr)
  

def dump_inheritable_type (classname, baseclass, header_file):
  
  outstr = """
  struct %(classname)s : public %(baseclass)s
  {
    typedef %(baseclass)s super;
    %(classname)s () { }
    %(classname)s (const super & x) 
      : super (x)
    { }
    %(classname)s (const %(classname)s & x, 
                   ::xml_schema::flags f = 0, 
                   ::xml_schema::container * c = 0)
      : super(x, f, c) 
    { }
    virtual %(classname)s * _clone (::xml_schema::flags f, 
                                    ::xml_schema::container * c) const 
    {
      return new %(classname)s (*this, f, c);
    }
  };
  """ % locals()
  header_file.write(outstr)
 
non_inheritable = { "::xml_schema::boolean" : True, 
                    "::xml_schema::double_" : True,
                    "::xml_schema::string"  : False,
                    "::xml_schema::date"    : False,
                    "::xml_schema::id"      : False }

def write_types (root, function_dict, typedef_dict, header_file):
  
  for classid, function_list in function_dict.iteritems():
    qualified_cname = root.xpath("compounddef[@id='" + classid + "']/compoundname/text()")[0]
    for name_ret_pair in function_list:
      fname = name_ret_pair[0]
      return_type = name_ret_pair[1]
      tinfo = typedef_dict[return_type]
      
      if(tinfo.is_schema_type):
        tinfo.return_type = "const " + tinfo.typedef + " & "
        
      elif(len(tinfo.wrapper) > 0):
        if(typedef_dict[tinfo.orig_type].is_schema_type):
           tinfo.return_type = "const " + tinfo.typedef + " & "
        else:
          base_type = typedef_dict[tinfo.orig_type].typedef
          # The following classname is the new type being introduced.
          classname = qualified_cname.split("::")[-1] + "_" + fname
          dump_inheritable_type(classname, base_type, header_file)
          tinfo.return_type = tinfo.wrapper + "< " + classname + " > "
        
      elif(non_inheritable[tinfo.orig_type]):
        # The following classname is the new type being introduced.
        classname = qualified_cname.split("::")[-1]  + "_" + fname
        dump_non_inheritable_type(classname, tinfo.typedef, header_file)
        tinfo.return_type = namespace + "::" + classname
      
      else:
        # The following classname is the new type being introduced.
        classname = qualified_cname.split("::")[-1]  + "_" + fname
        dump_inheritable_type(classname, tinfo.typedef, header_file)
        tinfo.return_type = namespace + "::" + classname


def push_dictionary(qualified_cname, child_type):
    length = 0
    if(qualified_cname in children_dict):
      length = len(children_dict[qualified_cname])
    else:
      children_dict[qualified_cname] = []
    
    children_dict[qualified_cname][length:] = [ child_type ]

    length = 0
    if(child_type in parent_dict):
      length = len(parent_dict[child_type])
    else:
      parent_dict[child_type] = []

    parent_dict[child_type][length:] = [ qualified_cname ]

    # Duplicate entries are dropped automatically.
    all_types_set.add(qualified_cname)
    all_types_set.add(child_type)


def write_function_declaration(return_type, qualified_cname, child_type):
  outstr = """
%(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s);
""" % locals()
  header_file.write(outstr)


def write_function_definition(return_type, qualified_cname, child_type, body):
  outstr = """
%(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s)
{\
  %(body)s\
}
""" % locals()
  cpp_file.write(outstr)


def write_one_function_list(qualified_cname, real_parent, function_list, typedef_dict):
  for pair in function_list:
    return_type = typedef_dict[pair[1]].return_type
    child_type = ""

    if(len(typedef_dict[pair[1]].wrapper) > 0):
      #Deref orig_type and check is_schema_type
      if(typedef_dict[typedef_dict[pair[1]].orig_type].is_schema_type):
        child_type = typedef_dict[typedef_dict[pair[1]].orig_type].orig_type
      else:
        child_type = namespace + "::" + real_parent + "_" + pair[0]
    elif(typedef_dict[pair[1]].is_schema_type):
      child_type = namespace + "::" + pair[0]
    else:        
      child_type = namespace + "::" + real_parent + "_" + pair[0]

    push_dictionary(qualified_cname, child_type)    
    write_function_declaration(return_type, qualified_cname, child_type)
    
    fname = pair[0]
    body = "\n  return x." + fname + "();\n"
    if(typedef_dict[pair[1]].wrapper.count("::xsd::cxx::tree::optional") > 0):
      body = """
  if (x.%(fname)s()) 
  {
    return ::xsd::cxx::tree::optional<%(child_type)s>(x.%(fname)s().get());
  }
  else 
  {
    return ::xsd::cxx::tree::optional<%(child_type)s>();
  }
""" % locals()
    
    
    write_function_definition(return_type, qualified_cname, child_type, body)



def write_recursive_function_list(classid, real_parent_id, function_dict, typedef_dict):
  function_list = function_dict[real_parent_id]
  qualified_cname = root.xpath("compounddef[@id='" + classid + "']/compoundname/text()")[0]
  real_parent_cname = root.xpath("compounddef[@id='" + real_parent_id + "']/compoundname/text()")[0].split("::")[-1]
  
  write_one_function_list(qualified_cname, real_parent_cname, function_list, typedef_dict)
  if(len(baseclass_dict[real_parent_id]) > 0):
    for baseid in baseclass_dict[real_parent_id]:
      write_recursive_function_list(classid, baseid, function_dict, typedef_dict)


def write_functions(root, function_dict, baseclass_dict, typedef_dict):
  for classid, function_list in function_dict.iteritems():
    write_recursive_function_list(classid, classid, function_dict, typedef_dict)
     

def get_all_member_functions_of(classid, function_dict, baseclass_dict):
  functions = function_dict[classid]
  
  if(len(baseclass_dict[classid]) > 0):
    for baseid in baseclass_dict[classid]:
      functions[len(functions):] = get_all_member_functions_of(baseid, function_dict, baseclass_dict)

  return functions
  
    
def inherit_baseclass_functions(function_dict, baseclass_dict):
  for classid, function_list in function_dict.iteritems():
    flist = get_all_member_functions_of(classid, function_dict, baseclass_dict)
    function_dict[classid] = flist


def write_header_prolog(namespace, header_file):
  guard_macro = "__" + namespace.upper() + "_META_HXX"
  outstr = """\
#ifndef %(guard_macro)s
#define %(guard_macro)s

#define DOMAIN_NAMESPACE %(namespace)s
#include "Kind_Traits.h"

#include "%(namespace)s.hxx"

namespace %(namespace)s {
""" % locals()
  header_file.write(outstr)


def write_header_epilog(namespace, header_file):
  guard_macro = "__" + namespace.upper() + "_META_HXX"
  outstr = """\

} // namespace %(namespace)s 

#endif // %(guard_macro)s
""" % locals()
  header_file.write(outstr)

def write_cpp_prolog (namespace, cpp_file):
  outstr = """\
#include "%(namespace)s-meta.hxx"

namespace %(namespace)s {
""" % locals()
  cpp_file.write(outstr)


def write_cpp_epilog (namespace, cpp_file):
  outstr = """
} // namespace %(namespace)s
""" % locals()
  cpp_file.write(outstr)


def write_schema_traits (all_types_set, children_dict, parent_dict, header_file):
  outstr = """
template <class T>
struct _Wrapper
{
  typedef typename ::xsd::cxx::tree::sequence <T> Container;
  typedef typename ::xsd::cxx::tree::optional <T> Optional;
};
"""
  header_file.write(outstr)

  for t in all_types_set:
    children_kinds = ""
    parent_kinds = ""
    metakind = "LEESA::AtomMetaTag"

    if(t in children_dict):
      children_kinds = ",".join(children_dict[t])
      metakind = "LEESA::ModelMetaTag"

    if(t in parent_dict):
      parent_kinds = ",".join(parent_dict[t])

    outstr = """
template <>
struct SchemaTraits< %(t)s > : public _Wrapper< %(t)s > {
  typedef boost::mpl::vector < %(children_kinds)s > ChildrenKinds;
  typedef boost::mpl::vector < %(parent_kinds)s > ParentKinds;
  typedef %(metakind)s MetaKind;
};
""" % locals()

    header_file.write(outstr)


try:
  import re
  from lxml import etree
  print("Running with lxml.etree")
except ImportError:
  try:
    # Python 2.5
    import xml.etree.cElementTree as etree
    print("Running with cElementTree on Python 2.5+")
  except ImportError:
    try:
      # Python 2.5
      import xml.etree.ElementTree as etree
      print("Running with ElementTree on Python 2.5+")
    except ImportError:
      try:
        # normal cElementTree install
        import cElementTree as etree
        print("Running with cElementTree")
      except ImportError:
        try:
          # normal ElementTree install
          import elementtree.ElementTree as etree
          print("Running with ElementTree")
        except ImportError:
          print("Failed to import ElementTree from any known place")
          quit()

f = open("all.xml", 'r')
root = etree.parse(f).getroot()
f.close()

compound_nodes = root.xpath("compounddef[@kind='class']")

# Contains the mapping of class_id to accessor member functions and their
# return types. Accesor name and its return type are grouped together in a pair.
# Each class_id maps to a list of pairs.
function_dict = {}

# Contains the mapping of class_id to its base classes. Base classes are
# grouped together in list.
baseclass_dict = {}

for node in compound_nodes:
  class_id = node.xpath("@id")[0]
  func_nodes = node.xpath("sectiondef[@kind='public-func']/memberdef[@kind='function' and @static='no' and @const='yes' and @virt='non-virtual']")
  
  tuple_list = []
  for fnode in func_nodes:
    funclassname = fnode.xpath("name/text()")[0]           # Find function name
    ret_type = get_return_type_from_function_node(fnode)   # Find function's return type
    funclassname_ret_pair = (funclassname, ret_type)       # Make a pair
    tuple_list.append(funclassname_ret_pair);              # Append the pair in the list

  function_dict[class_id] = tuple_list                     # Associate the list with the class_id

  bases = node.xpath("basecompoundref/@refid")             # Obtain a list of bases
  baseclass_dict[class_id] = bases                         # Associate the list with the claas_id

# Both the dictionaries are populated at this point.

print ("Printing baseclass dictionary: ")
for key, value in baseclass_dict.iteritems():
  print (key, value)

# Maintains information of nested typedefs inside schema classes
typedef_dict = {}

for key, value in function_dict.iteritems():
  typedef_nodes = root.xpath("compounddef[@id='" + key + "']//memberdef[@kind='typedef']")

  for tnode in typedef_nodes:
    tinfo = extract_type_info(tnode)
    typename = tnode.xpath("name/text()")[0]
    typedef_dict[typename] = tinfo

namespace = root.xpath("compounddef[@kind='namespace']/compoundname/text()")[0]
header_filename = namespace + "-meta.hxx"
header_file = open(header_filename, 'w')
cpp_filename = namespace + "-meta.cxx"
cpp_file = open(cpp_filename, 'w')

write_header_prolog(namespace, header_file)
write_cpp_prolog(namespace, cpp_file)

# This function updates the typedef dictionary.
write_types(root, function_dict, typedef_dict, header_file)

print ("Printing typedef dictionary: ")
for key, value in typedef_dict.iteritems():
  if(key.count("_traits") == 0):
    print (key)
    print (value.wrapper, value.orig_type, value.is_schema_type, value.typedef, value.return_type)

print ("Printing function dictionary: ")
for key, value in function_dict.iteritems():
  print (key, value)

# Populate these two dictionaries while writing functions.
children_dict = {}
parent_dict = {}
all_types_set = set()
write_functions(root, function_dict, baseclass_dict, typedef_dict)

print ("Printing children dictionary:")
for key, value in children_dict.iteritems():
  print (key, value)

print ("Printing parent dictionary:")
for key, value in parent_dict.iteritems():
  print (key, value)

print ("Printing all types:")
print (all_types_set)

write_schema_traits (all_types_set, children_dict, parent_dict, header_file)


write_header_epilog(namespace, header_file)
write_cpp_epilog(namespace, cpp_file)


header_file.close()
cpp_file.close()











