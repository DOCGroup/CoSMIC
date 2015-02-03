// -*- C++ -*-

//============================================================================
/**
 * @file    AttributeInstance.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_ATTRIBUTEINSTANCE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_ATTRIBUTEINSTANCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/ComponentParadigmSheets/ComponentInstance/PortInstance.h"
#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AttributeInstance_Impl;
  typedef AttributeInstance_Impl * AttributeInstance_in;
  typedef ::GAME::Mga::Smart_Ptr < AttributeInstance_Impl > AttributeInstance;

  // Forward decl.
  class Visitor;

  /**
   * @class AttributeInstance_Impl
   *
   * Implementation for the AttributeInstance model element.
   */
  class PICML_Export AttributeInstance_Impl :
    public virtual ::GAME::Mga::Reference_Impl,
    public virtual PortInstance_Impl
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
    static AttributeInstance _create (const ConnectorInstance_in parent);
    static AttributeInstance _create (const ComponentInstance_in parent);
    ///@}

    // Default constructor.
    AttributeInstance_Impl (void);

    // Initializing constructor.
    AttributeInstance_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~AttributeInstance_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ConnectorInstance parent_ConnectorInstance (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src AttributeValue connection.
    size_t src_of_AttributeValue (std::vector <AttributeValue> & items) const;
    GAME::Mga::Collection_T <AttributeValue> src_of_AttributeValue (void) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst AttributeDelegate connection.
    size_t dst_of_AttributeDelegate (std::vector <AttributeDelegate> & items) const;
    GAME::Mga::Collection_T <AttributeDelegate> dst_of_AttributeDelegate (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool ReadonlyAttribute_is_nil (void) const;
    ReadonlyAttribute refers_to_ReadonlyAttribute (void) const;
    void refers_to_ReadonlyAttribute (ReadonlyAttribute_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "AttributeInstance.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINSTANCE_ATTRIBUTEINSTANCE
