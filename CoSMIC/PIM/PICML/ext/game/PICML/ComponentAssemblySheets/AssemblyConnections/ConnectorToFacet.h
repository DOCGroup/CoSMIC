// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorToFacet.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTOFACET_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTOFACET_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorToFacet_Impl;
  typedef ConnectorToFacet_Impl * ConnectorToFacet_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorToFacet_Impl > ConnectorToFacet;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorToFacet_Impl
   *
   * Implementation for the ConnectorToFacet model element.
   */
  class PICML_Export ConnectorToFacet_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorToFacet _create (const ComponentAssembly_in parent);
    ///@}

    // Default constructor.
    ConnectorToFacet_Impl (void);

    // Initializing constructor.
    ConnectorToFacet_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ConnectorToFacet_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InnerName
    void InnerName (const std::string & val);

    /// Get the value of InnerName
    std::string InnerName (void) const;
    ///@}
    ConnectorInstance src_ConnectorInstance (void) const;
    ProvidedRequestPortEnd dst_ProvidedRequestPortEnd (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorToFacet.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTOFACET
