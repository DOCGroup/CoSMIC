// -*- C++ -*-

//============================================================================
/**
 * @file    PortType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORTTYPE_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_PORTTYPE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PortType_Impl;
  typedef PortType_Impl * PortType_in;
  typedef ::GAME::Mga::Smart_Ptr <PortType_Impl> PortType;

  // Forward decl.
  class Visitor;

  class PICML_Export PortType_Impl :
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
    PortType_Impl (void);

    /// Initializing constructor
    PortType_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~PortType_Impl (void);

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
    size_t get_ReadonlyAttributes (std::vector <ReadonlyAttribute> & items) const;
    size_t get_ObjectPorts (std::vector <ObjectPort> & items) const;
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
