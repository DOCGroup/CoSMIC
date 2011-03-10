// -*- C++ -*-

//============================================================================
/**
 * @file    Bridge.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_BRIDGE_H_
#define _PICML_TARGETELEMENTS_BRIDGE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Bridge_Impl;
  typedef Bridge_Impl * Bridge_in;
  typedef ::GAME::Mga::Smart_Ptr <Bridge_Impl> Bridge;

  // Forward decl.
  class Visitor;

  class PICML_Export Bridge_Impl :
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
    Bridge_Impl (void);

    /// Initializing constructor
    Bridge_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Bridge_Impl (void);

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
