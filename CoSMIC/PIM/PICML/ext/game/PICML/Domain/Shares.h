// -*- C++ -*-

//============================================================================
/**
 * @file    Shares.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_DOMAIN_SHARES_H_
#define _PICML_DOMAIN_SHARES_H_

#include "game/mga/Connection.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Shares_Impl;
  typedef Shares_Impl * Shares_in;
  typedef ::GAME::Mga::Smart_Ptr <Shares_Impl> Shares;

  // Forward decl.
  class Visitor;

  class PICML_Export Shares_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    Shares_Impl (void);

    /// Initializing constructor
    Shares_Impl (IMgaConnection * ptr);

    /// Destructor
    virtual ~Shares_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    static Shares _create (const Domain_in parent);
    ///@}

    /// Get the src Node connection point.
    Node src_Node (void);

    /// Get the dst SharedResource connection point.
    SharedResource dst_SharedResource (void);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void) const;
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
