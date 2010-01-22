root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --export-symbol PICML_Export --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include -D PICML_Export=  -D WITH_LEESA_DESC -O3
# CXXFLAGS = --std=c++0x -I $(COSMIC_ROOT)/Utils/LEESA/include -D PICML_Export= -D WITH_LEESA -O3

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) PICML.xsd
	python $(COSMIC_ROOT)/Utils/LEESA/bin/gen-meta.py -doxygen PICML.hxx
	@echo "Now enter 'make driver'"


# Build.
#
driver: driver.o PICML.o PICML-meta.o

PICML.o: PICML.cxx PICML.hxx
PICML-meta.o: PICML-meta.cxx PICML-meta.hxx
driver.o: driver.cxx PICML.hxx PICML-meta.hxx


# Test.
#
.PHONY: test
test: driver PICML.xml
	./driver PICML.xml


# Clean.
#
.PHONY: clean
clean:
	rm -f *.o PICML.?xx driver *-meta* *.?xx.bak all.xml
