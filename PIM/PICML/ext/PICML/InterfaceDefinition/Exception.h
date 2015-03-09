// -*- C++ -*-

//============================================================================
/**
 * @file    Exception.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_EXCEPTION_H_
#define _PICML_INTERFACEDEFINITION_EXCEPTION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Taggable.h"
#include "PICML/InterfaceDefinition/TemplateParameterValueType.h"
#include "PICML/InterfaceDefinition/ExceptionType.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Exception_Impl;
  typedef Exception_Impl * Exception_in;
  typedef ::GAME::Mga::Smart_Ptr < Exception_Impl > Exception;

  // Forward decl.
  class Visitor;

  /**
   * @class Exception_Impl
   *
   * Implementation for the Exception model element.
   */
  class PICML_Export Exception_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Taggable_Impl,
    public virtual TemplateParameterValueType_Impl,
    public virtual ExceptionType_Impl
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

    /**
     * @name Factory Methods
     */
    ///@{
    static Exception _create (const Package_in parent);
    static Exception _create (const File_in parent);
    static Exception _create (const HasOperations_in parent);
    ///@}

    // Default constructor.
    Exception_Impl (void);

    // Initializing constructor.
    Exception_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Exception_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Package parent_Package (void);
    File parent_File (void);
    HasOperations parent_HasOperations (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Members (std::vector <Member> & items) const;
    ::GAME::Mga::Collection_T <Member> get_Members (void) const;

    size_t get_ArrayMembers (std::vector <ArrayMember> & items) const;
    ::GAME::Mga::Collection_T <ArrayMember> get_ArrayMembers (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Exception.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_EXCEPTION
