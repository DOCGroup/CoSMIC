#ifndef _INTERPRETER_H_
#define _INTERPRETER_H_

#include "BON2Component.h"
#include <iostream>
#include <fstream>

class Pattern
{
public:
  virtual int create_init_file () = 0;
  virtual ~Pattern ();
};


class Pattern_Factory
{
public:
  Pattern_Factory (const BON::Project &project);
  Pattern *get_pattern (const BON::Model &model);
private:
  BON::Project project_;
};

#endif;