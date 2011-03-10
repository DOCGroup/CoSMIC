// -*- C++ -*-

//============================================================================
/**
 * @file    ExtendedPortBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORTBASE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_EXTENDEDPORTBASE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExtendedPortBase_Impl;
  typedef ExtendedPortBase_Impl * ExtendedPortBase_in;
  typedef ::GAME::Mga::Smart_Ptr <ExtendedPortBase_Impl> ExtendedPortBase;

  class PICML_Export ExtendedPortBase_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    ExtendedPortBase_Impl (void);

    /// Initializing constructor
    ExtendedPortBase_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ExtendedPortBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Component parent_Component (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    PortType refers_to_PortType (void) const;
    ///@}
  };
}

#endif
