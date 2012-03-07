// -*- C++ -*-

//============================================================================
/**
 * @file    MirrorPortInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_MIRRORPORTINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_MIRRORPORTINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MirrorPortInstance_Impl;
  typedef MirrorPortInstance_Impl * MirrorPortInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < MirrorPortInstance_Impl > MirrorPortInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class MirrorPortInstance_Impl
   *
   * Implementation for the MirrorPortInstance model element.
   */
  class PICML_Export MirrorPortInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl
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
    static MirrorPortInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    MirrorPortInstance_Impl (void);

    // Initializing constructor.
    MirrorPortInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~MirrorPortInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MirrorPort_is_nil (void) const;
    MirrorPort get_MirrorPort (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "MirrorPortInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_MIRRORPORTINSTANCE
