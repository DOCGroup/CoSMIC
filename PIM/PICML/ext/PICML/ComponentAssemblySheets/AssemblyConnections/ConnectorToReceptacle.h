// -*- C++ -*-

//============================================================================
/**
 * @file    ConnectorToReceptacle.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTORECEPTACLE_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTORECEPTACLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ConnectorToReceptacle_Impl;
  typedef ConnectorToReceptacle_Impl * ConnectorToReceptacle_in;
  typedef ::GAME::Mga::Smart_Ptr < ConnectorToReceptacle_Impl > ConnectorToReceptacle;

  // Forward decl.
  class Visitor;

  /**
   * @class ConnectorToReceptacle_Impl
   *
   * Implementation for the ConnectorToReceptacle model element.
   */
  class PICML_Export ConnectorToReceptacle_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ConnectorToReceptacle _create (const ComponentAssembly_in parent, RequiredRequestPortEnd_in src, ConnectorInstance_in dst);
    ///@}

    // Default constructor.
    ConnectorToReceptacle_Impl (void);

    // Initializing constructor.
    ConnectorToReceptacle_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~ConnectorToReceptacle_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentAssembly parent_ComponentAssembly (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of InnerName
    void InnerName (const std::string & val);

    /// Get the value of InnerName
    std::string InnerName (void) const;
    ///@}
    RequiredRequestPortEnd src_RequiredRequestPortEnd (void) const;
    ConnectorInstance dst_ConnectorInstance (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ConnectorToReceptacle.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_CONNECTORTORECEPTACLE
