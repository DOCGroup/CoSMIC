// -*- C++ -*-

//============================================================================
/**
 * @file    ImplementationDependency.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_IMPLEMENTATIONDEPENDENCY_H_
#define _PICML_COMMON_IMPLEMENTATIONDEPENDENCY_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ImplementationDependency_Impl;
  typedef ImplementationDependency_Impl * ImplementationDependency_in;
  typedef ::GAME::Mga::Smart_Ptr < ImplementationDependency_Impl > ImplementationDependency;

  // Forward decl.
  class Visitor;

  /**
   * @class ImplementationDependency_Impl
   *
   * Implementation for the ImplementationDependency model element.
   */
  class PICML_Export ImplementationDependency_Impl :
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
    static ImplementationDependency _create (const ComponentImplementationContainer_in parent);
    ///@}

    // Default constructor.
    ImplementationDependency_Impl (void);

    // Initializing constructor.
    ImplementationDependency_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ImplementationDependency_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of requiredType
    void requiredType (const std::string & val);

    /// Get the value of requiredType
    std::string requiredType (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst ImplementationDependsOn connection.
    size_t dst_of_ImplementationDependsOn (std::vector <ImplementationDependsOn> & items) const;
    GAME::Mga::Collection_T <ImplementationDependsOn> dst_of_ImplementationDependsOn (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ImplementationDependency.inl"
#endif

#endif  // !defined _PICML_COMMON_IMPLEMENTATIONDEPENDENCY
