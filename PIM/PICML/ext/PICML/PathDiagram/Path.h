// -*- C++ -*-

//============================================================================
/**
 * @file    Path.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATH_H_
#define _PICML_PATHDIAGRAM_PATH_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Path_Impl;
  typedef Path_Impl * Path_in;
  typedef ::GAME::Mga::Smart_Ptr < Path_Impl > Path;

  // Forward decl.
  class Visitor;

  /**
   * @class Path_Impl
   *
   * Implementation for the Path model element.
   */
  class PICML_Export Path_Impl :
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static Path _create (const Paths_in parent);
    ///@}

    // Default constructor.
    Path_Impl (void);

    // Initializing constructor.
    Path_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Path_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Paths parent_Paths (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src PathProperty connection.
    size_t src_of_PathProperty (std::vector <PathProperty> & items) const;
    GAME::Mga::Collection_T <PathProperty> src_of_PathProperty (void) const;
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ComponentRefs (std::vector <ComponentRef> & items) const;
    ::GAME::Mga::Collection_T <ComponentRef> get_ComponentRefs (void) const;

    size_t get_RequiredRequestPorts (std::vector <RequiredRequestPort> & items) const;
    ::GAME::Mga::Collection_T <RequiredRequestPort> get_RequiredRequestPorts (void) const;

    size_t get_ProvidedRequestPorts (std::vector <ProvidedRequestPort> & items) const;
    ::GAME::Mga::Collection_T <ProvidedRequestPort> get_ProvidedRequestPorts (void) const;

    size_t get_InEventPorts (std::vector <InEventPort> & items) const;
    ::GAME::Mga::Collection_T <InEventPort> get_InEventPorts (void) const;

    size_t get_OutEventPorts (std::vector <OutEventPort> & items) const;
    ::GAME::Mga::Collection_T <OutEventPort> get_OutEventPorts (void) const;

    size_t get_DisplayNodes (std::vector <DisplayNode> & items) const;
    ::GAME::Mga::Collection_T <DisplayNode> get_DisplayNodes (void) const;

    size_t get_ConnectedComponents (std::vector <ConnectedComponent> & items) const;
    ::GAME::Mga::Collection_T <ConnectedComponent> get_ConnectedComponents (void) const;

    size_t get_Edges (std::vector <Edge> & items) const;
    ::GAME::Mga::Collection_T <Edge> get_Edges (void) const;

    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_SrcEdges (std::vector <SrcEdge> & items) const;
    ::GAME::Mga::Collection_T <SrcEdge> get_SrcEdges (void) const;

    size_t get_EdgePropertys (std::vector <EdgeProperty> & items) const;
    ::GAME::Mga::Collection_T <EdgeProperty> get_EdgePropertys (void) const;

    size_t get_DstEdges (std::vector <DstEdge> & items) const;
    ::GAME::Mga::Collection_T <DstEdge> get_DstEdges (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Path.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATH
