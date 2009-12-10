root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --export-symbol POLY_Export --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include -D POLY_Export=

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) supermen.xsd
	python $(COSMIC_ROOT)/Utils/LEESA/bin/gen-meta.py -xsd supermen.hxx
	@echo "Now enter 'make driver'"


# Build.
#
driver: driver.o supermen.o supermen-meta.o

supermen.o: supermen.cxx supermen.hxx
supermen-meta.o: supermen-meta.cxx supermen-meta.hxx
driver.o: driver.cxx supermen.hxx supermen-meta.hxx


# Test.
#
.PHONY: test
test: driver supermen.xml
	./driver supermen.xml


# Clean.
#
.PHONY: clean
clean:
	rm -f supermen.o supermen.?xx driver.o driver *-meta* *.?xx.bak all.xml
