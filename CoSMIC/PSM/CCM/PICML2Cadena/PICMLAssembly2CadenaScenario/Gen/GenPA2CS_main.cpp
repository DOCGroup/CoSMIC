#include "GenPA2CS.h"
#include "InputFileRegistry.h"

UDM_USE_DOM
UDM_USE_MGA

void usage()
{
	std::cout << "Usage:  RootRuleBlock.exe PICML_FileType=\"Models\\picml_instance_mmv20040505_7.mga\" CadenaScenario_FileType=\"Models\\exported.xml\"!\"udm\\cadena_scenario.xsd\"  or\n\tRootRuleBlock -d\n\n";
}

int main( int argc, char* argv[])
{
	InputFileRegistry ifr;
	ifr.registerFile( "PICML_FileType=\"Models\\picml_instance_mmv20040505_7.mga\"");
	ifr.registerFile( "CadenaScenario_FileType=\"Models\\exported.xml\"!\"udm\\cadena_scenario.xsd\" ");
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
		Udm::SmartDataNetwork sdncadena_scenario_29b( cadena_scenario::diagram);
		sdncadena_scenario_29b.CreateNew( ifr.getFileName( "CadenaScenario_FileType"), UseXSD()( ifr.getFileName( "CadenaScenario_FileType")) ? ifr.getXsdName( "CadenaScenario_FileType") : "cadena_scenario", cadena_scenario::Scenario::meta, Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_cadena_scenario_29c( ifr.getFileName( "CadenaScenario_FileType"), &sdncadena_scenario_29b);
		dnsvec.push_back( sdns_cadena_scenario_29c);
		// Open PICML_FileType r
		Udm::SmartDataNetwork sdnPICML_298( PICML::diagram);
		sdnPICML_298.OpenExisting( ifr.getFileName( "PICML_FileType"), UseXSD()( ifr.getFileName( "PICML_FileType")) ? ifr.getXsdName( "PICML_FileType") : "PICML", Udm::CHANGES_LOST_DEFAULT);
		Udm::StaticDataNetworkSpecifier sdns_PICML_299( ifr.getFileName( "PICML_FileType"), &sdnPICML_298);
		dnsvec.push_back( sdns_PICML_299);
		// Create the project
		Udm::StaticUdmProject prj( dnsvec, PICMLAssembly2CadenaScenario::diagram);
		Udm::DataNetwork& cadena_scenario_ref_29d= prj.GetDataNetwork( ifr.getFileName( "CadenaScenario_FileType"));
		Udm::DataNetwork& pICML_ref_29a= prj.GetDataNetwork( ifr.getFileName( "PICML_FileType"));
		Packets_t pICML_File_Ins_1;
		Packets_t cadena_File_Ins_3;
		// get objects from DNs
		PICML::RootFolder rootPICML_29e= PICML::RootFolder::Cast( pICML_ref_29a.GetRootObject());
		pICML_File_Ins_1.push_back( rootPICML_29e);
		cadena_scenario::Scenario rootcadena_scenario_29f= cadena_scenario::Scenario::Cast( cadena_scenario_ref_29d.GetRootObject());
		cadena_File_Ins_3.push_back( rootcadena_scenario_29f);
		// transformation
		RootRuleBlock_0 rootRuleBlock_0;
		rootRuleBlock_0( pICML_File_Ins_1, cadena_File_Ins_3);
		// Close the project
		prj.Close();
		// Close CadenaScenario_FileType w
		sdncadena_scenario_29b.CloseWithUpdate();
		// Close PICML_FileType r
		sdnPICML_298.CloseNoUpdate();
	}
	catch( udm_exception &e)
	{
		cout << e.what() << endl;
	}
	return 0;
}

