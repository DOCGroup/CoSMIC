// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithDeployRequirement.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_MONOLITHDEPLOYREQUIREMENT_H_
#define _PICML_IMPLEMENTATIONCOMMON_MONOLITHDEPLOYREQUIREMENT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithDeployRequirement_Impl;
  typedef MonolithDeployRequirement_Impl * MonolithDeployRequirement_in;
  typedef ::GAME::Mga::Smart_Ptr < MonolithDeployRequirement_Impl > MonolithDeployRequirement;

  // Forward decl.
  class Visitor;

  /**
   * @class MonolithDeployRequirement_Impl
   *
   * Implementation for the MonolithDeployRequirement model element.
   */
  class PICML_Export MonolithDeployRequirement_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static MonolithDeployRequirement _create (const ImplementationContainer_in parent);
    ///@}

    // Default constructor.
    MonolithDeployRequirement_Impl (void);

    // Initializing constructor.
    MonolithDeployRequirement_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MonolithDeployRequirement_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    MonolithicImplementationBase src_MonolithicImplementationBase (void) const;
    ImplementationRequirement dst_ImplementationRequirement (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MonolithDeployRequirement.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_MONOLITHDEPLOYREQUIREMENT
