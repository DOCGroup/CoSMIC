// -*- C++ -*-

//============================================================================
/**
 * @file    HasExceptions.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_HASEXCEPTIONS_H_
#define _PICML_OPERATIONTYPES_HASEXCEPTIONS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "PICML/OperationTypes/OperationBase.h"
#include "game/mga/Model.h"

namespace PICML
{
  // Forward decl. and type definitions
  class HasExceptions_Impl;
  typedef HasExceptions_Impl * HasExceptions_in;
  typedef ::GAME::Mga::Smart_Ptr < HasExceptions_Impl > HasExceptions;

  /**
   * @class HasExceptions_Impl
   *
   * Implementation for the HasExceptions model element.
   */
  class PICML_Export HasExceptions_Impl :
    public virtual ::GAME::Mga::Model_Impl,
    public virtual OperationBase_Impl
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
    HasExceptions_Impl (void);

    // Initializing constructor.
    HasExceptions_Impl (IMgaModel * ptr);

    // Destructor.
    virtual ~HasExceptions_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_ExceptionRefs (std::vector <ExceptionRef> & items) const;
    ::GAME::Mga::Collection_T <ExceptionRef> get_ExceptionRefs (void) const;

    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "HasExceptions.inl"
#endif

#endif  // !defined _PICML_OPERATIONTYPES_HASEXCEPTIONS
