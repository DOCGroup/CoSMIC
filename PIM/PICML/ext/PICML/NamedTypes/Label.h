// -*- C++ -*-

//============================================================================
/**
 * @file    Label.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_NAMEDTYPES_LABEL_H_
#define _PICML_NAMEDTYPES_LABEL_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class Label_Impl;
  typedef Label_Impl * Label_in;
  typedef ::GAME::Mga::Smart_Ptr < Label_Impl > Label;

  // Forward decl.
  class Visitor;

  /**
   * @class Label_Impl
   *
   * Implementation for the Label model element.
   */
  class PICML_Export Label_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static Label _create (const SwitchedAggregate_in parent);
    ///@}

    // Default constructor.
    Label_Impl (void);

    // Initializing constructor.
    Label_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~Label_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    SwitchedAggregate parent_SwitchedAggregate (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst LabelConnection connection.
    size_t dst_of_LabelConnection (std::vector <LabelConnection> & items) const;
    GAME::Mga::Collection_T <LabelConnection> dst_of_LabelConnection (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "Label.inl"
#endif

#endif  // !defined _PICML_NAMEDTYPES_LABEL
