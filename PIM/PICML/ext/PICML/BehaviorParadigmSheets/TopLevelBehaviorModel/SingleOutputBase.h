// -*- C++ -*-

//============================================================================
/**
 * @file    SingleOutputBase.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEOUTPUTBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEOUTPUTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SingleOutputBase_Impl;
  typedef SingleOutputBase_Impl * SingleOutputBase_in;
  typedef ::GAME::Mga::Smart_Ptr < SingleOutputBase_Impl > SingleOutputBase;

  /**
   * @class SingleOutputBase_Impl
   *
   * Implementation for the SingleOutputBase model element.
   */
  class PICML_Export SingleOutputBase_Impl :
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
    SingleOutputBase_Impl (void);

    // Initializing constructor.
    SingleOutputBase_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~SingleOutputBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SingleOutputBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_SINGLEOUTPUTBASE
