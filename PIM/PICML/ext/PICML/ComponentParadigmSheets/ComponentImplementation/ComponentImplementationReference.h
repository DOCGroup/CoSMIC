// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementationReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONREFERENCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementationReference_Impl;
  typedef ComponentImplementationReference_Impl * ComponentImplementationReference_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentImplementationReference_Impl > ComponentImplementationReference;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentImplementationReference_Impl
   *
   * Implementation for the ComponentImplementationReference model element.
   */
  class PICML_Export ComponentImplementationReference_Impl :
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
    static ComponentImplementationReference _create (const PackageContainer_in parent);
    ///@}

    // Default constructor.
    ComponentImplementationReference_Impl (void);

    // Initializing constructor.
    ComponentImplementationReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~ComponentImplementationReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PackageContainer parent_PackageContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst Implementation connection.
    size_t dst_of_Implementation (std::vector <Implementation> & items) const;
    GAME::Mga::Collection_T <Implementation> dst_of_Implementation (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ComponentImplementation_is_nil (void) const;
    ComponentImplementation refers_to_ComponentImplementation (void) const;
    void refers_to_ComponentImplementation (ComponentImplementation_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentImplementationReference.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATIONREFERENCE
