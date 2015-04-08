// -*- C++ -*-

//============================================================================
/**
 * @file    CommonPortAttrs.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMMONPORTATTRS_H_
#define _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMMONPORTATTRS_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/FCO.h"

namespace PICML
{
  // Forward decl. and type definitions
  class CommonPortAttrs_Impl;
  typedef CommonPortAttrs_Impl * CommonPortAttrs_in;
  typedef ::GAME::Mga::Smart_Ptr < CommonPortAttrs_Impl > CommonPortAttrs;

  /**
   * @class CommonPortAttrs_Impl
   *
   * Implementation for the CommonPortAttrs model element.
   */
  class PICML_Export CommonPortAttrs_Impl :
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
    CommonPortAttrs_Impl (void);

    // Initializing constructor.
    CommonPortAttrs_Impl (IMgaFCO * ptr);

    // Destructor.
    virtual ~CommonPortAttrs_Impl (void) = 0;

    /**
     * @name Parent Methods
     */
    ///@{
    ///@}

    /**
     * @name Attribute Methods
     */
    ///@{

    /// Set the value of optional
    void optional (bool val);

    /// Get the value of optional
    bool optional (void) const;

    /// Set the value of exclusiveUser
    void exclusiveUser (bool val);

    /// Get the value of exclusiveUser
    bool exclusiveUser (void) const;

    /// Set the value of exclusiveProvider
    void exclusiveProvider (bool val);

    /// Get the value of exclusiveProvider
    bool exclusiveProvider (void) const;
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "CommonPortAttrs.inl"
#endif

#endif  // !defined _PICML_COMPONENTPARADIGMSHEETS_COMPONENTINTERFACE_COMMONPORTATTRS
