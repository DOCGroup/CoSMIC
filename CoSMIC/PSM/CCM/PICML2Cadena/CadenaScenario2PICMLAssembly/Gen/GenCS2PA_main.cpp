#include "GenCS2PA.h"
#include "InputFileRegistry.h"

UDM_USE_DOM
UDM_USE_MGA

void usage()
{
	std::cout << "Usage:  RootRuleBlock.exe PICML_FileType=\"Models\\TweakedRobotAssembly.mga\" CadenaScenario_FileType=\"Models\\exported.xml\"!\"udm\\cadena_scenario.xsd\"  PicmlCadenaExchange_FileType=\"Models\\dummy_embedded.xml\"!\"udm\\PICMLCadena_Xchange_embedded_EIProperties.xsd\"  or\n\tRootRuleBlock -d\n\n";
}

int main( int argc, char* argv[])
{
	InputFileRegistry ifr;
	ifr.registerFile( "PICML_FileType=\"Models\\TweakedRobotAssembly.mga\"");
	ifr.registerFile( "CadenaScenario_FileType=\"Models\\exported.xml\"!\"udm\\cadena_scenario.xsd\" ");
	ifr.registerFile( "PicmlCadenaExchange_FileType=\"Models\\dummy_embedded.xml\"!\"udm\\PICMLCadena_Xchange_embedded_EIProperties.xsd\" ");
	if( argc== 1)
	{
		usage( );
		return -1;
	}
	else
		if( ( argc== 2)&& ( std::string( argv[ 1])== "-d"))
			std::cout << "Executing with default arguments." << std::endl;
		else
			for( int i= 1; i<argc; ++i)
			{
				if( false== ifr.registerFile( argv[ i]))
					throw InputFileEx( std::string( "Invalid input file expression: ") + argv[ i]);
			}
	try
	{
		std::vector< Udm::StaticDataNetworkSpecifier> dnsvec;
		// Open CadenaScenario_FileType r
		Udm::SmartDataNetwork sdncadena_scenario_a0e( cadena_scenario::diagram);
		sdncadena_scenario_a0e.OpenExisting( ifr.getFileName( "CadenaScenario_FileType"), UseXSD()( ifr.getFileName( "CadenaScenario_FileType")) ? ifr.getXsdName( "CadenaScenario_FileType") : "cadena_scenario", Udm::CHANGES_LOST_DEFAULT);
		Udm::SmartDataNetwork mem_cadena_scenario_a0f( cadena_scenario::diagram);
		mem_cadena_scenario_a0f.CreateNew( "cadena_scenario_a10.mem", UseXSD()( ifr.getFileName( "CadenaScenario_FileType")) ? ifr.getXsdName( "CadenaScenario_FileType") : "cadena_scenario", cadena_scenario::Scenarios::meta, Udm::CHANGES_LOST_DEFAULT);
		mem_cadena_scenario_a0f= sdncadena_scenario_a0e;
		Udm::StaticDataNetworkSpecifier sdns_cadena_scenario_a12( "cadena_scenario_a11.mem", &mem_cadena_scenario_a0f);
		dnsvec.push_back( sdns_cadena_scenario_a12);
		// Open PICML_FileType rw
		Udm::SmartDataNetwork sdnPICML_a0b( PICML::diagram);
		sdnPICML_a0b.OpenExisting( ifr.getFileName( "PICML_FileType"), UseXSD()( ifr.getFileName( "PICML_FileType")) ? ifr.getXsdName( "PICML_FileType") : "PICML", Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_PICML_a0c( ifr.getFileName( "PICML_FileType"), &sdnPICML_a0b);
		dnsvec.push_back( sdns_PICML_a0c);
		// Open PicmlCadenaExchange_FileType w
		Udm::SmartDataNetwork mem_PICMLCadena_Xchange_embedded_EIProperties_a14( PICMLCadena_Xchange_embedded_EIProperties::diagram);
		mem_PICMLCadena_Xchange_embedded_EIProperties_a14.CreateNew( "PICMLCadena_Xchange_embedded_EIProperties_a15.mem", UseXSD()( ifr.getFileName( "PicmlCadenaExchange_FileType")) ? ifr.getXsdName( "PicmlCadenaExchange_FileType") : "PICMLCadena_Xchange_embedded_EIProperties", PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta, Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_PICMLCadena_Xchange_embedded_EIProperties_a17( "PICMLCadena_Xchange_embedded_EIProperties_a16.mem", &mem_PICMLCadena_Xchange_embedded_EIProperties_a14);
		dnsvec.push_back( sdns_PICMLCadena_Xchange_embedded_EIProperties_a17);
		// Create the project
		Udm::StaticUdmProject prj( dnsvec, PICMLAssembly2CadenaScenario::diagram);
		Udm::DataNetwork& cadena_scenario_ref_a13= prj.GetDataNetwork( "cadena_scenario_a11.mem");
		Udm::DataNetwork& pICML_ref_a0d= prj.GetDataNetwork( ifr.getFileName( "PICML_FileType"));
		Udm::DataNetwork& pICMLCadena_Xchange_embedded_EIProperties_ref_a18= prj.GetDataNetwork( "PICMLCadena_Xchange_embedded_EIProperties_a16.mem");
		Packets_t embedded_Dummy_File_Ins_1;
		Packets_t pICML_File_Ins_3;
		Packets_t cadena_File_Ins_5;
		// get objects from DNs
		PICML::RootFolder rootPICML_a1a= PICML::RootFolder::Cast( pICML_ref_a0d.GetRootObject());
		pICML_File_Ins_3.push_back( rootPICML_a1a);
		cadena_scenario::Scenarios rootcadena_scenario_a1b= cadena_scenario::Scenarios::Cast( cadena_scenario_ref_a13.GetRootObject());
		cadena_File_Ins_5.push_back( rootcadena_scenario_a1b);
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootPICMLCadena_Xchange_embedded_EIProperties_a1c= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( pICMLCadena_Xchange_embedded_EIProperties_ref_a18.GetRootObject());
		embedded_Dummy_File_Ins_1.push_back( rootPICMLCadena_Xchange_embedded_EIProperties_a1c);
		// transformation
		RootRuleBlock_0 rootRuleBlock_0;
		rootRuleBlock_0( embedded_Dummy_File_Ins_1, pICML_File_Ins_3, cadena_File_Ins_5);
		// Close the project
		prj.Close();
		// Close CadenaScenario_FileType r
		sdncadena_scenario_a0e.CloseNoUpdate();
		// Close PICML_FileType rw
		sdnPICML_a0b.CloseWithUpdate();
		// Close PicmlCadenaExchange_FileType w
		Udm::SmartDataNetwork sdnPICMLCadena_Xchange_embedded_EIProperties_a19( PICMLCadena_Xchange_embedded_EIProperties::diagram);
		sdnPICMLCadena_Xchange_embedded_EIProperties_a19.CreateNew( ifr.getFileName( "PicmlCadenaExchange_FileType"), UseXSD()( ifr.getFileName( "PicmlCadenaExchange_FileType")) ? ifr.getXsdName( "PicmlCadenaExchange_FileType") : "PICMLCadena_Xchange_embedded_EIProperties", PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta, Udm::CHANGES_LOST_DEFAULT);
		sdnPICMLCadena_Xchange_embedded_EIProperties_a19= mem_PICMLCadena_Xchange_embedded_EIProperties_a14;
		sdnPICMLCadena_Xchange_embedded_EIProperties_a19.CloseWithUpdate();
	}
	catch( udm_exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

