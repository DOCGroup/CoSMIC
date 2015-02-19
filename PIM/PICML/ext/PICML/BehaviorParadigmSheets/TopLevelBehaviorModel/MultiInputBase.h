// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInputBase_Impl;
  typedef MultiInputBase_Impl * MultiInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr < MultiInputBase_Impl > MultiInputBase;

  /**
   * @class MultiInputBase_Impl
   *
   * Implementation for the MultiInputBase model element.
   */
  class PICML_Export MultiInputBase_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    MultiInputBase_Impl (void);

    // Initializing constructor.
    MultiInputBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~MultiInputBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src MultiInput connection.
    size_t src_of_MultiInput (std::vector <MultiInput> & items) const;
    bool has_src_of_MultiInput (void) const;
    MultiInput src_of_MultiInput (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MultiInputBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIINPUTBASE
