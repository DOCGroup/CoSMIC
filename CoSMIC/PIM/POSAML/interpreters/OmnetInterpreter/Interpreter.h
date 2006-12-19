#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "BON2Component.h"
#include <iostream>
#include <fstream>
//template <typename T> 
class Pattern
{
public:
 // typedef T TYPE;
  //Pattern (const BON::Project &project);
  virtual int create_init_file () = 0;
  //~Pattern ();
//private:
 // T *pattern_;
};


class Pattern_Factory
{
public:
  Pattern_Factory (const BON::Project &project);
  Pattern *get_pattern (const BON::Model &model);
private:
  BON::Project project_;
};


//#include "Interpreter.cpp"
#endif;