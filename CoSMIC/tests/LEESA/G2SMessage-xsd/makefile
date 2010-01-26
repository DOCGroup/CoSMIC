root := $(XSD_ROOT)/examples

include $(root)/build/cxx/rules.make
include $(root)/build/xsd/tree-rules.make

override XSDFLAGS += --generate-polymorphic --generate-default-ctor --generate-ostream --generate-serialization --root-element-last --namespace-map http://www.gamingstandards.com/g2s/schemas/v1.0.3=G2Sv1_0_3
CXXFLAGS = -I $(COSMIC_ROOT)/Utils/LEESA/include -D LEESA_NO_VISITOR

SRCS = $(wildcard *.cxx)
OBJS = $(patsubst %.cxx,%.o,$(SRCS))

all:
	@echo "Enter 'make generate' then enter 'make driver'"

# Generate
#
generate: 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) xsd/*.xsd
	python $(COSMIC_ROOT)/Utils/LEESA/bin/gen-meta.py -no-doxygen -no-visitor g2sMessage.hxx
	@echo "Now enter 'make driver'"


generate-all-xml: 
	rm -f all.xml 
	$(XSD_ROOT)/bin/xsd cxx-tree $(XSDFLAGS) xsd/*.xsd
	doxygen
	xsltproc xml/combine.xslt xml/index.xml > all.xml
	rm -fr latex html xml

# Build.
#
driver: driver.cpp $(OBJS) 
	$(CXX) -lxerces-c -o $@ $^


%.o: %.cxx
	$(CXX) $(CXXFLAGS)  -c  $<


# Clean.
#
.PHONY: clean
clean:
	rm -f *.o g2s*.?xx driver *-meta* *.?xx.bak 
