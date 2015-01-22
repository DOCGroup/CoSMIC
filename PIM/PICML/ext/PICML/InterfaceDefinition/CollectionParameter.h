// -*- C++ -*-

//============================================================================
/**
 * @file    CollectionParameter.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_COLLECTIONPARAMETER_H_
#define _PICML_INTERFACEDEFINITION_COLLECTIONPARAMETER_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CollectionParameter_Impl;
  typedef CollectionParameter_Impl * CollectionParameter_in;
  typedef ::GAME::Mga::Smart_Ptr < CollectionParameter_Impl > CollectionParameter;

  // Forward decl.
  class Visitor;

  /**
   * @class CollectionParameter_Impl
   *
   * Implementation for the CollectionParameter model element.
   */
  class PICML_Export CollectionParameter_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual TemplateParameter_Impl
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
    static CollectionParameter _create (const Package_in parent);
    ///@}

    // Default constructor.
    CollectionParameter_Impl (void);

    // Initializing constructor.
    CollectionParameter_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~CollectionParameter_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool NameParameter_is_nil (void) const;
    NameParameter refers_to_NameParameter (void) const;
    void refers_to_NameParameter (NameParameter_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CollectionParameter.inl"
#endif

#endif  // !defined _PICML_INTERFACEDEFINITION_COLLECTIONPARAMETER
