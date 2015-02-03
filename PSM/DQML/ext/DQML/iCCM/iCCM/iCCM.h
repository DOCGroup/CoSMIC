// -*- C++ -*-

//============================================================================
/**
 * @file    iCCM.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_ICCM_ICCM_H_
#define _DQML_ICCM_ICCM_ICCM_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "DQML/RootFolder.h"
#include "game/mga/Folder.h"

namespace DQML
{
  // Forward decl. and type definitions
  class iCCM_Impl;
  typedef iCCM_Impl * iCCM_in;
  typedef ::GAME::Mga::Smart_Ptr < iCCM_Impl > iCCM;

  // Forward decl.
  class Visitor;

  /**
   * @class iCCM_Impl
   *
   * Implementation for the iCCM model element.
   */
  class DQML_Export iCCM_Impl :
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
    static iCCM _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    iCCM_Impl (void);

    // Initializing constructor.
    iCCM_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~iCCM_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    RootFolder parent_RootFolder (void);
    ///@}

    /**
     * @name Folder Getters
     */
    ///@{

    size_t get_DomainQosFolders (std::vector <DomainQosFolder> & items) const;

    ::GAME::Mga::Collection_T <DomainQosFolder> get_DomainQosFolders (void) const;

    size_t get_TopicQosFolders (std::vector <TopicQosFolder> & items) const;

    ::GAME::Mga::Collection_T <TopicQosFolder> get_TopicQosFolders (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "iCCM.inl"
#endif

#endif  // !defined _DQML_ICCM_ICCM_ICCM
