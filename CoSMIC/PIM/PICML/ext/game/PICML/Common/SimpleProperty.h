// -*- C++ -*-

//============================================================================
/**
 * @file    SimpleProperty.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_SIMPLEPROPERTY_H_
#define _PICML_COMMON_SIMPLEPROPERTY_H_

#include "game/mga/Reference.h"
#include "PICML/Common/Property.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SimpleProperty_Impl;
  typedef SimpleProperty_Impl * SimpleProperty_in;
  typedef ::GAME::Mga::Smart_Ptr <SimpleProperty_Impl> SimpleProperty;

  // Forward decl.
  class Visitor;

  class PICML_Export SimpleProperty_Impl :
    public virtual Property_Impl,
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    SimpleProperty_Impl (void);

    /// Initializing constructor
    SimpleProperty_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~SimpleProperty_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of Value
    void Value (const std::string & val);

    /// Get the value of Value
    std::string Value (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
