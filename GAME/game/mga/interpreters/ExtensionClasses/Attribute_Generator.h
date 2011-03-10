// -*- C++ -*-

//=============================================================================
/**
 * @file      Attribute_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_ATTRIBUTE_GENERATOR_H_
#define _EXTENSION_CLASSES_ATTRIBUTE_GENERATOR_H_

#include <fstream>
#include "game/mga/Visitor.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Attribute_Generator
 *
 * Visitor that generates the attributes for an extension class.
 */
class Attribute_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       classname         Name of the class
   * @param[in]       header            Target header file
   * @param[in]       source            Target source file
   */
  Attribute_Generator (const std::string & classname,
                       std::ofstream & header,
                       std::ofstream & source);

  /// Destructor.
  virtual ~Attribute_Generator (void);

  // Visit the HasAttribute connection.
  virtual void visit_Connection (Connection_in c);

  // Visit the Attribute atom.
  virtual void visit_Atom (Atom_in a);

  // Visit a Reference element.
  virtual void visit_Reference (Reference_in ref);

private:
  /// Name of the extension class.
  const std::string & classname_;

  /// The header file for the extension class.
  std::ofstream & header_;

  /// The source file for the extension class.
  std::ofstream & source_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_ATTRIBUTE_GENERATOR_H_
