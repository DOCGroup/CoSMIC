// -*- C++ -*-

//============================================================================
/**
 * @file    EdgeProperty.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_EDGEPROPERTY_H_
#define _PICML_PATHDIAGRAM_EDGEPROPERTY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class EdgeProperty_Impl;
  typedef EdgeProperty_Impl * EdgeProperty_in;
  typedef ::GAME::Mga::Smart_Ptr < EdgeProperty_Impl > EdgeProperty;

  // Forward decl.
  class Visitor;

  /**
   * @class EdgeProperty_Impl
   *
   * Implementation for the EdgeProperty model element.
   */
  class PICML_Export EdgeProperty_Impl :
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
    static EdgeProperty _create (const Path_in parent, Property_in src, Edge_in dst);
    ///@}

    // Default constructor.
    EdgeProperty_Impl (void);

    // Initializing constructor.
    EdgeProperty_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~EdgeProperty_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Path parent_Path (void);
    ///@}
    Property src_Property (void) const;
    Edge dst_Edge (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "EdgeProperty.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_EDGEPROPERTY
