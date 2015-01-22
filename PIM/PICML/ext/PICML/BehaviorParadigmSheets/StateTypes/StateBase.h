// -*- C++ -*-

//============================================================================
/**
 * @file    StateBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATEBASE_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATEBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class StateBase_Impl;
  typedef StateBase_Impl * StateBase_in;
  typedef ::GAME::Mga::Smart_Ptr < StateBase_Impl > StateBase;

  /**
   * @class StateBase_Impl
   *
   * Implementation for the StateBase model element.
   */
  class PICML_Export StateBase_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    StateBase_Impl (void);

    // Initializing constructor.
    StateBase_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~StateBase_Impl (void) = 0;

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

    /// Get the src Finish connection.
    size_t src_of_Finish (std::vector <Finish> & items) const;
    GAME::Mga::Collection_T <Finish> src_of_Finish (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst TerminalEffect connection.
    size_t dst_of_TerminalEffect (std::vector <TerminalEffect> & items) const;
    GAME::Mga::Collection_T <TerminalEffect> dst_of_TerminalEffect (void) const;

    /// Get the dst InputEffect connection.
    size_t dst_of_InputEffect (std::vector <InputEffect> & items) const;
    GAME::Mga::Collection_T <InputEffect> dst_of_InputEffect (void) const;

    /// Get the dst Effect connection.
    size_t dst_of_Effect (std::vector <Effect> & items) const;
    GAME::Mga::Collection_T <Effect> dst_of_Effect (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "StateBase.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_STATETYPES_STATEBASE
