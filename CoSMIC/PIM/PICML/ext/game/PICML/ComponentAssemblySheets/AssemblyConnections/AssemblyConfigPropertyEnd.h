// -*- C++ -*-

//============================================================================
/**
 * @file    AssemblyConfigPropertyEnd.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTYEND_H_
#define _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTYEND_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class AssemblyConfigPropertyEnd_Impl;
  typedef AssemblyConfigPropertyEnd_Impl * AssemblyConfigPropertyEnd_in;
  typedef ::GAME::Mga::Smart_Ptr < AssemblyConfigPropertyEnd_Impl > AssemblyConfigPropertyEnd;

  /**
   * @class AssemblyConfigPropertyEnd_Impl
   *
   * Implementation for the AssemblyConfigPropertyEnd model element.
   */
  class PICML_Export AssemblyConfigPropertyEnd_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    // Default constructor.
    AssemblyConfigPropertyEnd_Impl (void);

    // Initializing constructor.
    AssemblyConfigPropertyEnd_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~AssemblyConfigPropertyEnd_Impl (void) = 0;

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src AssemblyselectRequirement connection.
    size_t src_AssemblyselectRequirement (std::vector <AssemblyselectRequirement> & items) const;

    /// Get the src AssemblyConfigProperty connection.
    size_t src_AssemblyConfigProperty (std::vector <AssemblyConfigProperty> & items) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "AssemblyConfigPropertyEnd.inl"
#endif

#endif  // !defined _PICML_COMPONENTASSEMBLYSHEETS_ASSEMBLYCONNECTIONS_ASSEMBLYCONFIGPROPERTYEND
