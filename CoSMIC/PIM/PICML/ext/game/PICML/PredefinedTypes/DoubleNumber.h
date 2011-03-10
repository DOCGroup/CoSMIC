// -*- C++ -*-

//============================================================================
/**
 * @file    DoubleNumber.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PREDEFINEDTYPES_DOUBLENUMBER_H_
#define _PICML_PREDEFINEDTYPES_DOUBLENUMBER_H_

#include "game/mga/Atom.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class DoubleNumber_Impl;
  typedef DoubleNumber_Impl * DoubleNumber_in;
  typedef ::GAME::Mga::Smart_Ptr <DoubleNumber_Impl> DoubleNumber;

  // Forward decl.
  class Visitor;

  class PICML_Export DoubleNumber_Impl :
    public virtual FloatingPointType_Impl,
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    DoubleNumber_Impl (void);

    /// Initializing constructor
    DoubleNumber_Impl (IMgaAtom * ptr);

    /// Destructor
    virtual ~DoubleNumber_Impl (void);

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
    ///@}
  };
}

#endif
