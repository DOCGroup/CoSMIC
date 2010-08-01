// -*- C++ -*-

//=============================================================================
/**
 * @file      GME_ID_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_GME_ID_GENERATOR_H_
#define _GAME_GME_ID_GENERATOR_H_

#include "xercesc/dom/DOMDocument.hpp"
#include "Utils/xercesc/XercesString.h"
#include "ace/Thread_Mutex.h"
#include "game/config.h"

namespace GAME
{
namespace XME
{
/**
 * @class GME_ID_Generator
 *
 * Id generator for different model element types.
 */
class GME_ID_Generator
{
public:
  /// Default constructor.
  GME_ID_Generator (xercesc::DOMDocument * proj);

  /// Destructor.
  ~GME_ID_Generator (void);

  const ::Utils::XStr & generate_folder_id (void);
  const ::Utils::XStr & generate_atom_id (void);
  const ::Utils::XStr & generate_model_id (void);
  const ::Utils::XStr & generate_reference_id (void);
  const ::Utils::XStr & generate_connection_id (void);

private:
  struct typeinfo_t
  {
    typeinfo_t (void)
      : count_ (0) { }

    typeinfo_t (size_t count, const ::Utils::XStr & idstr)
      : count_ (count),
        idstr_ (idstr)
    {

    }

    /// Number of elements for the given type.
    XMLSize_t count_;

    /// The current id string for the type.
    ::Utils::XStr idstr_;

    ACE_Thread_Mutex lock_;
  };

  /// Helper method for initializing object.
  void init (xercesc::DOMDocument * proj);

  /// Helper method to initialize a type in the generator.
  static void init (xercesc::DOMDocument * proj,
                    const ::Utils::XStr & name,
                    typeinfo_t & type);

  /// Helper method for generating an id for a given type.
  static ::Utils::XStr & generate_id (typeinfo_t & type);

  /// Number of atoms.
  typeinfo_t atom_;

  /// Number of models.
  typeinfo_t model_;

  /// Number of folders.
  typeinfo_t folder_;

  /// Number of sets.
  typeinfo_t set_;

  /// Number of references.
  typeinfo_t ref_;

  /// Number of connections.
  typeinfo_t conn_;
};

}
}

#if defined (__GAME_INLINE__)
#include "GME_ID_Generator.inl"
#endif

#endif  // !defined _GAME_GME_ID_GENERATOR_H_
