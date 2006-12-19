#ifndef _PATTERNS_H_
#define _PATTERNS_H_

#include "BON2Component.h"
#include "Interpreter.h"
#include <iostream>
#include <fstream>

class Reactor:public Pattern
{
public: 
  Reactor (const BON::Project &, const BON::Model &);
  int create_init_file ();
private:
  BON::Project project_;
  BON::Model model_;
};

#endif