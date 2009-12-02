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


try:
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
  for node in func_nodes:
    funcname = node.xpath("name/text()")[0]               # Find function name
    ret_type = get_return_type_from_function_node(node)   # Find function's return type
    funcname_ret_pair = (funcname, ret_type)              # Make a pair
    tuple_list.append(funcname_ret_pair);                 # Append the pair in the list

  function_dict[class_id] = tuple_list                    # Associate the list with the class_id

  bases = node.xpath("basecompoundref/text()")            # Obtain a list of bases
  baseclass_dict[class_id] = bases                        # Associate the list with the claas_id

# Both the dictionaries are populated at this point.

print ("Printing function dictionary: ")
for key, value in function_dict.iteritems():
  print (key, value)

print ("Printing baseclass dictionary: ")
for key, value in baseclass_dict.iteritems():
  print (key, value)


for key, value in function_dict.iteritems():
  typedef_nodes = root.xpath("compounddef[@id='" + key + "']//memberdef[@kind='typedef']")
  



