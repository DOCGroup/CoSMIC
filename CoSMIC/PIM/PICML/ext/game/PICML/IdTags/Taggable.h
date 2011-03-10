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

#include "game/mga/FCO.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Taggable_Impl;
  typedef Taggable_Impl * Taggable_in;
  typedef ::GAME::Mga::Smart_Ptr <Taggable_Impl> Taggable;

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

    /// Default constructor
    Taggable_Impl (void);

    /// Initializing constructor
    Taggable_Impl (IMgaFCO * ptr);

    /// Destructor
    virtual ~Taggable_Impl (void) = 0;

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

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
