// -*- C++ -*-

//============================================================================
/**
 * @file    LookupKey.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupKey_Impl;
  typedef LookupKey_Impl * LookupKey_in;
  typedef ::GAME::Mga::Smart_Ptr < LookupKey_Impl > LookupKey;

  // Forward decl.
  class Visitor;

  /**
   * @class LookupKey_Impl
   *
   * Implementation for the LookupKey model element.
   */
  class PICML_Export LookupKey_Impl :
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
    static LookupKey _create (const ComponentFactory_in parent);
    ///@}

    // Default constructor.
    LookupKey_Impl (void);

    // Initializing constructor.
    LookupKey_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~LookupKey_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactory parent_ComponentFactory (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool LookupKeyType_is_nil (void) const;
    LookupKeyType refers_to_LookupKeyType (void) const;
    void refers_to_LookupKeyType (LookupKeyType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "LookupKey.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEY
