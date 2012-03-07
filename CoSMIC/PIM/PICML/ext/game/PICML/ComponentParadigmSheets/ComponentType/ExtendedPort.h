// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPort_Impl;
  typedef ExtendedPort_Impl * ExtendedPort_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedPort_Impl > ExtendedPort;

  // Forward decl.
  class Visitor;

  /**
   * @class ExtendedPort_Impl
   *
   * Implementation for the ExtendedPort model element.
   */
  class PICML_Export ExtendedPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual ExtendedPortBase_Impl
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
    static ExtendedPort _create (const ConnectorObject_in parent);
    static ExtendedPort _create (const Component_in parent);
    ///@}

    // Default constructor.
    ExtendedPort_Impl (void);

    // Initializing constructor.
    ExtendedPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ExtendedPort_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ExtendedPort_is_nil (void) const;
    ExtendedPort get_ExtendedPort (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORT
