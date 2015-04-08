// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexTypeReference.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXTYPEREFERENCE_H_
#define _PICML_COMMON_COMPLEXTYPEREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexTypeReference_Impl;
  typedef ComplexTypeReference_Impl * ComplexTypeReference_in;
  typedef ::GAME::Mga::Smart_Ptr < ComplexTypeReference_Impl > ComplexTypeReference;

  // Forward decl.
  class Visitor;

  /**
   * @class ComplexTypeReference_Impl
   *
   * Implementation for the ComplexTypeReference model element.
   */
  class PICML_Export ComplexTypeReference_Impl :
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
    static ComplexTypeReference _create (const ComplexProperty_in parent);
    static ComplexTypeReference _create (const DataValueContainer_in parent);
    ///@}

    // Default constructor.
    ComplexTypeReference_Impl (void);

    // Initializing constructor.
    ComplexTypeReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComplexTypeReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComplexProperty parent_ComplexProperty (void);
    DataValueContainer parent_DataValueContainer (void);
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComplexType_is_nil (void) const;
    ComplexType refers_to_ComplexType (void) const;
    void refers_to_ComplexType (ComplexType_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComplexTypeReference.inl"
#endif

#endif  // !defined _PICML_COMMON_COMPLEXTYPEREFERENCE
