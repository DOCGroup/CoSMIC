// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORTYPE_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORTYPE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorType_Impl;
  typedef ConnectorType_Impl * ConnectorType_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorType_Impl > ConnectorType;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorType_Impl
   *
   * Implementation for the ConnectorType model element.
   */
  class PICML_Export ConnectorType_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorType _create (const ConnectorImplementationContainer_in parent);
    ///@}

    // Default constructor.
    ConnectorType_Impl (void);

    // Initializing constructor.
    ConnectorType_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ConnectorType_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorImplementationContainer parent_ConnectorImplementationContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ConnectorImplements connection.
    size_t dst_of_ConnectorImplements (std::vector <ConnectorImplements> & items) const;
    bool has_dst_of_ConnectorImplements (void) const;
    ConnectorImplements dst_of_ConnectorImplements (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ConnectorObject_is_nil (void) const;
    ConnectorObject refers_to_ConnectorObject (void) const;
    void refers_to_ConnectorObject (ConnectorObject_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorType.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORIMPLEMENTATION_CONNECTORTYPE
