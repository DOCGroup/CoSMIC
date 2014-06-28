// -*- C++ -*-

//============================================================================
/**
 * @file    BehaviorInputAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_BEHAVIORINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_BEHAVIORINPUTACTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class BehaviorInputAction_Impl;
  typedef BehaviorInputAction_Impl * BehaviorInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr < BehaviorInputAction_Impl > BehaviorInputAction;

  /**
   * @class BehaviorInputAction_Impl
   *
   * Implementation for the BehaviorInputAction model element.
   */
  class PICML_Export BehaviorInputAction_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    BehaviorInputAction_Impl (void);

    // Initializing constructor.
    BehaviorInputAction_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~BehaviorInputAction_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    BehaviorModel parent_BehaviorModel (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src InputEffect connection.
    size_t src_InputEffect (std::vector <InputEffect> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Finish connection.
    size_t dst_Finish (std::vector <Finish> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "BehaviorInputAction.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_BEHAVIORINPUTACTION
