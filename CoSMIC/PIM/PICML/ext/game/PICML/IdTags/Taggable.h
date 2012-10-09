// -*- C++ -*-

//============================================================================
/**
 * @file    Taggable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IDTAGS_TAGGABLE_H_
#define _PICML_IDTAGS_TAGGABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Taggable_Impl;
  typedef Taggable_Impl * Taggable_in;
  typedef ::GAME::Mga::Smart_Ptr < Taggable_Impl > Taggable;

  /**
   * @class Taggable_Impl
   *
   * Implementation for the Taggable model element.
   */
  class PICML_Export Taggable_Impl :
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
    Taggable_Impl (void);

    // Initializing constructor.
    Taggable_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~Taggable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of VersionTag
    void VersionTag (const std::string & val);

    /// Get the value of VersionTag
    std::string VersionTag (void) const;

    /// Set the value of SpecifyIdTag
    void SpecifyIdTag (const std::string & val);

    /// Get the value of SpecifyIdTag
    std::string SpecifyIdTag (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Taggable.inl"
#endif

#endif  // !defined _PICML_IDTAGS_TAGGABLE
