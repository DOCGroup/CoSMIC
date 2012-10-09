// -*- C++ -*-

//============================================================================
/**
 * @file    Bridge.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TARGETELEMENTS_BRIDGE_H_
#define _PICML_TARGETELEMENTS_BRIDGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Bridge_Impl;
  typedef Bridge_Impl * Bridge_in;
  typedef ::GAME::Mga::Smart_Ptr < Bridge_Impl > Bridge;

  // Forward decl.
  class Visitor;

  /**
   * @class Bridge_Impl
   *
   * Implementation for the Bridge model element.
   */
  class PICML_Export Bridge_Impl :
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
    static Bridge _create (const Domain_in parent);
    ///@}

    // Default constructor.
    Bridge_Impl (void);

    // Initializing constructor.
    Bridge_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Bridge_Impl (void);

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
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst BridgeConnection connection.
    size_t dst_BridgeConnection (std::vector <BridgeConnection> & items) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_Resources (std::vector <Resource> & items) const;
    ::GAME::Mga::Iterator <Resource> get_Resources (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Bridge.inl"
#endif

#endif  // !defined _PICML_TARGETELEMENTS_BRIDGE
