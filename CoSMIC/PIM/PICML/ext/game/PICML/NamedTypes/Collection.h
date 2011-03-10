// -*- C++ -*-

//============================================================================
/**
 * @file    Collection.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_COLLECTION_H_
#define _PICML_NAMEDTYPES_COLLECTION_H_

#include "game/mga/Reference.h"
#include "PICML/NamedTypes/NoInheritable.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Collection_Impl;
  typedef Collection_Impl * Collection_in;
  typedef ::GAME::Mga::Smart_Ptr <Collection_Impl> Collection;

  // Forward decl.
  class Visitor;

  class PICML_Export Collection_Impl :
    public virtual NoInheritable_Impl,
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
    Collection_Impl (void);

    /// Initializing constructor
    Collection_Impl (IMgaReference * ptr);

    /// Destructor
    virtual ~Collection_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of bound
    void bound (const std::string & val);

    /// Get the value of bound
    std::string bound (void) const;
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
    MemberType refers_to_MemberType (void) const;
    ///@}
  };
}

#endif
