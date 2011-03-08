// -*- C++ -*-

//=============================================================================
/**
 * @file      Connection_Point_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill <hillj at cs dot iupui dot edu>
 */
//=============================================================================

#ifndef _EXTENSION_CLASSES_CONNECTION_POINT_GENERATOR_H_
#define _EXTENSION_CLASSES_CONNECTION_POINT_GENERATOR_H_

#include <iosfwd>
#include "game/mga/Visitor.h"
#include "game/mga/FCO.h"

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
class Connection_Point_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       classname         Name of the class
   * @param[in]       header            Target header file
   * @param[in]       source            Target source file
   */
  Connection_Point_Generator (FCO_in fco,
                              const std::string & classname,
                              std::ofstream & header,
                              std::ofstream & source);

  /// Destructor.
  virtual ~Connection_Point_Generator (void);

  // Visit the HasAttribute connection.
  virtual void visit_Connection (Connection_in c);

  // Visit the Attribute atom.
  virtual void visit_Atom (Atom_in a);

private:
  void generate_connection_point (const std::string & rolename,
                                  const std::string & pt_type);

  /// The FCO under generation.
  FCO fco_;

  /// Name of the extension class.
  const std::string & classname_;

  /// The header file for the extension class.
  std::ofstream & header_;

  /// The source file for the extension class.
  std::ofstream & source_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_INCONNECTION_GENERATOR_H_
