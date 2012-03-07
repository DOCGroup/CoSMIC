// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentAnalyses.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBENCHMARK_COMPONENTANALYSES_H_
#define _PICML_COMPONENTBENCHMARK_COMPONENTANALYSES_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/RootFolder.h"
#include "game/mga/Folder.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentAnalyses_Impl;
  typedef ComponentAnalyses_Impl * ComponentAnalyses_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentAnalyses_Impl > ComponentAnalyses;

  // Forward decl.
  class Visitor;

  /**
   * @class ComponentAnalyses_Impl
   *
   * Implementation for the ComponentAnalyses model element.
   */
  class PICML_Export ComponentAnalyses_Impl :
    public virtual ::GAME::Mga::Folder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static ComponentAnalyses _create (const ::GAME::Mga::RootFolder_in parent);
    ///@}

    // Default constructor.
    ComponentAnalyses_Impl (void);

    // Initializing constructor.
    ComponentAnalyses_Impl (IMgaFolder * ptr);

    // Destructor.
    virtual ~ComponentAnalyses_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    size_t get_BenchmarkAnalysiss (std::vector <BenchmarkAnalysis> & items) const;
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentAnalyses.inl"
#endif

#endif  // !defined _PICML_COMPONENTBENCHMARK_COMPONENTANALYSES
