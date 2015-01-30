// -*- C++ -*-

//============================================================================
/**
 * @file    InfoProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_INFOPROPERTY_H_
#define _PICML_IMPLEMENTATIONCOMMON_INFOPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class InfoProperty_Impl;
  typedef InfoProperty_Impl * InfoProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < InfoProperty_Impl > InfoProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class InfoProperty_Impl
   *
   * Implementation for the InfoProperty model element.
   */
  class PICML_Export InfoProperty_Impl :
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
    static InfoProperty _create (const ImplementationContainer_in parent, Implemenation_in src, Property_in dst);
    ///@}

    // Default constructor.
    InfoProperty_Impl (void);

    // Initializing constructor.
    InfoProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~InfoProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void);
    ///@}
    Implemenation src_Implemenation (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "InfoProperty.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_INFOPROPERTY
