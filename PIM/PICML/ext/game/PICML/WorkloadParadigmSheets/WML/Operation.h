// -*- C++ -*-

//============================================================================
/**
 * @file    Operation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_WORKLOADPARADIGMSHEETS_WML_OPERATION_H_
#define _PICML_WORKLOADPARADIGMSHEETS_WML_OPERATION_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Operation_Impl;
  typedef Operation_Impl * Operation_in;
  typedef ::GAME::Mga::Smart_Ptr < Operation_Impl > Operation;

  // Forward decl.
  class Visitor;

  /**
   * @class Operation_Impl
   *
   * Implementation for the Operation model element.
   */
  class PICML_Export Operation_Impl :
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
    static Operation _create (const Worker_in parent);
    ///@}

    // Default constructor.
    Operation_Impl (void);

    // Initializing constructor.
    Operation_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~Operation_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    Worker parent_Worker (void);
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{

    bool has_ReturnType (void) const;
    ReturnType get_ReturnType (void) const;
    size_t get_InParameters (std::vector <InParameter> & items) const;
    ::GAME::Mga::Collection_T <InParameter> get_InParameters (void) const;

    size_t get_InoutParameters (std::vector <InoutParameter> & items) const;
    ::GAME::Mga::Collection_T <InoutParameter> get_InoutParameters (void) const;

    size_t get_OutParameters (std::vector <OutParameter> & items) const;
    ::GAME::Mga::Collection_T <OutParameter> get_OutParameters (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Operation.inl"
#endif

#endif  // !defined _PICML_WORKLOADPARADIGMSHEETS_WML_OPERATION
