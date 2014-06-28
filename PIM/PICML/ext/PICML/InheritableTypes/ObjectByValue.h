// -*- C++ -*-

//============================================================================
/**
 * @file    ObjectByValue.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_OBJECTBYVALUE_H_
#define _PICML_INHERITABLETYPES_OBJECTBYVALUE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/SupportsInterfaces.h"
#include "PICML/IdTags/Prefixable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ObjectByValue_Impl;
  typedef ObjectByValue_Impl * ObjectByValue_in;
  typedef ::GAME::Mga::Smart_Ptr < ObjectByValue_Impl > ObjectByValue;

  /**
   * @class ObjectByValue_Impl
   *
   * Implementation for the ObjectByValue model element.
   */
  class PICML_Export ObjectByValue_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual HasOperations_Impl,
    public virtual SupportsInterfaces_Impl,
    public virtual Prefixable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    ObjectByValue_Impl (void);

    // Initializing constructor.
    ObjectByValue_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~ObjectByValue_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of abstract
    void abstract (bool val);

    /// Get the value of abstract
    bool abstract (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Members (std::vector <Member> & items) const;
    ::GAME::Mga::Collection_T <Member> get_Members (void) const;

    size_t get_ArrayMembers (std::vector <ArrayMember> & items) const;
    ::GAME::Mga::Collection_T <ArrayMember> get_ArrayMembers (void) const;

    size_t get_MakeMemberPrivates (std::vector <MakeMemberPrivate> & items) const;
    ::GAME::Mga::Collection_T <MakeMemberPrivate> get_MakeMemberPrivates (void) const;

    size_t get_PrivateFlags (std::vector <PrivateFlag> & items) const;
    ::GAME::Mga::Collection_T <PrivateFlag> get_PrivateFlags (void) const;

    size_t get_FactoryOperations (std::vector <FactoryOperation> & items) const;
    ::GAME::Mga::Collection_T <FactoryOperation> get_FactoryOperations (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ObjectByValue.inl"
#endif

#endif  // !defined _PICML_INHERITABLETYPES_OBJECTBYVALUE
