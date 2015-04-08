// -*- C++ -*-

//============================================================================
/**
 * @file    ServiceConsumer.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_REALTIMEREQUIREMENTS_SERVICECONSUMER_H_
#define _PICML_REALTIMEREQUIREMENTS_SERVICECONSUMER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ServiceConsumer_Impl;
  typedef ServiceConsumer_Impl * ServiceConsumer_in;
  typedef ::GAME::Mga::Smart_Ptr < ServiceConsumer_Impl > ServiceConsumer;

  // Forward decl.
  class Visitor;

  /**
   * @class ServiceConsumer_Impl
   *
   * Implementation for the ServiceConsumer model element.
   */
  class PICML_Export ServiceConsumer_Impl :
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
    static ServiceConsumer _create (const RTRequirements_in parent);
    ///@}

    // Default constructor.
    ServiceConsumer_Impl (void);

    // Initializing constructor.
    ServiceConsumer_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ServiceConsumer_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RTRequirements parent_RTRequirements (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of prioritize_service_invocations
    void prioritize_service_invocations (bool val);

    /// Get the value of prioritize_service_invocations
    bool prioritize_service_invocations (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ServiceConsumer.inl"
#endif

#endif  // !defined _PICML_REALTIMEREQUIREMENTS_SERVICECONSUMER
