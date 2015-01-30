// -*- C++ -*-

//============================================================================
/**
 * @file    TopLevelPackage.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGE_H_
#define _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Atom.h"

namespace PICML
{
  // Forward decl. and type definitions
  class TopLevelPackage_Impl;
  typedef TopLevelPackage_Impl * TopLevelPackage_in;
  typedef ::GAME::Mga::Smart_Ptr < TopLevelPackage_Impl > TopLevelPackage;

  // Forward decl.
  class Visitor;

  /**
   * @class TopLevelPackage_Impl
   *
   * Implementation for the TopLevelPackage model element.
   */
  class PICML_Export TopLevelPackage_Impl :
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
    static TopLevelPackage _create (const TopLevelPackageContainer_in parent);
    ///@}

    // Default constructor.
    TopLevelPackage_Impl (void);

    // Initializing constructor.
    TopLevelPackage_Impl (IMgaAtom * ptr);

    // Destructor.
    virtual ~TopLevelPackage_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    TopLevelPackageContainer parent_TopLevelPackageContainer (void);
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src package connection.
    size_t src_of_package (std::vector <package> & items) const;
    GAME::Mga::Collection_T <package> src_of_package (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "TopLevelPackage.inl"
#endif

#endif  // !defined _PICML_TOPLEVELPACKAGEDESCRIPTION_TOPLEVELPACKAGE
