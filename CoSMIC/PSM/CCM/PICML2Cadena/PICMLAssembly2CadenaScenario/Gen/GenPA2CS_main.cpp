#include "GenPA2CS.h"
#include "InputFileRegistry.h"

UDM_USE_DOM
UDM_USE_MGA

void usage()
{
	std::cout << "Usage:  RootRuleBlock.exe PICML_FileType=\"Models\\RobotAssembly.mga\" CadenaScenario_FileType=\"Models\\exported.xml\"!\"udm\\cadena_scenario.xsd\"  PicmlCadenaExchange_FileType=\"Models\\dummy_embedded.xml\"!\"udm\\PICMLCadena_Xchange_embedded_EIProperties.xsd\"  or\n\tRootRuleBlock -d\n\n";
}

int main( int argc, char* argv[])
{
	InputFileRegistry ifr;
	ifr.registerFile( "PICML_FileType=\"Models\\RobotAssembly.mga\"");
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
		// Open CadenaScenario_FileType w
		Udm::SmartDataNetwork mem_cadena_scenario_5e5( cadena_scenario::diagram);
		mem_cadena_scenario_5e5.CreateNew( "cadena_scenario_5e6.mem", UseXSD()( ifr.getFileName( "CadenaScenario_FileType")) ? ifr.getXsdName( "CadenaScenario_FileType") : "cadena_scenario", cadena_scenario::Scenarios::meta, Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_cadena_scenario_5e8( "cadena_scenario_5e7.mem", &mem_cadena_scenario_5e5);
		dnsvec.push_back( sdns_cadena_scenario_5e8);
		// Open PICML_FileType rw
		Udm::SmartDataNetwork sdnPICML_5e2( PICML::diagram);
		sdnPICML_5e2.OpenExisting( ifr.getFileName( "PICML_FileType"), UseXSD()( ifr.getFileName( "PICML_FileType")) ? ifr.getXsdName( "PICML_FileType") : "PICML", Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_PICML_5e3( ifr.getFileName( "PICML_FileType"), &sdnPICML_5e2);
		dnsvec.push_back( sdns_PICML_5e3);
		// Open PicmlCadenaExchange_FileType w
		Udm::SmartDataNetwork mem_PICMLCadena_Xchange_embedded_EIProperties_5eb( PICMLCadena_Xchange_embedded_EIProperties::diagram);
		mem_PICMLCadena_Xchange_embedded_EIProperties_5eb.CreateNew( "PICMLCadena_Xchange_embedded_EIProperties_5ec.mem", UseXSD()( ifr.getFileName( "PicmlCadenaExchange_FileType")) ? ifr.getXsdName( "PicmlCadenaExchange_FileType") : "PICMLCadena_Xchange_embedded_EIProperties", PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta, Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_PICMLCadena_Xchange_embedded_EIProperties_5ee( "PICMLCadena_Xchange_embedded_EIProperties_5ed.mem", &mem_PICMLCadena_Xchange_embedded_EIProperties_5eb);
		dnsvec.push_back( sdns_PICMLCadena_Xchange_embedded_EIProperties_5ee);
		// Create the project
		Udm::StaticUdmProject prj( dnsvec, PICMLAssembly2CadenaScenario::diagram);
		Udm::DataNetwork& cadena_scenario_ref_5e9= prj.GetDataNetwork( "cadena_scenario_5e7.mem");
		Udm::DataNetwork& pICML_ref_5e4= prj.GetDataNetwork( ifr.getFileName( "PICML_FileType"));
		Udm::DataNetwork& pICMLCadena_Xchange_embedded_EIProperties_ref_5ef= prj.GetDataNetwork( "PICMLCadena_Xchange_embedded_EIProperties_5ed.mem");
		Packets_t cadena_File_Ins_1;
		Packets_t embedded_Dummy_File_Ins_3;
		Packets_t pICML_File_Ins_5;
		// get objects from DNs
		PICML::RootFolder rootPICML_5f1= PICML::RootFolder::Cast( pICML_ref_5e4.GetRootObject());
		pICML_File_Ins_5.push_back( rootPICML_5f1);
		cadena_scenario::Scenarios rootcadena_scenario_5f2= cadena_scenario::Scenarios::Cast( cadena_scenario_ref_5e9.GetRootObject());
		cadena_File_Ins_1.push_back( rootcadena_scenario_5f2);
		PICMLCadena_Xchange_embedded_EIProperties::RootContainer rootPICMLCadena_Xchange_embedded_EIProperties_5f3= PICMLCadena_Xchange_embedded_EIProperties::RootContainer::Cast( pICMLCadena_Xchange_embedded_EIProperties_ref_5ef.GetRootObject());
		embedded_Dummy_File_Ins_3.push_back( rootPICMLCadena_Xchange_embedded_EIProperties_5f3);
		// transformation
		RootRuleBlock_0 rootRuleBlock_0;
		rootRuleBlock_0( cadena_File_Ins_1, embedded_Dummy_File_Ins_3, pICML_File_Ins_5);
		// Close the project
		prj.Close();
		// Close CadenaScenario_FileType w
		Udm::SmartDataNetwork sdncadena_scenario_5ea( cadena_scenario::diagram);
		sdncadena_scenario_5ea.CreateNew( ifr.getFileName( "CadenaScenario_FileType"), UseXSD()( ifr.getFileName( "CadenaScenario_FileType")) ? ifr.getXsdName( "CadenaScenario_FileType") : "cadena_scenario", cadena_scenario::Scenarios::meta, Udm::CHANGES_LOST_DEFAULT);
		sdncadena_scenario_5ea= mem_cadena_scenario_5e5;
		sdncadena_scenario_5ea.CloseWithUpdate();
		// Close PICML_FileType rw
		sdnPICML_5e2.CloseWithUpdate();
		// Close PicmlCadenaExchange_FileType w
		Udm::SmartDataNetwork sdnPICMLCadena_Xchange_embedded_EIProperties_5f0( PICMLCadena_Xchange_embedded_EIProperties::diagram);
		sdnPICMLCadena_Xchange_embedded_EIProperties_5f0.CreateNew( ifr.getFileName( "PicmlCadenaExchange_FileType"), UseXSD()( ifr.getFileName( "PicmlCadenaExchange_FileType")) ? ifr.getXsdName( "PicmlCadenaExchange_FileType") : "PICMLCadena_Xchange_embedded_EIProperties", PICMLCadena_Xchange_embedded_EIProperties::RootContainer::meta, Udm::CHANGES_LOST_DEFAULT);
		sdnPICMLCadena_Xchange_embedded_EIProperties_5f0= mem_PICMLCadena_Xchange_embedded_EIProperties_5eb;
		sdnPICMLCadena_Xchange_embedded_EIProperties_5f0.CloseWithUpdate();
	}
	catch( udm_exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

