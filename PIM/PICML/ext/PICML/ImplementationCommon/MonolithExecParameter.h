// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithExecParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_MONOLITHEXECPARAMETER_H_
#define _PICML_IMPLEMENTATIONCOMMON_MONOLITHEXECPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithExecParameter_Impl;
  typedef MonolithExecParameter_Impl * MonolithExecParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < MonolithExecParameter_Impl > MonolithExecParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class MonolithExecParameter_Impl
   *
   * Implementation for the MonolithExecParameter model element.
   */
  class PICML_Export MonolithExecParameter_Impl :
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
    static MonolithExecParameter _create (const ImplementationContainer_in parent, MonolithicImplementationBase_in src, Property_in dst);
    ///@}

    // Default constructor.
    MonolithExecParameter_Impl (void);

    // Initializing constructor.
    MonolithExecParameter_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MonolithExecParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void);
    ///@}
    MonolithicImplementationBase src_MonolithicImplementationBase (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MonolithExecParameter.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_MONOLITHEXECPARAMETER
