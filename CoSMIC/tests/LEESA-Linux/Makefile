CC=g++

all: UdmApp-SM.o UdmApp-PICML.o

UdmApp-SM.o: UdmApp-SM.cpp UdmConfig-SM.h UdmApp-SM.h SM_export.h SM.h
	$(CC) -c -I $(COSMIC_ROOT)/Utils/LEESA/include -I $(UDM_PATH)/include UdmApp-SM.cpp

UdmApp-PICML.o: UdmApp-PICML.cpp PICML_export.h PICML.h UdmApp-PICML.h UdmConfig-PICML.h
	$(CC) -c -I $(COSMIC_ROOT)/Utils/LEESA/include -I $(UDM_PATH)/include UdmApp-PICML.cpp

clean:
	rm -f UdmApp-SM.o UdmApp-PICML.o

