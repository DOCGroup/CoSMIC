// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelBehavior.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_TOPLEVELBEHAVIOR_H_
#define _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_TOPLEVELBEHAVIOR_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelBehavior_Impl;
  typedef TopLevelBehavior_Impl * TopLevelBehavior_in;
  typedef ::GAME::Mga::Smart_Ptr < TopLevelBehavior_Impl > TopLevelBehavior;

  /**
   * @class TopLevelBehavior_Impl
   *
   * Implementation for the TopLevelBehavior model element.
   */
  class PICML_Export TopLevelBehavior_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual BehaviorModel_Impl
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

    // Default constructor.
    TopLevelBehavior_Impl (void);

    // Initializing constructor.
    TopLevelBehavior_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~TopLevelBehavior_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_Environment (void) const;
    Environment get_Environment (void) const;
    size_t get_MultiInputs (std::vector <MultiInput> & items) const;
    ::GAME::Mga::Collection_T <MultiInput> get_MultiInputs (void) const;

    size_t get_QueryInputs (std::vector <QueryInput> & items) const;
    ::GAME::Mga::Collection_T <QueryInput> get_QueryInputs (void) const;

    size_t get_WorkerTypes (std::vector <WorkerType> & items) const;
    ::GAME::Mga::Collection_T <WorkerType> get_WorkerTypes (void) const;

    size_t get_Inputs (std::vector <Input> & items) const;
    ::GAME::Mga::Collection_T <Input> get_Inputs (void) const;

    size_t get_ApplicationTasks (std::vector <ApplicationTask> & items) const;
    ::GAME::Mga::Collection_T <ApplicationTask> get_ApplicationTasks (void) const;

    size_t get_PeriodicEvents (std::vector <PeriodicEvent> & items) const;
    ::GAME::Mga::Collection_T <PeriodicEvent> get_PeriodicEvents (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopLevelBehavior.inl"
#endif

#endif  // !defined _PICML_BEHAVIORPARADIGMSHEETS_TOPLEVELBEHAVIORMODEL_TOPLEVELBEHAVIOR
