// -*- C++ -*-

//============================================================================
/**
 * @file    ExternalResources.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_EXTERNALRESOURCES_H_
#define _PICML_COMPONENTBUILD_EXTERNALRESOURCES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ExternalResources_Impl;
  typedef ExternalResources_Impl * ExternalResources_in;
  typedef ::GAME::Mga::Smart_Ptr < ExternalResources_Impl > ExternalResources;

  // Forward decl.
  class Visitor;

  /**
   * @class ExternalResources_Impl
   *
   * Implementation for the ExternalResources model element.
   */
  class PICML_Export ExternalResources_Impl :
    public virtual ::GAME::Mga::Reference_Impl
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
    static ExternalResources _create (const Project_in parent);
    ///@}

    // Default constructor.
    ExternalResources_Impl (void);

    // Initializing constructor.
    ExternalResources_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ExternalResources_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Project parent_Project (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ExtResourceConn connection.
    size_t dst_ExtResourceConn (std::vector <ExtResourceConn> & items) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ImplementationArtifact_is_nil (void) const;
    ImplementationArtifact get_ImplementationArtifact (void) const;
    void set_ImplementationArtifact (ImplementationArtifact_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ExternalResources.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_EXTERNALRESOURCES
