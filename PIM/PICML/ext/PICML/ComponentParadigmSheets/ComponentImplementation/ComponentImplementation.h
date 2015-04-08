// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentImplementation.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATION_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ImplementationCommon/Implemenation.h"
#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentImplementation_Impl;
  typedef ComponentImplementation_Impl * ComponentImplementation_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentImplementation_Impl > ComponentImplementation;

  /**
   * @class ComponentImplementation_Impl
   *
   * Implementation for the ComponentImplementation model element.
   */
  class PICML_Export ComponentImplementation_Impl :
    public virtual ::GAME::Mga::FCO_Impl,
    public virtual Implemenation_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    ComponentImplementation_Impl (void);

    // Initializing constructor.
    ComponentImplementation_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ComponentImplementation_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src Implements connection.
    size_t src_of_Implements (std::vector <Implements> & items) const;
    bool has_src_of_Implements (void) const;
    Implements src_of_Implements (void) const;

    /// Get the src ImplementationCapability connection.
    size_t src_of_ImplementationCapability (std::vector <ImplementationCapability> & items) const;
    bool has_src_of_ImplementationCapability (void) const;
    ImplementationCapability src_of_ImplementationCapability (void) const;

    /// Get the src ImplementationDependsOn connection.
    size_t src_of_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const;
    GAME::Mga::Collection_T <ImplementationDependsOn> src_of_ImplementationDependsOn (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentImplementation.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_COMPONENTIMPLEMENTATION
