// -*- C++ -*-

//============================================================================
/**
 * @file    DomainQosFolder.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ICCM_DOMAINQOS_DOMAINQOSFOLDER_H_
#define _DQML_ICCM_DOMAINQOS_DOMAINQOSFOLDER_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Folder.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DomainQosFolder_Impl;
  typedef DomainQosFolder_Impl * DomainQosFolder_in;
  typedef ::GAME::Mga::Smart_Ptr < DomainQosFolder_Impl > DomainQosFolder;

  // Forward decl.
  class Visitor;

  /**
   * @class DomainQosFolder_Impl
   *
   * Implementation for the DomainQosFolder model element.
   */
  class DQML_Export DomainQosFolder_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static DomainQosFolder _create (const iCCM_in parent);
    ///@}

    // Default constructor.
    DomainQosFolder_Impl (void);

    // Initializing constructor.
    DomainQosFolder_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~DomainQosFolder_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    iCCM parent_iCCM (void);
    ///@}

    size_t get_Domains (std::vector <Domain> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "DomainQosFolder.inl"
#endif

#endif  // !defined _DQML_ICCM_DOMAINQOS_DOMAINQOSFOLDER
