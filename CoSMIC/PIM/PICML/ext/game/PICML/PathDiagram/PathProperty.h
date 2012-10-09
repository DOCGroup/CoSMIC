// -*- C++ -*-

//============================================================================
/**
 * @file    PathProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHPROPERTY_H_
#define _PICML_PATHDIAGRAM_PATHPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathProperty_Impl;
  typedef PathProperty_Impl * PathProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < PathProperty_Impl > PathProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class PathProperty_Impl
   *
   * Implementation for the PathProperty model element.
   */
  class PICML_Export PathProperty_Impl :
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
    static PathProperty _create (const Paths_in parent);
    ///@}

    // Default constructor.
    PathProperty_Impl (void);

    // Initializing constructor.
    PathProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~PathProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Paths parent_Paths (void);
    ///@}
    Path src_Path (void) const;
    Property dst_Property (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "PathProperty.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATHPROPERTY
