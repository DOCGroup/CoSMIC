// -*- C++ -*-

//============================================================================
/**
 * @file    QoSPolicy.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_QOSPOLICY_H_
#define _DQML_STANDARD_QOSPOLICIES_QOSPOLICY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class QoSPolicy_Impl;
  typedef QoSPolicy_Impl * QoSPolicy_in;
  typedef ::GAME::Mga::Smart_Ptr < QoSPolicy_Impl > QoSPolicy;

  /**
   * @class QoSPolicy_Impl
   *
   * Implementation for the QoSPolicy model element.
   */
  class DQML_Export QoSPolicy_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    QoSPolicy_Impl (void);

    // Initializing constructor.
    QoSPolicy_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~QoSPolicy_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    DDSQoS parent_DDSQoS (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of name
    void name (const std::string & val);

    /// Get the value of name
    std::string name (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "QoSPolicy.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_QOSPOLICY
