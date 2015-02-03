// -*- C++ -*-

//============================================================================
/**
 * @file    MonolithprimaryArtifact.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IMPLEMENTATIONCOMMON_MONOLITHPRIMARYARTIFACT_H_
#define _PICML_IMPLEMENTATIONCOMMON_MONOLITHPRIMARYARTIFACT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class MonolithprimaryArtifact_Impl;
  typedef MonolithprimaryArtifact_Impl * MonolithprimaryArtifact_in;
  typedef ::GAME::Mga::Smart_Ptr < MonolithprimaryArtifact_Impl > MonolithprimaryArtifact;

  // Forward decl.
  class Visitor;

  /**
   * @class MonolithprimaryArtifact_Impl
   *
   * Implementation for the MonolithprimaryArtifact model element.
   */
  class PICML_Export MonolithprimaryArtifact_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static MonolithprimaryArtifact _create (const ImplementationContainer_in parent, MonolithicImplementationBase_in src, ImplementationArtifactReference_in dst);
    ///@}

    // Default constructor.
    MonolithprimaryArtifact_Impl (void);

    // Initializing constructor.
    MonolithprimaryArtifact_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~MonolithprimaryArtifact_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ImplementationContainer parent_ImplementationContainer (void);
    ///@}
    MonolithicImplementationBase src_MonolithicImplementationBase (void) const;
    ImplementationArtifactReference dst_ImplementationArtifactReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "MonolithprimaryArtifact.inl"
#endif

#endif  // !defined _PICML_IMPLEMENTATIONCOMMON_MONOLITHPRIMARYARTIFACT
