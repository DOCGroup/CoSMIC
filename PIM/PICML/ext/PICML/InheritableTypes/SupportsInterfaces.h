// -*- C++ -*-

//============================================================================
/**
 * @file    SupportsInterfaces.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SUPPORTSINTERFACES_H_
#define _PICML_INHERITABLETYPES_SUPPORTSINTERFACES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SupportsInterfaces_Impl;
  typedef SupportsInterfaces_Impl * SupportsInterfaces_in;
  typedef ::GAME::Mga::Smart_Ptr < SupportsInterfaces_Impl > SupportsInterfaces;

  /**
   * @class SupportsInterfaces_Impl
   *
   * Implementation for the SupportsInterfaces model element.
   */
  class PICML_Export SupportsInterfaces_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;


    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    SupportsInterfaces_Impl (void);

    // Initializing constructor.
    SupportsInterfaces_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~SupportsInterfaces_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Supportss (std::vector <Supports> & items) const;
    ::GAME::Mga::Collection_T <Supports> get_Supportss (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "SupportsInterfaces.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_SUPPORTSINTERFACES
