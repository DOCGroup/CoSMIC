// -*- C++ -*-

//============================================================================
/**
 * @file    SupportsInterfaces.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_INHERITABLETYPES_SUPPORTSINTERFACES_H_
#define _PICML_INHERITABLETYPES_SUPPORTSINTERFACES_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class SupportsInterfaces_Impl;
  typedef SupportsInterfaces_Impl * SupportsInterfaces_in;
  typedef ::GAME::Mga::Smart_Ptr <SupportsInterfaces_Impl> SupportsInterfaces;

  class PICML_Export SupportsInterfaces_Impl :
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
    SupportsInterfaces_Impl (void);

    /// Initializing constructor
    SupportsInterfaces_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~SupportsInterfaces_Impl (void) = 0;

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Supportss (std::vector <Supports> & items) const;
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
