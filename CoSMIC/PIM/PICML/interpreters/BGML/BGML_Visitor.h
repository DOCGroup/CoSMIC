// $Id$ 

#ifndef BGML_VISITOR_H
#define BGML_VISITOR_H

#include "PICML.h"
#include <string>

#include "Global_Data.h"
#include "BGML_Export.h"

class BGML_Export BGML_Visitor: public PICML::Visitor
{
public:
    BGML_Visitor (std::string &outputPath);
    ~BGML_Visitor();
	
	// Visitor Operations
	void Visit_BenchmarkAnalysis (const PICML::BenchmarkAnalysis &model);
	void Visit_TimeProbe (const PICML::TimeProbe &probe);
private:
    void write_timer_information (std::string& file_name);

	BGML_Data bgml_state_;
	// BGML Data to hold the information
};

#endif // BGML_VISITOR_H