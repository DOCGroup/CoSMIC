// -*- C++ -*-

//============================================================================
/**
 * @file    Enum.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_ENUM_H_
#define _PICML_NAMEDTYPES_ENUM_H_

#include "game/mga/Model.h"
#include "PICML/NamedTypes/NoInheritable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Enum_Impl;
  typedef Enum_Impl * Enum_in;
  typedef ::GAME::Mga::Smart_Ptr <Enum_Impl> Enum;

  // Forward decl.
  class Visitor;

  class PICML_Export Enum_Impl :
    public virtual NoInheritable_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Enum_Impl (void);

    /// Initializing constructor
    Enum_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Enum_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_EnumValues (std::vector <EnumValue> & items) const;
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
