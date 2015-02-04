// -*- C++ -*-

//============================================================================
/**
 * @file    ComponentLib.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTBUILD_COMPONENTLIB_H_
#define _PICML_COMPONENTBUILD_COMPONENTLIB_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class ComponentLib_Impl;
  typedef ComponentLib_Impl * ComponentLib_in;
  typedef ::GAME::Mga::Smart_Ptr < ComponentLib_Impl > ComponentLib;

  /**
   * @class ComponentLib_Impl
   *
   * Implementation for the ComponentLib model element.
   */
  class PICML_Export ComponentLib_Impl :
    public virtual ::GAME::Mga::FCO_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::fco_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFCO interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    // Default constructor.
    ComponentLib_Impl (void);

    // Initializing constructor.
    ComponentLib_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~ComponentLib_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    Project parent_Project (void);
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of libraryexport
    void libraryexport (const std::string & val);

    /// Get the value of libraryexport
    std::string libraryexport (void) const;

    /// Set the value of sharedname
    void sharedname (const std::string & val);

    /// Get the value of sharedname
    std::string sharedname (void) const;

    /// Set the value of ORBServices
    void ORBServices (const std::string & val);

    /// Get the value of ORBServices
    std::string ORBServices (void) const;
    ///@}

    /**
     * @name Source Connection Point Methods
     */
    ///@{

    /// Get the src ExtResourceConn connection.
    size_t src_of_ExtResourceConn (std::vector <ExtResourceConn> & items) const;
    GAME::Mga::Collection_T <ExtResourceConn> src_of_ExtResourceConn (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "ComponentLib.inl"
#endif

#endif  // !defined _PICML_COMPONENTBUILD_COMPONENTLIB
