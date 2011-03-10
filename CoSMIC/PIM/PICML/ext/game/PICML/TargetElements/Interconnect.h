// -*- C++ -*-

//============================================================================
/**
 * @file    Interconnect.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_INTERCONNECT_H_
#define _PICML_TARGETELEMENTS_INTERCONNECT_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Interconnect_Impl;
  typedef Interconnect_Impl * Interconnect_in;
  typedef ::GAME::Mga::Smart_Ptr <Interconnect_Impl> Interconnect;

  // Forward decl.
  class Visitor;

  class PICML_Export Interconnect_Impl :
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
    Interconnect_Impl (void);

    /// Initializing constructor
    Interconnect_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Interconnect_Impl (void);

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
    size_t get_Resources (std::vector <Resource> & items) const;
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
