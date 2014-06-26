// -*- C++ -*-

//============================================================================
/**
 * @file    PublisherQos.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_PUBLISHERSUBSCRIBERQOS_PUBLISHERQOS_H_
#define _DQML_ICCM_PUBLISHERSUBSCRIBERQOS_PUBLISHERQOS_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class PublisherQos_Impl;
  typedef PublisherQos_Impl * PublisherQos_in;
  typedef ::GAME::Mga::Smart_Ptr < PublisherQos_Impl > PublisherQos;

  // Forward decl.
  class Visitor;

  /**
   * @class PublisherQos_Impl
   *
   * Implementation for the PublisherQos model element.
   */
  class DQML_Export PublisherQos_Impl :
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
    static PublisherQos _create (const Participant_in parent);
    ///@}

    // Default constructor.
    PublisherQos_Impl (void);

    // Initializing constructor.
    PublisherQos_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~PublisherQos_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Participant parent_Participant (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst PublisherConnection connection.
    size_t dst_PublisherConnection (std::vector <PublisherConnection> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_GroupDataQosPolicy (void) const;
    GroupDataQosPolicy get_GroupDataQosPolicy (void) const;

    bool has_PresentationQosPolicy (void) const;
    PresentationQosPolicy get_PresentationQosPolicy (void) const;

    bool has_EntityFactoryQosPolicy (void) const;
    EntityFactoryQosPolicy get_EntityFactoryQosPolicy (void) const;

    bool has_PartitionQosPolicy (void) const;
    PartitionQosPolicy get_PartitionQosPolicy (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PublisherQos.inl"
#endif

#endif  // !defined _DQML_ICCM_PUBLISHERSUBSCRIBERQOS_PUBLISHERQOS
