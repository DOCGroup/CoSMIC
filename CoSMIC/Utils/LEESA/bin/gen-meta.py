#!/usr/bin/python


def remove_cv_qualifiers(raw_type_str):
  strng = raw_type_str.replace("const","")
  strng = strng.replace("&","")
  strng = strng.replace("*","")
  return strng.strip()
  

def get_return_type_from_function_node(root, class_id, fnode):
  raw_type_str = fnode.xpath("type/text()")[0] 
  ret_type = remove_cv_qualifiers(raw_type_str)
  if (len(ret_type) == 0):
    raw_type_str = fnode.xpath("type/ref/text()")[0] 
    ret_type = remove_cv_qualifiers(raw_type_str)

  query = """compounddef[@id='%(class_id)s']
            /sectiondef[@kind='public-type']
            /memberdef[@kind='typedef'][name/text() = '%(ret_type)s']
            /definition/text()""" % locals()

  return root.xpath(query)[0].split()[-1]


def remove_non_schema_types(function_dict, typedef_dict):
  for classid, function_list in function_dict.items():
    index = -1
    for name_ret_pair in function_list[:]:
      index += 1
      func_name = name_ret_pair[0]
      ret_type = name_ret_pair[1]
      if (ret_type in typedef_dict):
        if (not typedef_dict[ret_type].is_schema_type):
          orig_type = typedef_dict[ret_type].orig_type 
          if (orig_type in typedef_dict):
            if (not typedef_dict[orig_type].is_schema_type):
              del typedef_dict[orig_type]
              del typedef_dict[ret_type]
              if(len(function_list) > 0):
                del function_list[index]
                index -= 1
          else:
            del typedef_dict[ret_type]
            if(len(function_list) > 0):
              del function_list[index]
              index -= 1




class TypeInfo:
  wrapper = ""
  orig_type = ""
  is_schema_type = False

  def __str__(self):
    return "['" + self.wrapper + "' '" + self.orig_type + "' '" + str(self.is_schema_type) + "']"
    
  def __eq__(self, other):
    return (self.wrapper == other.wrapper) and (self.orig_type == other.orig_type) and (self.is_schema_type == other.is_schema_type)
    

def extract_type_info (typedef_node):
  tinfo = TypeInfo()

  ref_nodes = typedef_node.xpath("type/ref") 
  if(len(ref_nodes) > 0):
    
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

    if (not tinfo.is_schema_type):
      # Prepend full qualification of the typedef. That means namespace::classname::typedef
      # Full qualification is needed to disambiguate same typedefs in different classes
      tinfo.orig_type = typedef_node.xpath("definition/text()")[0].split()[-1].rpartition("::")[0] + "::" + ref_nodes[0].text 
    else:
      tinfo.orig_type = ref_nodes[0].text
    
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

  return tinfo



def populate_typedef_dictionary(function_dict, typedef_dict, root):
  for classid in function_dict.keys():
    typedef_nodes = root.xpath("compounddef[@id='" + classid + "']//memberdef[@kind='typedef']")

    for tnode in typedef_nodes:
      tinfo = extract_type_info(tnode)
      typename = tnode.xpath("name/text()")[0]
      if((not typename.endswith("_iterator")) and (not typename.endswith("_traits"))):
        typedef = tnode.xpath("definition/text()")[0].split()[-1]
        typedef_dict[typedef] = tinfo


def push_dictionary(qualified_cname, child_type):
    length = 0
    if(qualified_cname in children_dict):
      length = len(children_dict[qualified_cname])
    else:
      children_dict[qualified_cname] = []
    
    children_dict[qualified_cname][length:] = [ child_type ]

    global max_length

    if(max_length < len(children_dict[qualified_cname])):
      max_length = len(children_dict[qualified_cname]) 

    length = 0
    if(child_type in parent_dict):
      length = len(parent_dict[child_type])
    else:
      parent_dict[child_type] = []

    parent_dict[child_type][length:] = [ qualified_cname ]

    if(max_length < len(parent_dict[child_type])):
      max_length = len(parent_dict[child_type]) 


def synthesize_function_declaration(return_type, qualified_cname, child_type, conflicting_types):
  global synthesized_function_declarations
  
  if(len(conflicting_types) > 0):
    str_types = ", ".join(conflicting_types)
    outstr = """
/************ %(child_type)s conflicts with %(str_types)s
%(return_type)s
children_kind(%(qualified_cname)s & x, %(child_type)s const *);

const %(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s const *);
************/
""" % locals()
    synthesized_function_declarations += outstr

  else:
    outstr = """
%(return_type)s
children_kind(%(qualified_cname)s & x, %(child_type)s const *);

const %(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s const *);
""" % locals()
    synthesized_function_declarations += outstr


def synthesize_function_definition(return_type, qualified_cname, child_type, fname):
  global synthesized_function_definitions
  outstr = """
%(return_type)s
children_kind(%(qualified_cname)s & x, %(child_type)s const *)
{
  return x.%(fname)s();
}

const %(return_type)s
children_kind(const %(qualified_cname)s & x, %(child_type)s const *)
{
  return x.%(fname)s();
}
""" % locals()
  synthesized_function_definitions += outstr



def get_conflicting_types(type, tyepdef_dict):
  """Finds typedefs defined in the same class that conflict. General algo 
     is: Find a type definition that is identical to type but for a 
     different key. If the type definitions is coming from a different
     class, neglect it. This is a pretty slow function for large dictionaries.""" 
  conflicting_types = []
  if type in typedef_dict:
    typedef = typedef_dict[type] # Look for an identical typedef mapped under a different key.
    for key, value in typedef_dict.items():
      if((typedef == value) and (type != key) and (type.rpartition("::")[0] == key.rpartition("::")[0])):
        conflicting_types.append(key)

  return conflicting_types


def synthesize_one_function_list(qualified_cname, real_parent, function_list, typedef_dict):
  for pair in function_list:
    if(pair[1] in typedef_dict):
      fname = pair[0]
      return_type = pair[1] + " & "
      typedef_child_type = "::"

      if(len(typedef_dict[pair[1]].wrapper) > 0):
        original_type = typedef_dict[pair[1]].orig_type 
        actual_child_class = typedef_dict[original_type].orig_type
      elif(typedef_dict[pair[1]].is_schema_type):
        original_type = pair[1]
        actual_child_class = typedef_dict[pair[1]].orig_type

      typedef_child_type = qualified_cname + "::" + fname + "_type"
      push_dictionary(qualified_cname, actual_child_class)    
      conflicting_types = get_conflicting_types(original_type, typedef_dict);

      synthesize_function_declaration(return_type, qualified_cname, typedef_child_type, conflicting_types)
      if(len(conflicting_types) == 0):
        synthesize_function_definition(return_type, qualified_cname, typedef_child_type, fname)



def synthesize_recursive_function_list(classid, real_parent_id, function_dict, typedef_dict):
  function_list = function_dict[real_parent_id]
  qualified_cname = root.xpath("compounddef[@id='" + classid + "']/compoundname/text()")[0]
  real_parent_cname = root.xpath("compounddef[@id='" + real_parent_id + "']/compoundname/text()")[0].split("::")[-1]
  
  synthesize_one_function_list(qualified_cname, real_parent_cname, function_list, typedef_dict)
  sys.stdout.write(".")
  sys.stdout.flush()
  if(len(baseclass_dict[real_parent_id]) > 0):
    for baseid in baseclass_dict[real_parent_id]:
      synthesize_recursive_function_list(classid, baseid, function_dict, typedef_dict)


def synthesize_functions(root, function_dict, baseclass_dict, typedef_dict):
  for classid, function_list in function_dict.items():
    synthesize_recursive_function_list(classid, classid, function_dict, typedef_dict)
     

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


def write_header_prolog(no_visitor, max_length, namespace, orig_header_without_ext, meta_header_file):
  guard_macro = "__" + orig_header_without_ext.upper() + "_META_HXX"
  outstr = """\
#ifndef %(guard_macro)s
#define %(guard_macro)s

#include "%(orig_header_without_ext)s.hxx"

#ifndef DOMAIN_HAS_DESCENDANT_PAIRS
#define DOMAIN_HAS_DESCENDANT_PAIRS
#endif // DOMAIN_HAS_DESCENDANT_PAIRS
""" % locals()
  meta_header_file.write(outstr)
  
  if(max_length > 20):
    vector_size = (max_length/10 + 1)*10 
    outstr = """
#define BOOST_MPL_CFG_NO_PREPROCESSED_HEADERS
#define BOOST_MPL_LIMIT_VECTOR_SIZE %(vector_size)s
""" % locals()
    meta_header_file.write(outstr)

  if(no_visitor):
    outstr = """
#ifndef LEESA_NO_VISITOR
#define LEESA_NO_VISITOR
#endif // LEESA_NO_VISITOR
"""
    meta_header_file.write(outstr)

  if(namespace != ""):
    outstr = """\

#define DOMAIN_NAMESPACE %(namespace)s
#include "Kind_Traits.h"

namespace %(namespace)s {
""" % locals()
    meta_header_file.write(outstr)
  else:
    outstr = """\

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
struct ContainerTraits
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
      children_kinds = ", ".join(children_dict[t])
      metakind = "LEESA::ModelMetaTag"

    if(t in parent_dict):
      parent_kinds = ", ".join(parent_dict[t])

    outstr = """
template <>
struct SchemaTraits< %(t)s > : public ContainerTraits< %(t)s > {
  typedef boost::mpl::vector < %(children_kinds)s > ChildrenKinds;
  //typedef boost::mpl::vector < %(parent_kinds)s > ParentKinds;
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
      func_name = fnode.xpath("name/text()")[0]                              # Find function name
      ret_type = get_return_type_from_function_node(root, class_id, fnode)   # Find function's return type
      funcname_ret_pair = (func_name, ret_type)                              # Make a pair
      tuple_list.append(funcname_ret_pair);                                  # Append the pair in the list

    function_dict[class_id] = tuple_list                                     # Associate the list with the class_id

    bases = node.xpath("basecompoundref/@refid")                             # Obtain a list of bases
    baseclass_dict[class_id] = bases                                         # Associate the list with the claas_id



def write_forward_declarations(namespace, orig_header_file, enhanced_header_file):
  for line in orig_header_file:
    if("Forward declarations." in line):
      if(namespace != ""):
        line="""\
namespace %(namespace)s 
{
  typedef xml_schema::type type;
}
// Forward declarations.
""" % locals()
      else:
        line="""\
typedef xml_schema::type type;
// Forward declarations.
"""
    
    enhanced_header_file.write(line)


def write_accept_declarations(namespace, orig_header_file, enhanced_header_file, root):
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
  for qualified_cname in all_types_set:
    cname = qualified_cname.split("::")[-1]
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
  for qualified_cname in all_types_set:
    cname = qualified_cname.split("::")[-1]
    outstr = """
    virtual void visit_%(cname)s(%(cname)s & x) {}
    virtual void leave_%(cname)s(%(cname)s & x) {}
""" % locals()

    meta_header_file.write(outstr)
  
  meta_header_file.write("\n};\n")
  
  
def populate_all_types(root, all_types_set):
  all_class_names = root.xpath("compounddef[@kind='class']/compoundname/text()")
  for cname in all_class_names:
    all_types_set.add(cname)
  
  
def push_descendants (parent, descendants, children_dict, visited):
  children = children_dict[parent]
  descendants[len(descendants):] = children
  for c in children:
    if((c in children_dict) and (not c in visited)):
      visited.add(c)
      push_descendants(c, descendants, children_dict, visited)


  
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
    visited = set()
    push_descendants (ancestor, descendants, children_dict, visited)
    descendants = sorted(list(set(descendants)))
    for descendant in descendants:
      meta_header_file.write(
      """  template <> struct IsDescendant < %(ancestor)s, %(descendant)s > : _True_ { };\n""" % locals())
    
    meta_header_file.write("\n")


def transform_xsd(xsd_file_name):
  xsd_file = open(xsd_file_name, 'r')
  root = etree.parse(xsd_file).getroot()
  xsd_file.close()

  NSMAP = { root.prefix : 'http://www.w3.org/2001/XMLSchema'} 
  
  xsd_basic_types = ["boolean",      "byte",          "date",         "dateTime",     "decimal",
                     "double",       "duration",      "float",        "int",          "integer", 
                     "language",     "long", "Short", "string",       "time",         "token",        
                     "unsignedByte", "unsignedInt",   "unsignedLong", "unsignedShort", ]
  all_types = ""

  for t in xsd_basic_types:
    # Append all types in the @type predicate.
    all_types = all_types + " @type='" + root.prefix + ":" + t + "' or " 
  
  all_types = all_types[:all_types.rfind("or")] # remove the last "or"
  query = "//" + root.prefix + ":element[" + all_types + "]"

  element_nodes = root.xpath(query, namespaces=NSMAP)
  for n in element_nodes:
    simpleType = etree.Element("{http://www.w3.org/2001/XMLSchema}simpleType") 
    simpleType.append(etree.Element("{http://www.w3.org/2001/XMLSchema}restriction", {'base' : n.attrib["type"] }))
    n.append(simpleType)
    del(n.attrib["type"])

  print(etree.tostring(root, pretty_print = True))


def print_dictionary(dict, message):
  print (message)
  for key, value in sorted(dict.items()):
    print (key)
    print (value)


def generate_xml():
  global orig_header_file_name

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
      if re.match("GENERATE_XML.+=.+", line):
        line=line.replace("NO","YES")
      elif re.match("WARNINGS.+=.+", line):
        line=line.replace("YES","NO")
      elif re.match("WARN_IF_UNDOCUMENTED.+=.+", line):
        line=line.replace("YES","NO")
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
    print("Can't find xsltproc in path. Please make sure you have installed xsltproc and it is in the path.")
    os.chdir(pwd)

  shutil.copy("all.xml", pwd)
  os.chdir(pwd)
  shutil.rmtree(tempdir)


def usage():
  print("Usage #1: python gen-meta.py -doxygen <top level header file>")
  print("Usage #2: python gen-meta.py -doxygen -no-visitor <top level header file>")
  print("Usage #3: python gen-meta.py -no-doxygen (reads all.xml) <top level header file>")
  print("Usage #4: python gen-meta.py -no-doxygen (reads all.xml) -no-visitor <top level header file>")
  print("Usage #4: python gen-meta.py -transform-xsd <source xsd file>")
  print("Note: all.xml should be obtained by running doxygen on *.hxx only.")
  
    
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

if(len(sys.argv) < 3):
  usage()
  quit()

tool = ""        
if(sys.argv[1] == "-doxygen"):
  tool = "doxygen"
elif(sys.argv[1] == "-no-doxygen"):
  tool = "no-doxygen"
elif(sys.argv[1] == "-transform-xsd"):
  if(len(sys.argv) != 3):
    usage()
    quit()
  else:
    if (not os.path.exists(sys.argv[2])):
      print(sys.argv[2] + " does not exist.")
    else:
      transform_xsd(sys.argv[2])
    quit()
else:
  usage()
  quit()

no_visitor = False 
orig_header_file_name = ""
cpp_file_name = ""

if(sys.argv[2] == "-no-visitor"):
  if(len(sys.argv) != 4):
    usage()
    quit()
  
  no_visitor = True
  orig_header_file_name = sys.argv[3]
else:
  orig_header_file_name = sys.argv[2]

if((tool == "doxygen" or tool == "no-doxygen") and (not os.path.exists(orig_header_file_name))):
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

if(tool == "doxygen"):
  generate_xml()


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
populate_typedef_dictionary(function_dict, typedef_dict, root)

namespace = root.xpath("compounddef[@kind='namespace']/compoundname/text()")[0]
if(namespace == "xml_schema"):
  print("Looks like schema does not have any namespace. Using global namespace.")
  namespace = ""
else:
  print("Using namespace = ", namespace)

# This function removes non-schema types from both the directories.
# Particularly, simple content nodes do not have their own vocabulary-specific
# types. Those functions and basic types are neglected. If vocabulary-specific
# types for them are desired, please change the schema. Simply add
# <xsd:simpleType> 
#   <xsd:extension base="xsd:whatever_basic_type" />
# </xsd:simpleType>
remove_non_schema_types(function_dict, typedef_dict)
print_dictionary(typedef_dict, "############################ Printing typedef dictionary: ############################# ")
print_dictionary(function_dict, "$$$$$$$$$$$$$$$$$$$$$$$$$$ Printing function dictionary: $$$$$$$$$$$$$$$$$$$$$$")

# Populate these two dictionaries while synthesizing data access functions.
# It also updates the max_length that determines
# BOOST_MPL_LIMIT_VECTOR_SIZE
children_dict = {}
parent_dict = {}
max_length = 0
synthesized_function_declarations = ""
synthesized_function_definitions = ""
print("============================ Synthesizing functions =========================")
synthesize_functions(root, function_dict, baseclass_dict, typedef_dict)

meta_header_filename = orig_header_without_ext + "-meta.hxx"
meta_header_file = open(meta_header_filename, 'w')
cpp_filename = orig_header_without_ext + "-meta.cxx"
cpp_file = open(cpp_filename, 'w')

write_header_prolog(no_visitor, max_length, namespace, orig_header_without_ext, meta_header_file)
write_cpp_prolog(namespace, orig_header_without_ext, cpp_file)
meta_header_file.write(synthesized_function_declarations)
cpp_file.write(synthesized_function_definitions)

# Populate the fully qualified names of the types. Namespace prefix will be there.
all_types_set = set()
populate_all_types(root, all_types_set)

print_dictionary(children_dict, "%%%%%%%%%%%%%%%%%%%%%%%%%%% Printing children dictionary: %%%%%%%%%%%%%%%%%%%%%%%%%%%%")
print_dictionary(parent_dict, "@@@@@@@@@@@@@@@@@@@@@@@@@@@ Printing parent dictionary: @@@@@@@@@@@@@@@@@@@@@@@@@@@@@")

print ("**************************** Printing all types:  ******************************")
print (all_types_set)

if (no_visitor == False):
  write_accept_definitions(all_types_set, cpp_file)

shutil.copy(orig_header_file_name, orig_header_file_name + ".bak")
orig_header_file = open(orig_header_file_name + ".bak", 'r')
enhanced_header_file = open(orig_header_file_name, 'w')

if (no_visitor == False):
  write_accept_declarations(namespace, orig_header_file, enhanced_header_file, root)
else:
  write_forward_declarations(namespace, orig_header_file, enhanced_header_file)

write_schema_traits (all_types_set, children_dict, parent_dict, meta_header_file)
write_descendant_pairs(children_dict, meta_header_file)

if (no_visitor == False):
  write_visitor(all_types_set, meta_header_file)

write_header_epilog(namespace, orig_header_without_ext, meta_header_file)
write_cpp_epilog(namespace, orig_header_without_ext, cpp_file)

orig_header_file.close()
enhanced_header_file.close()
meta_header_file.close()
cpp_file.close()


