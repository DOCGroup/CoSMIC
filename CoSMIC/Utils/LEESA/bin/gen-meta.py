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

  def __str__(self):
    return "['" + self.wrapper + "' '" + self.orig_type + "' '" + str(self.is_schema_type) + "' '" + self.typedef + "' '" + self.return_type + "']"
    

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



def dump_non_inheritable_type (classname, basic_type, meta_header_file):
  
  outstr = """
  struct %(classname)s : 
    public ::xml_schema::simple_type,
    public LEESA::VisitorAsIndex_CRTP < %(classname)s, visitor >
  {
    public:
    
      %(classname)s(%(basic_type)s const & x)
        : val_(const_cast<%(basic_type)s *>(&x)) { }
               
      %(classname)s(%(basic_type)s & x)
        : val_(&x) { }
               
      operator %(basic_type)s & () {
        // For booleans, safe-bool idiom should be used.
        return *(this->val_);
      }

      operator %(basic_type)s const & () const {
        // For booleans, safe-bool idiom should be used.
        return *(this->val_);
      }

      virtual %(classname)s * _clone (::xml_schema::flags f,
                                      ::xml_schema::container * c) const
      {
        return new %(classname)s(*(this->val_));
      }

      virtual void accept (visitor & v);
      virtual void leave (visitor & v);
      using LEESA::VisitorAsIndex_CRTP < %(classname)s, visitor >::operator [];

    private:
    
      %(basic_type)s * val_;
  };
  """ % locals()
  meta_header_file.write (outstr)
  

def dump_inheritable_type (classname, baseclass, meta_header_file):
  
  outstr = """
  struct %(classname)s : 
    public %(baseclass)s, 
    public LEESA::VisitorAsIndex_CRTP < %(classname)s, visitor >
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
    virtual void accept (visitor & v);
    virtual void leave (visitor & v);
    using LEESA::VisitorAsIndex_CRTP < %(classname)s, visitor >::operator [];
  };
  """ % locals()
  meta_header_file.write(outstr)
 

def write_types (root, function_dict, typedef_dict, meta_header_file):
  
  for classid, function_list in function_dict.items():
    qualified_cname = root.xpath("compounddef[@id='" + classid + "']/compoundname/text()")[0]
    for name_ret_pair in function_list:
      fname = name_ret_pair[0]
      return_type = name_ret_pair[1]
      tinfo = typedef_dict[return_type]
      
      if(tinfo.is_schema_type):
        tinfo.return_type = tinfo.typedef + " & "
        
      elif(len(tinfo.wrapper) > 0):
        if(typedef_dict[tinfo.orig_type].is_schema_type):
           tinfo.return_type = tinfo.typedef + " & "
        else:
          base_type = typedef_dict[tinfo.orig_type].typedef
          # The following classname is the new type being introduced.
          classname = qualified_cname.split("::")[-1] + "_" + fname
          dump_inheritable_type(classname, base_type, meta_header_file)
          tinfo.return_type = tinfo.wrapper + "< " + classname + " > "
        
      elif(non_inheritable[tinfo.orig_type]):
        # The following classname is the new type being introduced.
        classname = qualified_cname.split("::")[-1]  + "_" + fname
        dump_non_inheritable_type(classname, tinfo.typedef, meta_header_file)
        tinfo.return_type = namespace + "::" + classname
      
      else:
        # The following classname is the new type being introduced.
        classname = qualified_cname.split("::")[-1]  + "_" + fname
        dump_inheritable_type(classname, tinfo.typedef, meta_header_file)
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
children_kind(%(qualified_cname)s & x, %(child_type)s);

const %(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s);
""" % locals()
  meta_header_file.write(outstr)


def write_function_definition(return_type, qualified_cname, child_type, body):
  outstr = """
%(return_type)s
children_kind(%(qualified_cname)s & x, %(child_type)s)
{\
  %(body)s\
}

const %(return_type)s
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
  for classid, function_list in function_dict.items():
    write_recursive_function_list(classid, classid, function_dict, typedef_dict)
     

def get_all_member_functions_of(classid, function_dict, baseclass_dict):
  functions = function_dict[classid]
  
  if(len(baseclass_dict[classid]) > 0):
    for baseid in baseclass_dict[classid]:
      functions[len(functions):] = get_all_member_functions_of(baseid, function_dict, baseclass_dict)

  return functions
  
    
def inherit_baseclass_functions(function_dict, baseclass_dict):
  for classid, function_list in function_dict.items():
    flist = get_all_member_functions_of(classid, function_dict, baseclass_dict)
    function_dict[classid] = flist


def write_header_prolog(namespace, orig_header_without_ext, meta_header_file):
  guard_macro = "__" + orig_header_without_ext.upper() + "_META_HXX"
  if(namespace != ""):
    outstr = """\
#ifndef %(guard_macro)s
#define %(guard_macro)s

#include "%(orig_header_without_ext)s.hxx"

#define DOMAIN_NAMESPACE %(namespace)s
#include "Kind_Traits.h"

namespace %(namespace)s {
""" % locals()
    meta_header_file.write(outstr)
  else:
    outstr = """\
#ifndef %(guard_macro)s
#define %(guard_macro)s

#include "%(orig_header_without_ext)s.hxx"

#define NO_NAMESPACE
#define DOMAIN_NAMESPACE 
#include "Kind_Traits.h"

""" % locals()
    meta_header_file.write(outstr)
    


def write_header_epilog(namespace, orig_header_without_ext, meta_header_file):
  guard_macro = "__" + orig_header_without_ext.upper() + "_META_HXX"
  if(namespace != ""):
    outstr = """\

} // namespace %(namespace)s 

#endif // %(guard_macro)s
""" % locals()
    meta_header_file.write(outstr)
  else:
    outstr = """\

#endif // %(guard_macro)s
""" % locals()
    meta_header_file.write(outstr)


def write_cpp_prolog (namespace, orig_header_without_ext, cpp_file):
  if(namespace != ""):
    outstr = """\
#include "%(orig_header_without_ext)s-meta.hxx"

namespace %(namespace)s {
""" % locals()
    cpp_file.write(outstr)
  else:
    outstr = """\
#include "%(orig_header_without_ext)s-meta.hxx"

""" % locals()
    cpp_file.write(outstr)
    


def write_cpp_epilog (namespace, orig_header_wihtout_ext, cpp_file):
  if(namespace != ""):
    outstr = """
} // namespace %(namespace)s
""" % locals()
    cpp_file.write(outstr)


def write_schema_traits (all_types_set, children_dict, parent_dict, meta_header_file):
  outstr = """
template <class T>
struct _Wrapper
{
  typedef typename ::xsd::cxx::tree::sequence <T> Container;
  typedef typename ::xsd::cxx::tree::optional <T> Optional;
};
"""
  meta_header_file.write(outstr)

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

    meta_header_file.write(outstr)

 
def populate_functions_and_baseclasses(function_dict, baseclass_dict, root):
  compound_nodes = root.xpath("compounddef[@kind='class']")

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


def populate_typedef_dictionary(typedef_dict, root):
  for key, value in function_dict.items():
    typedef_nodes = root.xpath("compounddef[@id='" + key + "']//memberdef[@kind='typedef']")

    for tnode in typedef_nodes:
      tinfo = extract_type_info(tnode)
      typename = tnode.xpath("name/text()")[0]
      typedef_dict[typename] = tinfo


def write_accept_functions(namespace, orig_header_file, enhanced_header_file, root):
  compound_nodes = root.xpath("compounddef[@kind='class']")
  class_end_dict = {}
  class_start_dict = {}
  
  for node in compound_nodes:
    cname = node.xpath("compoundname/text()")[0].split("::")[-1]
    bodystart = int(node.xpath("location/@bodystart")[0]) + 1
    bodyend = int(node.xpath("location/@bodyend")[0])
    class_end_dict[bodyend] = cname
    class_start_dict[bodystart] = cname
  
  mode = "prolog"
  i = 0
  for line in orig_header_file:
    i+=1
    if(i in class_end_dict):
      cname = class_end_dict[i]
      line = """
  public:

    virtual void accept (visitor & v);
    virtual void leave (visitor & v);
    using LEESA::VisitorAsIndex_CRTP< %(cname)s,  visitor >::operator [];
  };
""" % locals()
    elif(i in class_start_dict):
      cname = class_start_dict[i]
      line = """\
      , public LEESA::VisitorAsIndex_CRTP< %(cname)s, visitor >
  {
""" %locals()
    
    if(mode == "prolog" and "Begin prologue." in line):
      line = """\
#include "LEESA_VisitorAsIndex.h"
// Begin prologue.
"""
      mode = "forward"
    if(mode == "forward" and "Forward declarations." in line):
      if(namespace != ""):
        line="""\
namespace %(namespace)s 
{
  class visitor;
  typedef xml_schema::type type;
}
// Forward declarations.
""" % locals()
        mode = "done"
        enhanced_header_file.write(line)
      else:
        line="""\
class visitor;
typedef xml_schema::type type;
// Forward declarations.
"""
        mode = "done"
    
    enhanced_header_file.write(line)
        
  
  
def write_accept_definitions(all_types_set, cpp_file):
  for t in all_types_set:
    cname = t.split("::")[-1]
    outstr = """
void %(cname)s::accept(visitor & v) {
  v.visit_%(cname)s (*this);
}

void %(cname)s::leave(visitor & v) {
  v.leave_%(cname)s (*this);
}
""" % locals()
  
    cpp_file.write(outstr)
  
def write_visitor(all_types_set, meta_header_file):
  outstr = """
class visitor {
  public:
"""
  meta_header_file.write(outstr)
  for t in all_types_set:
    cname = t.split("::")[-1]
    outstr = """
    virtual void visit_%(cname)s(%(cname)s & x) {}
    virtual void leave_%(cname)s(%(cname)s & x) {}
""" % locals()

    meta_header_file.write(outstr)
  
  meta_header_file.write("\n};\n")
  
  
def push_descendants (parent, descendants, children_dict):
  children = children_dict[parent]
  descendants[len(descendants):] = children
  for c in children:
    if c in children_dict:
      push_descendants(c, descendants, children_dict)


  
def write_descendant_pairs(children_dict, meta_header_file):
  outstr = """
#ifndef DOMAIN_HAS_DESCENDANT_PAIRS
#define DOMAIN_HAS_DESCENDANT_PAIRS
#endif // DOMAIN_HAS_DESCENDANT_PAIRS

  struct _False_ { enum { value = 0 }; };
  struct _True_  { enum { value = 1 }; };

  template <class T, class U>
  struct IsDescendant : _False_ {};
 
""" % locals()
  meta_header_file.write(outstr)

  
  for ancestor in sorted(children_dict.keys()):
    descendants = []
    push_descendants (ancestor, descendants, children_dict)
    for descendant in sorted(descendants):
      meta_header_file.write(
      """  template <> struct IsDescendant < %(ancestor)s, %(descendant)s > : _True_ { };\n""" % locals())
    
    meta_header_file.write("\n")


def print_dictionary(dict, message):
  print (message)
  for key, value in sorted(dict.items()):
    print (key)
    print (value)


def usage():
  print("python gen-meta.py < -xsd | -udm > <header file>")
  
    
try:
  import re
  import os
  import sys
  import os.path
  import subprocess
  import fileinput
  import tempfile
  import shutil
  from lxml import etree
  #print("Running with lxml.etree")
except ImportError:
  try:
    # Python 2.5
    import xml.etree.cElementTree as etree
    #print("Running with cElementTree on Python 2.5+")
  except ImportError:
    try:
      # Python 2.5
      import xml.etree.ElementTree as etree
      #print("Running with ElementTree on Python 2.5+")
    except ImportError:
      try:
        # normal cElementTree install
        import cElementTree as etree
        #print("Running with cElementTree")
      except ImportError:
        try:
          # normal ElementTree install
          import elementtree.ElementTree as etree
          #print("Running with ElementTree")
        except ImportError:
          print("Failed to import ElementTree from any known place.")
          quit()

if(len(sys.argv) != 3):
  usage()
  quit()

tool = ""        
if(sys.argv[1] == "-xsd"):
  tool = "xsd"
elif(sys.argv[1] == "-udm"):
  tool = "udm"
else:
  usage()
  quit()

orig_header_file_name = sys.argv[2]
cpp_file_name = ""

if (tool == "udm"):
  print("Udm is not supported yet.")
  quit()

if(not os.path.exists(orig_header_file_name)):
  print(orig_header_file_name + " does not exist.")
  quit()

orig_header_without_ext = orig_header_file_name.split(".")[0]
  
try: 
  name_parts = orig_header_file_name.split(".")
  if(name_parts[1] == "hxx"):
    cpp_file_name = orig_header_without_ext + ".cxx"
  elif(name_parts[1] == "h"):
    cpp_file_name = orig_header_without_ext + ".cpp"
  else:
    raise Exception()
except Exception:
  print ("Specified header file does not seem to have a known extension.")
  quit()
  
if(not os.path.exists(cpp_file_name)):
  print(cpp_file_name + " does not exist.")

pwd = os.getcwd()
tempdir = tempfile.mkdtemp(dir = pwd)
shutil.copy(orig_header_file_name, tempdir)
os.chdir(tempdir)

try:  
  subprocess.call(["doxygen",  "-g"])
except OSError:
  print("Can't find doxygen in path")
  os.chdir(pwd)
  quit()
  
if(not os.path.exists("Doxyfile")):
  print("Doxyfile was not generated. Please make sure you have the latest version of doxygen installed.")  
  os.chdir(pwd)
  quit()

for line in fileinput.FileInput("Doxyfile",inplace=1):
    if "GENERATE_XML" in line:
      line=line.replace("NO","YES")
    sys.stdout.write(line)

try:  
  returncode = subprocess.call(["doxygen"])
except OSError:
  print("Can't find doxygen in path")
  os.chdir(pwd)
  quit()
  
os.chdir("xml")

try:  
  combined_xml_file = open("all.xml", 'w')
  subprocess.call(["xsltproc", "combine.xslt", "index.xml"], stdout = combined_xml_file)
  combined_xml_file.close()
except OSError:
  print("Can't find xsltproc in path. Please make sure you have installed xsltproc and it is the path.")
  os.chdir(pwd)

shutil.copy("all.xml", pwd)
os.chdir(pwd)
shutil.rmtree(tempdir)
  
non_inheritable = { "::xml_schema::boolean"                 : True, 
                    "::xml_schema::double_"                 : True,
                    "::xml_schema::float_"                  : True,
                    "::xml_schema::decimal"                 : True,
                    "::xml_schema::byte"                    : True,
                    "::xml_schema::unsigned_byte"           : True,
                    "::xml_schema::short_"                  : True,
                    "::xml_schema::unsigned_short"          : True,
                    "::xml_schema::int_"                    : True,
                    "::xml_schema::unsigned_int"            : True,
                    "::xml_schema::long_"                   : True,
                    "::xml_schema::unsigned_long"           : True,
                    "::xml_schema::integer"                 : True,
                    "::xml_schema::non_positive_integer"    : True,
                    "::xml_schema::non_negative_integer"    : True,
                    "::xml_schema::positive_integer"        : True,
                    "::xml_schema::negative_integer"        : True,

                    "::xml_schema::string"                  : False,
                    "::xml_schema::normalized_string"       : False,
                    "::xml_schema::token"                   : False,
                    "::xml_schema::name"                    : False,
                    "::xml_schema::nmtoken"                 : False,
                    "::xml_schema::nmtokens"                : False,
                    "::xml_schema::ncname"                  : False,
                    "::xml_schema::language"                : False,
                    "::xml_schema::id"                      : False,
                    "::xml_schema::idref"                   : False,
                    "::xml_schema::idrefs"                  : False,
                    "::xml_schema::uri"                     : False,
                    "::xml_schema::qname"                   : False,
                    "::xml_schema::buffer"                  : False,
                    "::xml_schema::base64_binary"           : False,
                    "::xml_schema::hex_binary"              : False,
                    "::xml_schema::date"                    : False,
                    "::xml_schema::time_zone"               : False,
                    "::xml_schema::date_time"               : False,
                    "::xml_schema::duration"                : False,
                    "::xml_schema::gday"                    : False,
                    "::xml_schema::gmonth"                  : False,
                    "::xml_schema::gmonth_day"              : False,
                    "::xml_schema::gyear"                   : False,
                    "::xml_schema::gyear_month"             : False,
                    "::xml_schema::time"                    : False }


f = open("all.xml", 'r')
root = etree.parse(f).getroot()
f.close()

# function_dict contains the mapping of class_id to accessor member functions and 
# their return types. Accesor name and its return type are grouped together in a pair.
# Each class_id maps to a list of pairs. baseclass_dict contains the mapping of 
# class_id to its base classes. Base classes are grouped together in list.
function_dict = {}
baseclass_dict = {}
populate_functions_and_baseclasses(function_dict, baseclass_dict, root)
#print_dictionary(baseclass_dict, "Printing baseclass dictionary: ")

# Maintains information of nested typedefs inside schema classes
typedef_dict = {}
populate_typedef_dictionary(typedef_dict, root)

namespace = root.xpath("compounddef[@kind='namespace']/compoundname/text()")[0]
if(namespace == "xml_schema"):
  print("Looks like schema does not have any namespace. Using global namespace.")
  namespace = ""
else:
  print("Using namespace = ", namespace)

meta_header_filename = orig_header_without_ext + "-meta.hxx"
meta_header_file = open(meta_header_filename, 'w')
cpp_filename = orig_header_without_ext + "-meta.cxx"
cpp_file = open(cpp_filename, 'w')

write_header_prolog(namespace, orig_header_without_ext, meta_header_file)
write_cpp_prolog(namespace, orig_header_without_ext, cpp_file)

print_dictionary(typedef_dict, "************************Printing typedef dictionary: ***************************** ")
# This function updates the typedef dictionary.
write_types(root, function_dict, typedef_dict, meta_header_file)

print_dictionary(typedef_dict, "Printing typedef dictionary: ")
print_dictionary(function_dict, "Printing function dictionary: ")

# Populate these two dictionaries while writing functions.
children_dict = {}
parent_dict = {}
all_types_set = set()

write_functions(root, function_dict, baseclass_dict, typedef_dict)

print_dictionary(children_dict, "Printing children dictionary:")
print_dictionary(parent_dict, "Printing parent dictionary:")

print ("Printing all types:")
print (all_types_set)

write_accept_definitions(all_types_set, cpp_file)

shutil.copy(orig_header_file_name, orig_header_file_name + ".bak")
orig_header_file = open(orig_header_file_name + ".bak", 'r')
enhanced_header_file = open(orig_header_file_name, 'w')

write_accept_functions(namespace, orig_header_file, enhanced_header_file, root)
write_schema_traits (all_types_set, children_dict, parent_dict, meta_header_file)
write_descendant_pairs(children_dict, meta_header_file)
write_visitor(all_types_set, meta_header_file)



write_header_epilog(namespace, orig_header_without_ext, meta_header_file)
write_cpp_epilog(namespace, orig_header_without_ext, cpp_file)

orig_header_file.close()
enhanced_header_file.close()
meta_header_file.close()
cpp_file.close()











