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

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NodeReference_Impl;
  typedef NodeReference_Impl * NodeReference_in;
  typedef ::GAME::Mga::Smart_Ptr < NodeReference_Impl > NodeReference;

  // Forward decl.
  class Visitor;

  /**
   * @class NodeReference_Impl
   *
   * Implementation for the NodeReference model element.
   */
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

    /**
     * @name Factory Methods
     */
    ///@{
    static NodeReference _create (const DeploymentPlan_in parent);
    ///@}

    // Default constructor.
    NodeReference_Impl (void);

    // Initializing constructor.
    NodeReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~NodeReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PropertyMapping connection.
    size_t src_PropertyMapping (std::vector <PropertyMapping> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst InstanceMapping connection.
    size_t dst_InstanceMapping (std::vector <InstanceMapping> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Node_is_nil (void) const;
    Node get_Node (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "NodeReference.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_NODEREFERENCE
