CC=g++
COPTS=-DLEESA_FOR_UDM -c -I $(COSMIC_ROOT)/Utils/LEESA/include -I $(UDM_PATH)/include

all: UdmApp-SM.o UdmApp-PICML.o

UdmApp-SM.o: UdmApp-SM.cpp UdmConfig-SM.h UdmApp-SM.h SM_export.h SM.h
	$(CC) $(COPTS) UdmApp-SM.cpp

UdmApp-PICML.o: UdmApp-PICML.cpp PICML_export.h PICML.h UdmApp-PICML.h UdmConfig-PICML.h
	$(CC) $(COPTS) UdmApp-PICML.cpp

clean:
	rm -f UdmApp-SM.o UdmApp-PICML.o

