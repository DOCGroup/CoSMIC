// -*- C++ -*-

//============================================================================
/**
 * @file    Inheritable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_INHERITABLE_H_
#define _PICML_INHERITABLETYPES_INHERITABLE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Inheritable_Impl;
  typedef Inheritable_Impl * Inheritable_in;
  typedef ::GAME::Mga::Smart_Ptr <Inheritable_Impl> Inheritable;

  class PICML_Export Inheritable_Impl :
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
    Inheritable_Impl (void);

    /// Initializing constructor
    Inheritable_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Inheritable_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Inheritss (std::vector <Inherits> & items) const;
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
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
