// -*- C++ -*-

//============================================================================
/**
 * @file    Paths.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHS_H_
#define _PICML_PATHDIAGRAM_PATHS_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Paths_Impl;
  typedef Paths_Impl * Paths_in;
  typedef ::GAME::Mga::Smart_Ptr <Paths_Impl> Paths;

  // Forward decl.
  class Visitor;

  class PICML_Export Paths_Impl :
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
    Paths_Impl (void);

    /// Initializing constructor
    Paths_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Paths_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Paths _create (const PathDiagrams_in parent);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Propertys (std::vector <Property> & items) const;
    size_t get_Paths (std::vector <Path> & items) const;
    size_t get_PathPropertys (std::vector <PathProperty> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    PathDiagrams parent_PathDiagrams (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
