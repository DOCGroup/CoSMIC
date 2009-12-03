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



def dump_non_inheritable_type (classname, basic_type, outfile):
  
  outstr = """
  struct %(classname)s : public ::xml_schema::simple_type
  {
    public:
    
      explicit %(classname)s(%(basic_type)s x = %(basic_type)s())
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
  outfile.write (outstr)
  

def dump_inheritable_type (classname, baseclass, outfile):
  
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
  outfile.write(outstr)
 
non_inheritable = { "::xml_schema::boolean" : True, 
                    "::xml_schema::double_" : True,
                    "::xml_schema::string"  : False,
                    "::xml_schema::date"    : False,
                    "::xml_schema::id"      : False }

def write_types (root, function_dict, typedef_dict, outfile):
  
  for classid, function_list in function_dict.iteritems():
    qualified_cname = root.xpath("compounddef[@id='" + classid + "']/compoundname/text()")[0]
    for name_ret_pair in function_list:
      fname = name_ret_pair[0]
      return_type = name_ret_pair[1]
      tinfo = typedef_dict[return_type]
      
      if(tinfo.is_schema_type):
        print (tinfo.orig_type + " already exists.")      
        
      elif(len(tinfo.wrapper) > 0):
        if(not typedef_dict[tinfo.orig_type].is_schema_type):
          base_type = typedef_dict[tinfo.orig_type].typedef
          classname = qualified_cname.split("::")[-1]
          dump_inheritable_type(classname + "_" + fname, base_type, outfile)
        
      else:    
          classname = qualified_cname.split("::")[-1]
          if(non_inheritable[tinfo.orig_type]):
            dump_non_inheritable_type(classname + "_" + fname, tinfo.typedef, outfile)
          else:
            dump_inheritable_type(classname + "_" + fname, tinfo.typedef, outfile)
        

def write_prolog(namespace, outfile):
  guard_macro = "__" + namespace.upper() + "_META_HXX"
  outstr = """\
#ifndef %(guard_macro)s
#define %(guard_macro)s

#define DOMAIN_NAMESPACE %(namespace)s
#include "Kind_Traits.h"

#include "%(namespace)s.hxx"

namespace %(namespace)s {
""" % locals()
  outfile.write(outstr)


def write_epilog(namespace, outfile):
  guard_macro = "__" + namespace.upper() + "_META_HXX"
  outstr = """\

} // namespace %(namespace)s 

#endif // %(guard_macro)s
""" % locals()
  outfile.write(outstr)


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
    funclassname = fnode.xpath("name/text()")[0]               # Find function name
    ret_type = get_return_type_from_function_node(fnode)   # Find function's return type
    funclassname_ret_pair = (funclassname, ret_type)               # Make a pair
    tuple_list.append(funclassname_ret_pair);                  # Append the pair in the list

  function_dict[class_id] = tuple_list                     # Associate the list with the class_id

  bases = node.xpath("basecompoundref/text()")             # Obtain a list of bases
  baseclass_dict[class_id] = bases                         # Associate the list with the claas_id

# Both the dictionaries are populated at this point.

print ("Printing function dictionary: ")
for key, value in function_dict.iteritems():
  print (key, value)

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


print ("Printing typedef dictionary: ")
for key, value in typedef_dict.iteritems():
  print (key)
  print (value.wrapper, value.orig_type, value.is_schema_type, value.typedef)


namespace = root.xpath("compounddef[@kind='namespace']/compoundname/text()")[0]
outfilename = namespace + "-meta.hxx"
outfile = open(outfilename, 'w')

write_prolog(namespace, outfile)
write_types(root, function_dict, typedef_dict, outfile)
write_epilog(namespace, outfile)


outfile.close()


















