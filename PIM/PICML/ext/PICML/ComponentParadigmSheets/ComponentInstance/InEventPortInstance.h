// -*- C++ -*-

//============================================================================
/**
 * @file    InEventPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_INEVENTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_INEVENTPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InEventPortInstance_Impl;
  typedef InEventPortInstance_Impl * InEventPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < InEventPortInstance_Impl > InEventPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class InEventPortInstance_Impl
   *
   * Implementation for the InEventPortInstance model element.
   */
  class PICML_Export InEventPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual InEventPortEnd_Impl,
    public virtual PortInstance_Impl
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
    static InEventPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    InEventPortInstance_Impl (void);

    // Initializing constructor.
    InEventPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~InEventPortInstance_Impl (void);

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
    bool InEventPort_is_nil (void) const;
    InEventPort get_InEventPort (void) const;
    void set_InEventPort (InEventPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "InEventPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_INEVENTPORTINSTANCE
