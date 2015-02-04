// -*- C++ -*-

//============================================================================
/**
 * @file    MultiOutputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIOUTPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIOUTPUTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiOutputBase_Impl;
  typedef MultiOutputBase_Impl * MultiOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr < MultiOutputBase_Impl > MultiOutputBase;

  /**
   * @class MultiOutputBase_Impl
   *
   * Implementation for the MultiOutputBase model element.
   */
  class PICML_Export MultiOutputBase_Impl :
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
    MultiOutputBase_Impl (void);

    // Initializing constructor.
    MultiOutputBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~MultiOutputBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MultiOutputBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_MULTIOUTPUTBASE
