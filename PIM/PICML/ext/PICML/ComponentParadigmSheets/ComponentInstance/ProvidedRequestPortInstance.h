// -*- C++ -*-

//============================================================================
/**
 * @file    ProvidedRequestPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PROVIDEDREQUESTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PROVIDEDREQUESTPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ProvidedRequestPortInstance_Impl;
  typedef ProvidedRequestPortInstance_Impl * ProvidedRequestPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < ProvidedRequestPortInstance_Impl > ProvidedRequestPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class ProvidedRequestPortInstance_Impl
   *
   * Implementation for the ProvidedRequestPortInstance model element.
   */
  class PICML_Export ProvidedRequestPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl,
    public virtual ProvidedRequestPortEnd_Impl
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
    static ProvidedRequestPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    ProvidedRequestPortInstance_Impl (void);

    // Initializing constructor.
    ProvidedRequestPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ProvidedRequestPortInstance_Impl (void);

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
    bool ProvidedRequestPort_is_nil (void) const;
    ProvidedRequestPort refers_to_ProvidedRequestPort (void) const;
    void refers_to_ProvidedRequestPort (ProvidedRequestPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ProvidedRequestPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_PROVIDEDREQUESTPORTINSTANCE
