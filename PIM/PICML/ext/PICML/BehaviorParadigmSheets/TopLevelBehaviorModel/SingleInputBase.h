// -*- C++ -*-

//============================================================================
/**
 * @file    SingleInputBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEINPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEINPUTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SingleInputBase_Impl;
  typedef SingleInputBase_Impl * SingleInputBase_in;
  typedef ::GAME::Mga::Smart_Ptr < SingleInputBase_Impl > SingleInputBase;

  /**
   * @class SingleInputBase_Impl
   *
   * Implementation for the SingleInputBase model element.
   */
  class PICML_Export SingleInputBase_Impl :
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
    SingleInputBase_Impl (void);

    // Initializing constructor.
    SingleInputBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~SingleInputBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src Input connection.
    size_t src_of_Input (std::vector <Input> & items) const;
    GAME::Mga::Collection_T <Input> src_of_Input (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SingleInputBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEINPUTBASE
