// -*- C++ -*-

//============================================================================
/**
 * @file    Supports.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SUPPORTS_H_
#define _PICML_INHERITABLETYPES_SUPPORTS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Supports_Impl;
  typedef Supports_Impl * Supports_in;
  typedef ::GAME::Mga::Smart_Ptr < Supports_Impl > Supports;

  // Forward decl.
  class Visitor;

  /**
   * @class Supports_Impl
   *
   * Implementation for the Supports model element.
   */
  class PICML_Export Supports_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Supports _create (const SupportsInterfaces_in parent);
    ///@}

    // Default constructor.
    Supports_Impl (void);

    // Initializing constructor.
    Supports_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Supports_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SupportsInterfaces parent_SupportsInterfaces (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Object_is_nil (void) const;
    Object refers_to_Object (void) const;
    void refers_to_Object (Object_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Supports.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_SUPPORTS
