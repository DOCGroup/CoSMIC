// -*- C++ -*-

//============================================================================
/**
 * @file    DisplayNode.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_DISPLAYNODE_H_
#define _PICML_PATHDIAGRAM_DISPLAYNODE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/PathDiagram/GraphVertex.h"
#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DisplayNode_Impl;
  typedef DisplayNode_Impl * DisplayNode_in;
  typedef ::GAME::Mga::Smart_Ptr < DisplayNode_Impl > DisplayNode;

  // Forward decl.
  class Visitor;

  /**
   * @class DisplayNode_Impl
   *
   * Implementation for the DisplayNode model element.
   */
  class PICML_Export DisplayNode_Impl :
    public virtual ::GAME::Mga::Atom_Impl,
    public virtual GraphVertex_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static DisplayNode _create (const Path_in parent);
    ///@}

    // Default constructor.
    DisplayNode_Impl (void);

    // Initializing constructor.
    DisplayNode_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~DisplayNode_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "DisplayNode.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_DISPLAYNODE
