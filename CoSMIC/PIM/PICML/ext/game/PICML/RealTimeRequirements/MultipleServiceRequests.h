// -*- C++ -*-

//============================================================================
/**
 * @file    MultipleServiceRequests.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_MULTIPLESERVICEREQUESTS_H_
#define _PICML_REALTIMEREQUIREMENTS_MULTIPLESERVICEREQUESTS_H_

#include "game/mga/Atom.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MultipleServiceRequests_Impl;
  typedef MultipleServiceRequests_Impl * MultipleServiceRequests_in;
  typedef ::GAME::Mga::Smart_Ptr <MultipleServiceRequests_Impl> MultipleServiceRequests;

  // Forward decl.
  class Visitor;

  class PICML_Export MultipleServiceRequests_Impl :
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
    MultipleServiceRequests_Impl (void);

    /// Initializing constructor
    MultipleServiceRequests_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~MultipleServiceRequests_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static MultipleServiceRequests _create (const ServiceProvider_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of minimum_simultaneous_service_level
    void minimum_simultaneous_service_level (long val);

    /// Get the value of minimum_simultaneous_service_level
    long minimum_simultaneous_service_level (void) const;

    /// Set the value of simultaneous_service_execution
    void simultaneous_service_execution (bool val);

    /// Get the value of simultaneous_service_execution
    bool simultaneous_service_execution (void) const;

    /// Set the value of buffer_service_requests
    void buffer_service_requests (bool val);

    /// Get the value of buffer_service_requests
    bool buffer_service_requests (void) const;

    /// Set the value of maximum_simultaneous_service_level
    void maximum_simultaneous_service_level (long val);

    /// Get the value of maximum_simultaneous_service_level
    long maximum_simultaneous_service_level (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ServiceProvider parent_ServiceProvider (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
