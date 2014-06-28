// -*- C++ -*-

//============================================================================
/**
 * @file    RootFolder.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_ROOTFOLDER_H_
#define _DQML_ROOTFOLDER_H_

#include "game/mga/RootFolder.h"

#include "DQML_fwd.h"
#include "DQML_export.h"

namespace DQML
{
  // Forward decl. and type definitions
  class RootFolder_Impl;
  typedef RootFolder_Impl * RootFolder_in;
  typedef ::GAME::Mga::Smart_Ptr < RootFolder_Impl > RootFolder;

  /**
   * @class RootFolder_Impl
   *
   * Implementation of the root folder model element.
   */
  class DQML_Export RootFolder_Impl : public virtual ::GAME::Mga::RootFolder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor.
    RootFolder_Impl (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       folder        The source folder interface.
     */
    RootFolder_Impl (IMgaFolder * folder);

    /// Destructor.
    virtual ~RootFolder_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    size_t get_iCCM (std::vector <iCCM> & items) const;
    ::GAME::Mga::Collection_T <iCCM> get_iCCM (void) const;

    size_t get_DDSQoS (std::vector <DDSQoS> & items) const;
    ::GAME::Mga::Collection_T <DDSQoS> get_DDSQoS (void) const;
  };
}

#endif
