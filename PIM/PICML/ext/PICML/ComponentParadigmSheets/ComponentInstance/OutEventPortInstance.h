// -*- C++ -*-

//============================================================================
/**
 * @file    OutEventPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_OUTEVENTPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_OUTEVENTPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OutEventPortInstance_Impl;
  typedef OutEventPortInstance_Impl * OutEventPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < OutEventPortInstance_Impl > OutEventPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class OutEventPortInstance_Impl
   *
   * Implementation for the OutEventPortInstance model element.
   */
  class PICML_Export OutEventPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl,
    public virtual OutEventPortEnd_Impl
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
    static OutEventPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    OutEventPortInstance_Impl (void);

    // Initializing constructor.
    OutEventPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~OutEventPortInstance_Impl (void);

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
    bool OutEventPort_is_nil (void) const;
    OutEventPort refers_to_OutEventPort (void) const;
    void refers_to_OutEventPort (OutEventPort_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OutEventPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_OUTEVENTPORTINSTANCE
