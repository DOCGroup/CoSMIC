// -*- C++ -*-

//============================================================================
/**
 * @file    PathReference.h
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_PATHDIAGRAM_PATHREFERENCE_H_
#define _PICML_PATHDIAGRAM_PATHREFERENCE_H_

#include "PICML/PICML_fwd.h"
#include "PICML/PICML_export.h"

#include "game/mga/Reference.h"

namespace PICML
{
  // Forward decl. and type definitions
  class PathReference_Impl;
  typedef PathReference_Impl * PathReference_in;
  typedef ::GAME::Mga::Smart_Ptr < PathReference_Impl > PathReference;

  // Forward decl.
  class Visitor;

  /**
   * @class PathReference_Impl
   *
   * Implementation for the PathReference model element.
   */
  class PICML_Export PathReference_Impl :
    public virtual ::GAME::Mga::Reference_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::reference_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaReference interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Identifier if this class is an abstract type in GME
    static const bool is_abstract;

    /**
     * @name Factory Methods
     */
    ///@{
    static PathReference _create (const ComponentImplementationContainer_in parent);
    ///@}

    // Default constructor.
    PathReference_Impl (void);

    // Initializing constructor.
    PathReference_Impl (IMgaReference * ptr);

    // Destructor.
    virtual ~PathReference_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    /**
     * @name Parent Methods
     */
    ///@{
    ComponentImplementationContainer parent_ComponentImplementationContainer (void);
    ///@}

    /**
     * @name Destination Connection Point Methods
     */
    ///@{

    /// Get the dst CriticalPath connection.
    size_t dst_of_CriticalPath (std::vector <CriticalPath> & items) const;
    bool has_dst_of_CriticalPath (void) const;
    CriticalPath dst_of_CriticalPath (void) const;
    ///@}

    /**
     * @name Refers To Methods
     */
    ///@{
    bool Path_is_nil (void) const;
    Path refers_to_Path (void) const;
    void refers_to_Path (Path_in item);
    ///@}
  };
}

#if defined (__GAME_INLINE__)
#include "PathReference.inl"
#endif

#endif  // !defined _PICML_PATHDIAGRAM_PATHREFERENCE
