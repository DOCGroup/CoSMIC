// -*- C++ -*-

//============================================================================
/**
 * @file    CriticalPath.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_CRITICALPATH_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_CRITICALPATH_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Connection.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CriticalPath_Impl;
  typedef CriticalPath_Impl * CriticalPath_in;
  typedef ::GAME::Mga::Smart_Ptr < CriticalPath_Impl > CriticalPath;

  // Forward decl.
  class Visitor;

  /**
   * @class CriticalPath_Impl
   *
   * Implementation for the CriticalPath model element.
   */
  class PICML_Export CriticalPath_Impl :
    public virtual ::GAME::Mga::Connection_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::connection_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaConnection interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /**
     * @name Factory Methods
     */
    ///@{
    static CriticalPath _create (const ComponentImplementationContainer_in parent);
    ///@}

    // Default constructor.
    CriticalPath_Impl (void);

    // Initializing constructor.
    CriticalPath_Impl (IMgaConnection * ptr);

    // Destructor.
    virtual ~CriticalPath_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);
    ComponentAssembly src_ComponentAssembly (void) const;
    PathReference dst_PathReference (void) const;
  };
}

#if defined (__GAME_INLINE__)
#include "CriticalPath.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTIMPLEMENTATION_CRITICALPATH
