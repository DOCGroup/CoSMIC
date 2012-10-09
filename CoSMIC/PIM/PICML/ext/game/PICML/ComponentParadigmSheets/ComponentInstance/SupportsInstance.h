// -*- C++ -*-

//============================================================================
/**
 * @file    SupportsInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_SUPPORTSINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_SUPPORTSINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SupportsInstance_Impl;
  typedef SupportsInstance_Impl * SupportsInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < SupportsInstance_Impl > SupportsInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class SupportsInstance_Impl
   *
   * Implementation for the SupportsInstance model element.
   */
  class PICML_Export SupportsInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
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
    static SupportsInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    SupportsInstance_Impl (void);

    // Initializing constructor.
    SupportsInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~SupportsInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentInstance parent_ComponentInstance (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Supports_is_nil (void) const;
    Supports get_Supports (void) const;
    void set_Supports (Supports_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SupportsInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_SUPPORTSINSTANCE
