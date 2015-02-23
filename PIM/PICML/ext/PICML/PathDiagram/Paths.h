// -*- C++ -*-

//============================================================================
/**
 * @file    Paths.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHS_H_
#define _PICML_PATHDIAGRAM_PATHS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Paths_Impl;
  typedef Paths_Impl * Paths_in;
  typedef ::GAME::Mga::Smart_Ptr < Paths_Impl > Paths;

  // Forward decl.
  class Visitor;

  /**
   * @class Paths_Impl
   *
   * Implementation for the Paths model element.
   */
  class PICML_Export Paths_Impl :
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
    static Paths _create (const PathDiagrams_in parent);
    ///@}

    // Default constructor.
    Paths_Impl (void);

    // Initializing constructor.
    Paths_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Paths_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    PathDiagrams parent_PathDiagrams (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_SimplePropertys (std::vector <SimpleProperty> & items) const;
    ::GAME::Mga::Collection_T <SimpleProperty> get_SimplePropertys (void) const;

    size_t get_ComplexPropertys (std::vector <ComplexProperty> & items) const;
    ::GAME::Mga::Collection_T <ComplexProperty> get_ComplexPropertys (void) const;

    size_t get_Paths (std::vector <Path> & items) const;
    ::GAME::Mga::Collection_T <Path> get_Paths (void) const;

    size_t get_PathPropertys (std::vector <PathProperty> & items) const;
    ::GAME::Mga::Collection_T <PathProperty> get_PathPropertys (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Paths.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATHS
