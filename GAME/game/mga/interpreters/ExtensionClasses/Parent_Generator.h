// -*- C++ -*-

//=============================================================================
/**
 * @file      Parent_Generator.h
 *
 * $Id$
 *
 * @author    Alhad Mokashi <amokashi at iupui dot edu>
 *            James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_CONTAINMENT_GENERATOR_H_
#define _EXTENSION_CLASSES_CONTAINMENT_GENERATOR_H_

#include <fstream>
#include "game/mga/Visitor.h"

namespace GAME
{
namespace Mga
{

/**
 * @class InConnection_Generator
 *
 * Visitor that generates concrete in_connection methods for an
 * extension class.
 */
class Parent_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       classname         Name of the class
   * @param[in]       header            Target header file
   * @param[in]       source            Target source file
   */
  Parent_Generator (const std::string & classname,
                    std::ofstream & header,
                    std::ofstream & source);

  /// Destructor.
  virtual ~Parent_Generator (void);

  // Visit the HasAttribute connection.
  virtual void visit_Connection (Connection_in c);

  // Visit the Attribute atom.
  virtual void visit_Atom (Atom_in a);

private:
  /// Name of the extension class.
  const std::string & classname_;

  /// The header file for the extension class.
  std::ofstream & header_;

  /// The source file for the extension class.
  std::ofstream & source_;

  std::string cardinality_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_INCONNECTION_GENERATOR_H_
