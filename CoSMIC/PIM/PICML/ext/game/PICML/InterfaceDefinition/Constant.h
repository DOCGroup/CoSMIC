// -*- C++ -*-

//============================================================================
/**
 * @file    Constant.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INTERFACEDEFINITION_CONSTANT_H_
#define _PICML_INTERFACEDEFINITION_CONSTANT_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Constant_Impl;
  typedef Constant_Impl * Constant_in;
  typedef ::GAME::Mga::Smart_Ptr <Constant_Impl> Constant;

  // Forward decl.
  class Visitor;

  class PICML_Export Constant_Impl :
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
    Constant_Impl (void);

    /// Initializing constructor
    Constant_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Constant_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Constant _create (const File_in parent);
    static Constant _create (const Package_in parent);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of value
    void value (const std::string & val);

    /// Get the value of value
    std::string value (void) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    File parent_File (void) const;
    Package parent_Package (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ConstantType refers_to_ConstantType (void) const;
    ///@}
  };
}

#endif
