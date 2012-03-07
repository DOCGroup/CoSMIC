// -*- C++ -*-

//============================================================================
/**
 * @file    SharedResource.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_SHAREDRESOURCE_H_
#define _PICML_TARGETELEMENTS_SHAREDRESOURCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SharedResource_Impl;
  typedef SharedResource_Impl * SharedResource_in;
  typedef ::GAME::Mga::Smart_Ptr < SharedResource_Impl > SharedResource;

  // Forward decl.
  class Visitor;

  /**
   * @class SharedResource_Impl
   *
   * Implementation for the SharedResource model element.
   */
  class PICML_Export SharedResource_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static SharedResource _create (const Domain_in parent);
    ///@}

    // Default constructor.
    SharedResource_Impl (void);

    // Initializing constructor.
    SharedResource_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~SharedResource_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Shares connection.
    size_t dst_Shares (std::vector <Shares> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SharedResource.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_SHAREDRESOURCE
