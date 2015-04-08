// -*- C++ -*-

//============================================================================
/**
 * @file    MultiInputAction.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_MULTIINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_MULTIINPUTACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultiInputAction_Impl;
  typedef MultiInputAction_Impl * MultiInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr < MultiInputAction_Impl > MultiInputAction;

  // Forward decl.
  class Visitor;

  /**
   * @class MultiInputAction_Impl
   *
   * Implementation for the MultiInputAction model element.
   */
  class PICML_Export MultiInputAction_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual BehaviorInputAction_Impl
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

    /**
     * @name Factory Methods
     */
    ///@{
    static MultiInputAction _create (const BehaviorModel_in parent);
    ///@}

    // Default constructor.
    MultiInputAction_Impl (void);

    // Initializing constructor.
    MultiInputAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~MultiInputAction_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst MultiInput connection.
    size_t dst_of_MultiInput (std::vector <MultiInput> & items) const;
    bool has_dst_of_MultiInput (void) const;
    MultiInput dst_of_MultiInput (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MultiInputAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_MULTIINPUTACTION
