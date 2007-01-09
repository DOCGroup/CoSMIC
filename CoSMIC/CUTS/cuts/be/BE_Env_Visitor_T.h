#ifndef _CUTS_BE_ENV_VISITOR_H_
#define _CUTS_BE_ENV_VISITOR_H_

#include "PICML/PICML.h"

template <typename BE_STRATEGY>
class CUTS_BE_Env_Visitor_T : public PICML::Visitor
{
public:
  /// Initalizing constructor.
  CUTS_BE_Env_Visitor_T (BE_STRATEGY & traits);

  virtual ~CUTS_BE_Env_Visitor_T (void);

protected:
  void Visit_Environment (
    const PICML::Environment & env);

  void Visit_MultiInput (
    const PICML::MultiInput & input);

  void Visit_InputAction (
    const PICML::InputAction & input);

private:
  /// The traits for the visitor.
  BE_STRATEGY & traits_;
};

#include "BE_Env_Visitor_T.cpp"

#endif  // !defined _CUTS_BE_ENV_VISITOR_H_
