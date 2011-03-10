// -*- C++ -*-

//============================================================================
/**
 * @file    TwowayOperation.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_OPERATIONTYPES_TWOWAYOPERATION_H_
#define _PICML_OPERATIONTYPES_TWOWAYOPERATION_H_

#include "game/mga/Model.h"
#include "PICML/OperationTypes/HasExceptions.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TwowayOperation_Impl;
  typedef TwowayOperation_Impl * TwowayOperation_in;
  typedef ::GAME::Mga::Smart_Ptr <TwowayOperation_Impl> TwowayOperation;

  // Forward decl.
  class Visitor;

  class PICML_Export TwowayOperation_Impl :
    public virtual HasExceptions_Impl,
    public virtual ::GAME::Mga::Model_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::model_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaModel interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor
    TwowayOperation_Impl (void);

    /// Initializing constructor
    TwowayOperation_Impl (IMgaModel * ptr);

    /// Destructor
    virtual ~TwowayOperation_Impl (void);

    /// Accept a visitor for this project.
    virtual void accept (Visitor * v);

    /**
     * @name Factory Methods
     */
    ///@{
    ///@}

    /**
     * @name Containment Methods
     */
    ///@{
    size_t get_OutParameters (std::vector <OutParameter> & items) const;

    ReturnType get_ReturnType (void) const;
    size_t get_InoutParameters (std::vector <InoutParameter> & items) const;
    ///@}

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Reference Methods
     */
    ///@{
    ///@}
  };
}

#endif
