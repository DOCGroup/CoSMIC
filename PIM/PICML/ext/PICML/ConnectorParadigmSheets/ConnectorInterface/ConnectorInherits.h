// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorInherits.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTORINHERITS_H_
#define _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTORINHERITS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorInherits_Impl;
  typedef ConnectorInherits_Impl * ConnectorInherits_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorInherits_Impl > ConnectorInherits;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorInherits_Impl
   *
   * Implementation for the ConnectorInherits model element.
   */
  class PICML_Export ConnectorInherits_Impl :
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
    static ConnectorInherits _create (const ConnectorObject_in parent);
    ///@}

    // Default constructor.
    ConnectorInherits_Impl (void);

    // Initializing constructor.
    ConnectorInherits_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ConnectorInherits_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorObject parent_ConnectorObject (void);
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
#include "ConnectorInherits.inl"
#endif

#endif  // !defined _PICML_CONNECTORPARADIGMSHEETS_CONNECTORINTERFACE_CONNECTORINHERITS
