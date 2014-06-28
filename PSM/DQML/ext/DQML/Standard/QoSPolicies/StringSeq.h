// -*- C++ -*-

//============================================================================
/**
 * @file    StringSeq.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_STRINGSEQ_H_
#define _DQML_STANDARD_QOSPOLICIES_STRINGSEQ_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class StringSeq_Impl;
  typedef StringSeq_Impl * StringSeq_in;
  typedef ::GAME::Mga::Smart_Ptr < StringSeq_Impl > StringSeq;

  // Forward decl.
  class Visitor;

  /**
   * @class StringSeq_Impl
   *
   * Implementation for the StringSeq model element.
   */
  class DQML_Export StringSeq_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static StringSeq _create (const SubscriptionKeyQosPolicy_in parent);
    static StringSeq _create (const PartitionQosPolicy_in parent);
    ///@}

    // Default constructor.
    StringSeq_Impl (void);

    // Initializing constructor.
    StringSeq_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~StringSeq_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SubscriptionKeyQosPolicy parent_SubscriptionKeyQosPolicy (void);
    PartitionQosPolicy parent_PartitionQosPolicy (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_StringSeq_Items (std::vector <StringSeq_Item> & items) const;
    ::GAME::Mga::Collection_T <StringSeq_Item> get_StringSeq_Items (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "StringSeq.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_STRINGSEQ
