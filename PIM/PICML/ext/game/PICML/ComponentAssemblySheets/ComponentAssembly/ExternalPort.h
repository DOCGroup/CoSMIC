// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_EXTERNALPORT_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_EXTERNALPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalPort_Impl;
  typedef ExternalPort_Impl * ExternalPort_in;
  typedef ::GAME::Mga::Smart_Ptr < ExternalPort_Impl > ExternalPort;

  // Forward decl.
  class Visitor;

  /**
   * @class ExternalPort_Impl
   *
   * Implementation for the ExternalPort model element.
   */
  class PICML_Export ExternalPort_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ExternalPort _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ExternalPort_Impl (void);

    // Initializing constructor.
    ExternalPort_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ExternalPort_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of location
    void location (const std::string & val);

    /// Get the value of location
    std::string location (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ExternalDelegate connection.
    size_t src_ExternalDelegate (std::vector <ExternalDelegate> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExternalPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_COMPONENTASSEMBLY_EXTERNALPORT
