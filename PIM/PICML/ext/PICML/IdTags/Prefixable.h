// -*- C++ -*-

//============================================================================
/**
 * @file    Prefixable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IDTAGS_PREFIXABLE_H_
#define _PICML_IDTAGS_PREFIXABLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Prefixable_Impl;
  typedef Prefixable_Impl * Prefixable_in;
  typedef ::GAME::Mga::Smart_Ptr < Prefixable_Impl > Prefixable;

  /**
   * @class Prefixable_Impl
   *
   * Implementation for the Prefixable model element.
   */
  class PICML_Export Prefixable_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    Prefixable_Impl (void);

    // Initializing constructor.
    Prefixable_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Prefixable_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of PrefixTag
    void PrefixTag (const std::string & val);

    /// Get the value of PrefixTag
    std::string PrefixTag (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Prefixable.inl"
#endif

#endif  // !defined _PICML_IDTAGS_PREFIXABLE
