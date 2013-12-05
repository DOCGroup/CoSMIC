// -*- C++ -*-

//============================================================================
/**
 * @file    DomainEntity.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_DDSENTITIES_DOMAINENTITY_H_
#define _DQML_STANDARD_DDSENTITIES_DOMAINENTITY_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Model.h"

namespace DQML
{
  // Forward decl. and type definitions
  class DomainEntity_Impl;
  typedef DomainEntity_Impl * DomainEntity_in;
  typedef ::GAME::Mga::Smart_Ptr < DomainEntity_Impl > DomainEntity;

  /**
   * @class DomainEntity_Impl
   *
   * Implementation for the DomainEntity model element.
   */
  class DQML_Export DomainEntity_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    DomainEntity_Impl (void);

    // Initializing constructor.
    DomainEntity_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~DomainEntity_Impl (void) = 0;
  };
}

#if defined (__GAME_INLINE__)
#include "DomainEntity.inl"
#endif

#endif  // !defined _DQML_STANDARD_DDSENTITIES_DOMAINENTITY
