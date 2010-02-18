CC=g++
CXXFLAGS= -D LEESA_FOR_UDM -c -I $(COSMIC_ROOT)/Utils/LEESA/include -I $(UDM_PATH)/include -D WITHOUT_LEESA

start:
	@echo "Enter 'make generate' then 'make object'"

generate:
	cp SM-orig.h SM.h
	cp SM-orig.cpp SM.cpp
	cp PICML-orig.h PICML.h
	cp PICML-orig.cpp PICML.cpp
	perl $(COSMIC_ROOT)/Utils/LEESA/bin/gen-pairs.pl SM
	perl $(COSMIC_ROOT)/Utils/LEESA/bin/gen-pairs.pl PICML
	@echo "Now enter 'make object'"


object: UdmApp-SM.o UdmApp-PICML.o
UdmApp-SM.o: UdmApp-SM.cpp UdmConfig-SM.h UdmApp-SM.h SM_export.h SM.h
UdmApp-PICML.o: UdmApp-PICML.cpp PICML_export.h PICML.h UdmApp-PICML.h UdmConfig-PICML.h


.PHONY: clean
clean:
	rm -f UdmApp-SM.o UdmApp-PICML.o PICML.* SM.* 

