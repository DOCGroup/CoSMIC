// -*- C++ -*-

//=============================================================================
/**
 * @file      Base_Class_Locator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_BASE_CLASS_LOCATOR_H_
#define _EXTENSION_CLASSES_BASE_CLASS_LOCATOR_H_

#include <set>
#include "game/mga/Atom.h"
#include "game/mga/Visitor.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Base_Class_Locator
 *
 * Visitor implementation that locates the base class for an element
 * type. This located base classes are stored by name. If the element
 * is not involved in Inheritance, then the default Mga type is stored
 * as the base class.
 */
  class Base_Class_Locator : public Visitor
{
public:
  Base_Class_Locator (std::set <Atom> & bc);

  /// Destructor.
  virtual ~Base_Class_Locator (void);

  virtual void visit_Atom (Atom_in a);

  virtual void visit_Connection (Connection_in c);

  virtual void visit_Reference (Reference_in ref);

private:
  /// Collection of located base classes.
  std::set <Atom> & bc_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_BASE_CLASS_LOCATOR_H_

