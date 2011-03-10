// -*- C++ -*-

//============================================================================
/**
 * @file    QueryInputAction.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_QUERYINPUTACTION_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_ACTIONTYPES_QUERYINPUTACTION_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class QueryInputAction_Impl;
  typedef QueryInputAction_Impl * QueryInputAction_in;
  typedef ::GAME::Mga::Smart_Ptr <QueryInputAction_Impl> QueryInputAction;

  // Forward decl.
  class Visitor;

  class PICML_Export QueryInputAction_Impl :
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
    QueryInputAction_Impl (void);

    /// Initializing constructor
    QueryInputAction_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~QueryInputAction_Impl (void);

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
    size_t get_Propertys (std::vector <Property> & items) const;
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
