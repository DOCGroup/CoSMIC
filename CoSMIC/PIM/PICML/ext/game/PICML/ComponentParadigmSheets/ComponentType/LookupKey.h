// -*- C++ -*-

//============================================================================
/**
 * @file    LookupKey.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEY_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTTYPE_LOOKUPKEY_H_

#include "game/mga/Reference.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class LookupKey_Impl;
  typedef LookupKey_Impl * LookupKey_in;
  typedef ::GAME::Mga::Smart_Ptr <LookupKey_Impl> LookupKey;

  // Forward decl.
  class Visitor;

  class PICML_Export LookupKey_Impl :
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
    LookupKey_Impl (void);

    /// Initializing constructor
    LookupKey_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~LookupKey_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static LookupKey _create (const ComponentFactory_in parent);
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentFactory parent_ComponentFactory (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    LookupKeyType refers_to_LookupKeyType (void) const;
    ///@}
  };
}

#endif
