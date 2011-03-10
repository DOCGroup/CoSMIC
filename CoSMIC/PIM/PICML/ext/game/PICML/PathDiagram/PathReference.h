// -*- C++ -*-

//============================================================================
/**
 * @file    PathReference.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHREFERENCE_H_
#define _PICML_PATHDIAGRAM_PATHREFERENCE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathReference_Impl;
  typedef PathReference_Impl * PathReference_in;
  typedef ::GAME::Mga::Smart_Ptr <PathReference_Impl> PathReference;

  // Forward decl.
  class Visitor;

  class PICML_Export PathReference_Impl :
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
    PathReference_Impl (void);

    /// Initializing constructor
    PathReference_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~PathReference_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
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
    Path refers_to_Path (void) const;
    ///@}
  };
}

#endif
