// -*- C++ -*-

//=============================================================================
/**
 * @file      GME_ID_Generator_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_GME_ID_GENERATOR_T_H_
#define _GAME_GME_ID_GENERATOR_T_H_

#include "Utils/xercesc/XercesString.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

namespace GAME
{
namespace XME
{
/**
 * @struct initial_id
 *
 * Trait class for the initial id of an element. This is used
 * to initialize the id in the id generator, and make sure the
 * correct number of bytes is allocated for future ids.
 */
template <typename T>
struct initial_id;

/**
 * @class GME_ID_Generator_T
 *
 * ID generator for different model element types.
 */
template <typename T>
class GME_ID_Generator_T
{
public:
  /// Default constructor.
  GME_ID_Generator_T (void);

  /// Destructor.
  ~GME_ID_Generator_T (void);

  /**
   * Initialize the id generator.
   *
   * @param[in]     proj      Project used to initial generator
   */
  void init (xercesc::DOMDocument * proj);

  /// Reset the ID generator.
  void reset (void);

  /**
   * Generate a new id for the element.
   *
   * @param[in]     id        New id
   * @retval        true      Successfully generated id
   * @retval        false     Failed to generate id
   */
  const ::Utils::XStr & generate_id  (void);

  const ::Utils::XStr & current_id (void) const;

private:
  /// Number of elements for the given type T.
  XMLSize_t count_;

  /// The current unique id.
  ::Utils::XStr id_;

};

}
}

#define GME_XME_ID_GENERATOR(T) \
  ACE_Singleton <::GAME::XME::GME_ID_Generator_T <T>, \
                 ACE_Null_Mutex>::instance ()

#if defined (__GAME_INLINE__)
#include "GME_ID_Generator_T.inl"
#endif

#include "GME_ID_Generator_T.cpp"

#endif  // !defined _GAME_GME_ID_GENERATOR_H_
