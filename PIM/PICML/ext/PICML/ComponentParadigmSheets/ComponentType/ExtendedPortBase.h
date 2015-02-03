// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORTBASE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORTBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortBase_Impl;
  typedef ExtendedPortBase_Impl * ExtendedPortBase_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedPortBase_Impl > ExtendedPortBase;

  /**
   * @class ExtendedPortBase_Impl
   *
   * Implementation for the ExtendedPortBase model element.
   */
  class PICML_Export ExtendedPortBase_Impl :
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

    // Default constructor.
    ExtendedPortBase_Impl (void);

    // Initializing constructor.
    ExtendedPortBase_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ExtendedPortBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void);
    ConnectorObject parent_ConnectorObject (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool PortType_is_nil (void) const;
    PortType refers_to_PortType (void) const;
    void refers_to_PortType (PortType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedPortBase.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORTBASE
