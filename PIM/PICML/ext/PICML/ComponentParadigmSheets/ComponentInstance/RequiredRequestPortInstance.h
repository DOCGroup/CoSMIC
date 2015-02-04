// -*- C++ -*-

//============================================================================
/**
 * @file    RequiredRequestPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_REQUIREDREQUESTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_REQUIREDREQUESTPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RequiredRequestPortInstance_Impl;
  typedef RequiredRequestPortInstance_Impl * RequiredRequestPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < RequiredRequestPortInstance_Impl > RequiredRequestPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class RequiredRequestPortInstance_Impl
   *
   * Implementation for the RequiredRequestPortInstance model element.
   */
  class PICML_Export RequiredRequestPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl,
    public virtual RequiredRequestPortEnd_Impl
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
    static RequiredRequestPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    RequiredRequestPortInstance_Impl (void);

    // Initializing constructor.
    RequiredRequestPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~RequiredRequestPortInstance_Impl (void);

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
    bool RequiredRequestPort_is_nil (void) const;
    RequiredRequestPort refers_to_RequiredRequestPort (void) const;
    void refers_to_RequiredRequestPort (RequiredRequestPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "RequiredRequestPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_REQUIREDREQUESTPORTINSTANCE
