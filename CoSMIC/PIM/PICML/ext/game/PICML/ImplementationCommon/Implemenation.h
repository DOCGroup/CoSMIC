// -*- C++ -*-

//============================================================================
/**
 * @file    Implemenation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_IMPLEMENATION_H_
#define _PICML_IMPLEMENTATIONCOMMON_IMPLEMENATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Implemenation_Impl;
  typedef Implemenation_Impl * Implemenation_in;
  typedef ::GAME::Mga::Smart_Ptr < Implemenation_Impl > Implemenation;

  /**
   * @class Implemenation_Impl
   *
   * Implementation for the Implemenation model element.
   */
  class PICML_Export Implemenation_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    Implemenation_Impl (void);

    // Initializing constructor.
    Implemenation_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Implemenation_Impl (void) = 0;

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of UUID
    void UUID (const std::string & val);

    /// Get the value of UUID
    std::string UUID (void) const;

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ConfigProperty connection.
    size_t src_ConfigProperty (std::vector <ConfigProperty> & items) const;

    /// Get the src InfoProperty connection.
    size_t src_InfoProperty (std::vector <InfoProperty> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Implemenation.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_IMPLEMENATION
