// -*- C++ -*-

//============================================================================
/**
 * @file    Collection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_COLLECTION_H_
#define _PICML_NAMEDTYPES_COLLECTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/NamedTypes/NoInheritable.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Collection_Impl;
  typedef Collection_Impl * Collection_in;
  typedef ::GAME::Mga::Smart_Ptr < Collection_Impl > Collection;

  // Forward decl.
  class Visitor;

  /**
   * @class Collection_Impl
   *
   * Implementation for the Collection model element.
   */
  class PICML_Export Collection_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual NoInheritable_Impl
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
    static Collection _create (const ConnectorObject_in parent);
    static Collection _create (const HasOperations_in parent);
    ///@}

    // Default constructor.
    Collection_Impl (void);

    // Initializing constructor.
    Collection_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~Collection_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of bound
    void bound (const std::string & val);

    /// Get the value of bound
    std::string bound (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool MemberType_is_nil (void) const;
    MemberType get_MemberType (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Collection.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_COLLECTION
