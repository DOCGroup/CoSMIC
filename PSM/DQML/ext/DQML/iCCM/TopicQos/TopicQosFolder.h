// -*- C++ -*-

//============================================================================
/**
 * @file    TopicQosFolder.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_TOPICQOS_TOPICQOSFOLDER_H_
#define _DQML_ICCM_TOPICQOS_TOPICQOSFOLDER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Folder.h"

namespace DQML
{
  // Forward decl. and type definitions
  class TopicQosFolder_Impl;
  typedef TopicQosFolder_Impl * TopicQosFolder_in;
  typedef ::GAME::Mga::Smart_Ptr < TopicQosFolder_Impl > TopicQosFolder;

  // Forward decl.
  class Visitor;

  /**
   * @class TopicQosFolder_Impl
   *
   * Implementation for the TopicQosFolder model element.
   */
  class DQML_Export TopicQosFolder_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static TopicQosFolder _create (const iCCM_in parent);
    ///@}

    // Default constructor.
    TopicQosFolder_Impl (void);

    // Initializing constructor.
    TopicQosFolder_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~TopicQosFolder_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    iCCM parent_iCCM (void);
    ///@}

    /**
     * @name Folder Getters
     */
    ///@{

    size_t get_TopicQoss (std::vector <TopicQos> & items) const;

    ::GAME::Mga::Collection_T <TopicQos> get_TopicQoss (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopicQosFolder.inl"
#endif

#endif  // !defined _DQML_ICCM_TOPICQOS_TOPICQOSFOLDER
