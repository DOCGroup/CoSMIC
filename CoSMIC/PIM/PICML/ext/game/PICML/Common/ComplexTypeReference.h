// -*- C++ -*-

//============================================================================
/**
 * @file    ComplexTypeReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMMON_COMPLEXTYPEREFERENCE_H_
#define _PICML_COMMON_COMPLEXTYPEREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComplexTypeReference_Impl;
  typedef ComplexTypeReference_Impl * ComplexTypeReference_in;
  typedef ::GAME::Mga::Smart_Ptr <ComplexTypeReference_Impl> ComplexTypeReference;

  // Forward decl.
  class Visitor;

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

    /// Default constructor
    ComplexTypeReference_Impl (void);

    /// Initializing constructor
    ComplexTypeReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ComplexTypeReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ComplexTypeReference _create (const ComplexProperty_in parent);
    static ComplexTypeReference _create (const DataValueContainer_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComplexProperty parent_ComplexProperty (void) const;
    DataValueContainer parent_DataValueContainer (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ComplexType refers_to_ComplexType (void) const;
    ///@}
  };
}

#endif
