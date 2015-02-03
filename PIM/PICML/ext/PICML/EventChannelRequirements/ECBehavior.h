// -*- C++ -*-

//============================================================================
/**
 * @file    ECBehavior.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_EVENTCHANNELREQUIREMENTS_ECBEHAVIOR_H_
#define _PICML_EVENTCHANNELREQUIREMENTS_ECBEHAVIOR_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ECBehavior_Impl;
  typedef ECBehavior_Impl * ECBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr < ECBehavior_Impl > ECBehavior;

  // Forward decl.
  class Visitor;

  /**
   * @class ECBehavior_Impl
   *
   * Implementation for the ECBehavior model element.
   */
  class PICML_Export ECBehavior_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ECBehavior _create (const ECRequirements_in parent);
    ///@}

    // Default constructor.
    ECBehavior_Impl (void);

    // Initializing constructor.
    ECBehavior_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ECBehavior_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ECRequirements parent_ECRequirements (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of DispatchingMultithreadingLevel
    void DispatchingMultithreadingLevel (long val);

    /// Get the value of DispatchingMultithreadingLevel
    long DispatchingMultithreadingLevel (void) const;

    /// Set the value of DisconnectDanglingConnections
    void DisconnectDanglingConnections (bool val);

    /// Get the value of DisconnectDanglingConnections
    bool DisconnectDanglingConnections (void) const;

    /// Set the value of SupplierBasedFiltering
    void SupplierBasedFiltering (bool val);

    /// Get the value of SupplierBasedFiltering
    bool SupplierBasedFiltering (void) const;

    /// Set the value of ConsumerBasedFiltering
    void ConsumerBasedFiltering (bool val);

    /// Get the value of ConsumerBasedFiltering
    bool ConsumerBasedFiltering (void) const;

    /// Set the value of MultithreadedConsumer
    void MultithreadedConsumer (bool val);

    /// Get the value of MultithreadedConsumer
    bool MultithreadedConsumer (void) const;

    /// Set the value of MultithreadedSupplier
    void MultithreadedSupplier (bool val);

    /// Get the value of MultithreadedSupplier
    bool MultithreadedSupplier (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ECBehavior.inl"
#endif

#endif  // !defined _PICML_EVENTCHANNELREQUIREMENTS_ECBEHAVIOR
