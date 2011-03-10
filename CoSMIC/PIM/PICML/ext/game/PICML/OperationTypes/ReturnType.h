// -*- C++ -*-

//============================================================================
/**
 * @file    ReturnType.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_RETURNTYPE_H_
#define _PICML_OPERATIONTYPES_RETURNTYPE_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ReturnType_Impl;
  typedef ReturnType_Impl * ReturnType_in;
  typedef ::GAME::Mga::Smart_Ptr <ReturnType_Impl> ReturnType;

  // Forward decl.
  class Visitor;

  class PICML_Export ReturnType_Impl :
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
    ReturnType_Impl (void);

    /// Initializing constructor
    ReturnType_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~ReturnType_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static ReturnType _create (const TwowayOperation_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    TwowayOperation parent_TwowayOperation (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
