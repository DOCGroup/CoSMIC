root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --export-symbol RSS_Export --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include -D RSS_Export=

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) rss2.xsd
	python $(COSMIC_ROOT)/Utils/LEESA/bin/gen-meta.py -xsd rss2.hxx
	@echo "Now enter 'make driver'"


# Build.
#
driver: driver.o rss2.o rss2-meta.o

rss2.o: rss2.cxx rss2.hxx
rss2-meta.o: rss2-meta.cxx rss2-meta.hxx
driver.o: driver.cxx rss2.hxx rss2-meta.hxx


# Test.
#
.PHONY: test
test: driver rss2.xml
	./driver rss2.xml


# Clean.
#
.PHONY: clean
clean:
	rm -f *.o rss2.?xx driver *-meta* *.?xx.bak all.xml
