// $Id$ 

#ifndef BGML_VISITOR_H
#define BGML_VISITOR_H

#include "PICML.h"
#include <string>

class BGML_Visitor: public PICML::Visitor
{
public:
    BGML_Visitor (const std::string& outputPath);
    ~BGML_Visitor();
	
	// Visitor Operations
	void Visit_BenchmarkAnalysis (const PICML::BenchmarkAnalysis& model);
	
private:
    std::string outputPath_;
};

#endif // BGML_VISITOR_H