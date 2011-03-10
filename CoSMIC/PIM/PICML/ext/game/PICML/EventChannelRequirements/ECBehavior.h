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

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ECBehavior_Impl;
  typedef ECBehavior_Impl * ECBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr <ECBehavior_Impl> ECBehavior;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    ECBehavior_Impl (void);

    /// Initializing constructor
    ECBehavior_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~ECBehavior_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ECBehavior _create (const ECRequirements_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of MultithreadedSupplier
    void MultithreadedSupplier (bool val);

    /// Get the value of MultithreadedSupplier
    bool MultithreadedSupplier (void) const;

    /// Set the value of DispatchingMultithreadingLevel
    void DispatchingMultithreadingLevel (long val);

    /// Get the value of DispatchingMultithreadingLevel
    long DispatchingMultithreadingLevel (void) const;

    /// Set the value of MultithreadedConsumer
    void MultithreadedConsumer (bool val);

    /// Get the value of MultithreadedConsumer
    bool MultithreadedConsumer (void) const;

    /// Set the value of DisconnectDanglingConnections
    void DisconnectDanglingConnections (bool val);

    /// Get the value of DisconnectDanglingConnections
    bool DisconnectDanglingConnections (void) const;

    /// Set the value of ConsumerBasedFiltering
    void ConsumerBasedFiltering (bool val);

    /// Get the value of ConsumerBasedFiltering
    bool ConsumerBasedFiltering (void) const;

    /// Set the value of SupplierBasedFiltering
    void SupplierBasedFiltering (bool val);

    /// Get the value of SupplierBasedFiltering
    bool SupplierBasedFiltering (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ECRequirements parent_ECRequirements (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
