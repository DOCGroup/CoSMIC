/*
 * @file: main.cpp
 *
 * Configurator entry point
 * 
 * @author: Emre Turkay <emre.turkay@vanderbilt.edu>
 */

#include <qapplication.h>
#include "configuratordialog.h"

#include <qlistview.h>

#include "items.h"
#include "options.h"
#include "initialize_tree.i"

Rule* Option::rule_;

int main( int argc, char** argv )
{
	// Create root category
	Option_Category root("Root", "root element");
	// Create rule validator
	Rule rule(&root);
	Option::rule_ = &rule;
	// Initialize the root category
	initialize_option_tree(root);

	// Create QT interface
	QApplication app( argc, argv );
	ConfiguratorDialog dialog( &rule, 0, 0, TRUE);
	app.setMainWidget(&dialog);
	dialog.set_categories(&root);
	
	// QT main loop entrance
	dialog.exec();

	return 0;
}
