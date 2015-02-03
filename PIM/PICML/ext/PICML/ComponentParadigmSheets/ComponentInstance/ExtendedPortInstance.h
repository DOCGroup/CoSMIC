// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_EXTENDEDPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_EXTENDEDPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ExtendedPortInstanceBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortInstance_Impl;
  typedef ExtendedPortInstance_Impl * ExtendedPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < ExtendedPortInstance_Impl > ExtendedPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class ExtendedPortInstance_Impl
   *
   * Implementation for the ExtendedPortInstance model element.
   */
  class PICML_Export ExtendedPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl,
    public virtual ExtendedPortInstanceBase_Impl
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
    static ExtendedPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    ExtendedPortInstance_Impl (void);

    // Initializing constructor.
    ExtendedPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ExtendedPortInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ExtendedPort_is_nil (void) const;
    ExtendedPort refers_to_ExtendedPort (void) const;
    void refers_to_ExtendedPort (ExtendedPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExtendedPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_EXTENDEDPORTINSTANCE
