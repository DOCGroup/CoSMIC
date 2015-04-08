// -*- C++ -*-

//============================================================================
/**
 * @file    NativeValue.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_NATIVEVALUE_H_
#define _PICML_INTERFACEDEFINITION_NATIVEVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class NativeValue_Impl;
  typedef NativeValue_Impl * NativeValue_in;
  typedef ::GAME::Mga::Smart_Ptr < NativeValue_Impl > NativeValue;

  // Forward decl.
  class Visitor;

  /**
   * @class NativeValue_Impl
   *
   * Implementation for the NativeValue model element.
   */
  class PICML_Export NativeValue_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static NativeValue _create (const Package_in parent);
    static NativeValue _create (const File_in parent);
    ///@}

    // Default constructor.
    NativeValue_Impl (void);

    // Initializing constructor.
    NativeValue_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~NativeValue_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void);
    File parent_File (void);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "NativeValue.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_NATIVEVALUE
