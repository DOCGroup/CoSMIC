// -*- C++ -*-

//============================================================================
/**
 * @file    ECRole.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_EVENTCHANNELREQUIREMENTS_ECROLE_H_
#define _PICML_EVENTCHANNELREQUIREMENTS_ECROLE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ECRole_Impl;
  typedef ECRole_Impl * ECRole_in;
  typedef ::GAME::Mga::Smart_Ptr < ECRole_Impl > ECRole;

  // Forward decl.
  class Visitor;

  /**
   * @class ECRole_Impl
   *
   * Implementation for the ECRole model element.
   */
  class PICML_Export ECRole_Impl :
    public virtual ::GAME::Mga::Atom_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::atom_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaAtom interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static ECRole _create (const ECRequirements_in parent);
    ///@}

    // Default constructor.
    ECRole_Impl (void);

    // Initializing constructor.
    ECRole_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~ECRole_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ECRequirements parent_ECRequirements (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of ECFilterType
    void ECFilterType (const std::string & val);

    /// Get the value of ECFilterType
    std::string ECFilterType (void) const;

    /// Set the value of rolekind
    void rolekind (const std::string & val);

    /// Get the value of rolekind
    std::string rolekind (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ECRole.inl"
#endif

#endif  // !defined _PICML_EVENTCHANNELREQUIREMENTS_ECROLE
