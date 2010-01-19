root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --export-symbol LIBRARY_Export --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include -D LIBRARY_Export=  -D OPTIMIZED_CARRIER -D WITH_LEESA -O3
# CXXFLAGS = --std=c++0x -I $(COSMIC_ROOT)/Utils/LEESA/include -D LIBRARY_Export= -D OPTIMIZED_CARRIER -D WITH_LEESA -O3

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) library.xsd
	python $(COSMIC_ROOT)/Utils/LEESA/bin/gen-meta.py -xsd library.hxx
	@echo "Now enter 'make driver'"


# Build.
#
driver: driver.o library.o library-meta.o
driver1stage: driver1stage.o library.o library-meta.o

library.o: library.cxx library.hxx
library-meta.o: library-meta.cxx library-meta.hxx
driver.o: driver.cxx library.hxx library-meta.hxx
driver1stage.o: driver1stage.cxx library.hxx library-meta.hxx


# Test.
#
.PHONY: test
test: driver library.xml
	./driver library.xml


# Clean.
#
.PHONY: clean
clean:
	rm -f *.o library.?xx driver driver1stage *-meta* *.?xx.bak all.xml
