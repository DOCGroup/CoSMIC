// -*- C++ -*-

//============================================================================
/**
 * @file    Node.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_NODE_H_
#define _PICML_TARGETELEMENTS_NODE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Node_Impl;
  typedef Node_Impl * Node_in;
  typedef ::GAME::Mga::Smart_Ptr < Node_Impl > Node;

  // Forward decl.
  class Visitor;

  /**
   * @class Node_Impl
   *
   * Implementation for the Node model element.
   */
  class PICML_Export Node_Impl :
    public virtual ::GAME::Mga::Model_Impl
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
    static Node _create (const Domain_in parent);
    ///@}

    // Default constructor.
    Node_Impl (void);

    // Initializing constructor.
    Node_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Node_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;

    /// Set the value of operatingSystem
    void operatingSystem (const std::string & val);

    /// Get the value of operatingSystem
    std::string operatingSystem (void) const;

    /// Set the value of architecture
    void architecture (const std::string & val);

    /// Get the value of architecture
    std::string architecture (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src InterconnectConnection connection.
    size_t src_of_InterconnectConnection (std::vector <InterconnectConnection> & items) const;
    GAME::Mga::Collection_T <InterconnectConnection> src_of_InterconnectConnection (void) const;

    /// Get the src Shares connection.
    size_t src_of_Shares (std::vector <Shares> & items) const;
    GAME::Mga::Collection_T <Shares> src_of_Shares (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Resources (std::vector <Resource> & items) const;
    ::GAME::Mga::Collection_T <Resource> get_Resources (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Node.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_NODE
