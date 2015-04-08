// -*- C++ -*-

//============================================================================
/**
 * @file    StringSeq_Item.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _DQML_STANDARD_QOSPOLICIES_STRINGSEQ_ITEM_H_
#define _DQML_STANDARD_QOSPOLICIES_STRINGSEQ_ITEM_H_

#include "DQML/DQML_fwd.h"
#include "DQML/DQML_export.h"

#include "game/mga/Atom.h"

namespace DQML
{
  // Forward decl. and type definitions
  class StringSeq_Item_Impl;
  typedef StringSeq_Item_Impl * StringSeq_Item_in;
  typedef ::GAME::Mga::Smart_Ptr < StringSeq_Item_Impl > StringSeq_Item;

  // Forward decl.
  class Visitor;

  /**
   * @class StringSeq_Item_Impl
   *
   * Implementation for the StringSeq_Item model element.
   */
  class DQML_Export StringSeq_Item_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static StringSeq_Item _create (const StringSeq_in parent);
    ///@}

    // Default constructor.
    StringSeq_Item_Impl (void);

    // Initializing constructor.
    StringSeq_Item_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~StringSeq_Item_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    StringSeq parent_StringSeq (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of value
    void value (const std::string & val);

    /// Get the value of value
    std::string value (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "StringSeq_Item.inl"
#endif

#endif  // !defined _DQML_STANDARD_QOSPOLICIES_STRINGSEQ_ITEM
