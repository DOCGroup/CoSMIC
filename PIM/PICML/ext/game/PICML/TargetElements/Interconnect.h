// -*- C++ -*-

//============================================================================
/**
 * @file    Interconnect.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_INTERCONNECT_H_
#define _PICML_TARGETELEMENTS_INTERCONNECT_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Interconnect_Impl;
  typedef Interconnect_Impl * Interconnect_in;
  typedef ::GAME::Mga::Smart_Ptr < Interconnect_Impl > Interconnect;

  // Forward decl.
  class Visitor;

  /**
   * @class Interconnect_Impl
   *
   * Implementation for the Interconnect model element.
   */
  class PICML_Export Interconnect_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static Interconnect _create (const Domain_in parent);
    ///@}

    // Default constructor.
    Interconnect_Impl (void);

    // Initializing constructor.
    Interconnect_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Interconnect_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Domain parent_Domain (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of label
    void label (const std::string & val);

    /// Get the value of label
    std::string label (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src BridgeConnection connection.
    size_t src_BridgeConnection (std::vector <BridgeConnection> & items) const;
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst InterconnectConnection connection.
    size_t dst_InterconnectConnection (std::vector <InterconnectConnection> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Resources (std::vector <Resource> & items) const;
    ::GAME::Mga::Collection_T <Resource> get_Resources (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Interconnect.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_INTERCONNECT
