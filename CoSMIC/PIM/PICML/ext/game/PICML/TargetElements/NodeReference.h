// -*- C++ -*-

//============================================================================
/**
 * @file    NodeReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_NODEREFERENCE_H_
#define _PICML_TARGETELEMENTS_NODEREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NodeReference_Impl;
  typedef NodeReference_Impl * NodeReference_in;
  typedef ::GAME::Mga::Smart_Ptr <NodeReference_Impl> NodeReference;

  // Forward decl.
  class Visitor;

  class PICML_Export NodeReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    NodeReference_Impl (void);

    /// Initializing constructor
    NodeReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~NodeReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
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
    Node refers_to_Node (void) const;
    ///@}
  };
}

#endif
