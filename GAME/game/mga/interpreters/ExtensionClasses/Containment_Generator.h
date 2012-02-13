// -*- C++ -*-

//=============================================================================
/**
 * @file      InConnection_Generator.h
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
#include <set>

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
class Containment_Generator : public Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       classname         Name of the class
   * @param[in]       header            Target header file
   * @param[in]       source            Target source file
   */
  Containment_Generator (FCO_in fco,
                         const std::string & classname,
                         std::ofstream & header,
                         std::ofstream & source);

  /// Destructor.
  virtual ~Containment_Generator (void);

  // Visit the HasAttribute connection.
  virtual void visit_Connection (Connection_in c);

  // Visit the Reference element.
  virtual void visit_Reference (Reference_in ref);

private:
  void generate_containment (FCO_in, const std::string & card);

  /// The parent extension class object for the generation.
  FCO fco_;

  /// Name of the extension class.
  const std::string & classname_;

  /// The header file for the extension class.
  std::ofstream & header_;

  /// The source file for the extension class.
  std::ofstream & source_;

  /// Collection of seen elements.
  std::set <std::string> seen_;
};

}
}

#endif  // !defined _EXTENSION_CLASSES_INCONNECTION_GENERATOR_H_
