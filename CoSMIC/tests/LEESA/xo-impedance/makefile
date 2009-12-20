root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include 

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) impedance.xsd
	@echo "Now enter 'make driver'"


# Build.
#
driver: driver.o impedance.o 

impedance.o: impedance.cxx impedance.hxx
impedance-meta.o: impedance-meta.cxx 
driver.o: driver.cxx impedance.hxx 


# Test.
#
.PHONY: test
test: driver impedance.xml
	./driver impedance.xml


# Clean.
#
.PHONY: clean
clean:
	rm -f impedance.o impedance.?xx driver.o driver *-meta* *.?xx.bak all.xml
