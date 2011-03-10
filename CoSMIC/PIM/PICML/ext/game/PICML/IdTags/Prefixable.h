// -*- C++ -*-

//============================================================================
/**
 * @file    Prefixable.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_IDTAGS_PREFIXABLE_H_
#define _PICML_IDTAGS_PREFIXABLE_H_

#include "game/mga/Model.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Prefixable_Impl;
  typedef Prefixable_Impl * Prefixable_in;
  typedef ::GAME::Mga::Smart_Ptr <Prefixable_Impl> Prefixable;

  class PICML_Export Prefixable_Impl :
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
    Prefixable_Impl (void);

    /// Initializing constructor
    Prefixable_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~Prefixable_Impl (void) = 0;

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of PrefixTag
    void PrefixTag (const std::string & val);

    /// Get the value of PrefixTag
    std::string PrefixTag (void) const;
    ///@}

    /**
     * @name Containment Methods
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
