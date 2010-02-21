#!/usr/bin/python

try:
  import sys
  from datetime import datetime
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


def bench_lxml_xpath_direct(root): # Very slow but very fast if text() is removed.
  name_list = root.xpath("book/author/name/text()")
  print ("Size of list = " + str(len(name_list)))


def bench_lxml_xpath_loop(root): # Fast 
  name_list = root.xpath("book/author/name")
  result = []
  for n in name_list:
    result.append(n.text)

  print ("Size of list = " + str(len(name_list)))

def bench_lxml_getiterator(tree): # Very fast
  result = []
  for name in tree.getiterator("name"):
    result.append(name.text)
  print ("Size of list = " + str(len(result)))


def bench_lxml_findall(tree):  # Superfast
# While this is the fastest way among all that are presented here, it is 
# about 2 to 2.2 times slower compared to LEESA!
  result = []
  for name in tree.findall("//name"):
    result.append(name.text)
  print ("Size of list = " + str(len(result)))


if(len(sys.argv) < 2):
  print ("Please specify a XML file.")
  quit()

start = datetime.now()
schema_file = open("library.xsd")
schema = etree.XMLSchema(file=schema_file)
parser = etree.XMLParser(schema = schema)
data_file = open(sys.argv[1], 'r')
tree = etree.parse(data_file, parser)
root = tree.getroot()
data_file.close()
schema_file.close()
end = datetime.now()
delta = end-start
print "Parsing time = ", delta

start = datetime.now()
#bench_lxml_xpath_direct(root)
#bench_lxml_xpath_loop(root)
#bench_lxml_getiterator(tree)
bench_lxml_findall(tree)
end = datetime.now()
delta = end-start
print "Query time = ", delta


