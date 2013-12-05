// -*- C++ -*-

//============================================================================
/**
 * @file    OperationBase.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_OPERATIONBASE_H_
#define _PICML_OPERATIONTYPES_OPERATIONBASE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/IdTags/Taggable.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class OperationBase_Impl;
  typedef OperationBase_Impl * OperationBase_in;
  typedef ::GAME::Mga::Smart_Ptr < OperationBase_Impl > OperationBase;

  /**
   * @class OperationBase_Impl
   *
   * Implementation for the OperationBase model element.
   */
  class PICML_Export OperationBase_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual Taggable_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    OperationBase_Impl (void);

    // Initializing constructor.
    OperationBase_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~OperationBase_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    BenchmarkAnalysis parent_BenchmarkAnalysis (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_InParameters (std::vector <InParameter> & items) const;
    ::GAME::Mga::Iterator <InParameter> get_InParameters (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "OperationBase.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_OPERATIONBASE
