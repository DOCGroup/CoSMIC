// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorPort.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MIRRORPORT_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MIRRORPORT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentType/ExtendedPortBase.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPort_Impl;
  typedef MirrorPort_Impl * MirrorPort_in;
  typedef ::GAME::Mga::Smart_Ptr < MirrorPort_Impl > MirrorPort;

  // Forward decl.
  class Visitor;

  /**
   * @class MirrorPort_Impl
   *
   * Implementation for the MirrorPort model element.
   */
  class PICML_Export MirrorPort_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual ExtendedPortBase_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static MirrorPort _create (const ConnectorObject_in parent);
    static MirrorPort _create (const Component_in parent);
    ///@}

    // Default constructor.
    MirrorPort_Impl (void);

    // Initializing constructor.
    MirrorPort_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~MirrorPort_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MirrorPort.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_MIRRORPORT
