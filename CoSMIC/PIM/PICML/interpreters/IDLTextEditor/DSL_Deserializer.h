// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_Deserializer.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_DESERIALIZER_H_
#define _DSL_DESERIALIZER_H_

#include <istream>
#include "game/GME_fwd.h"

/**
 * @class DSL_Deserializer
 *
 * Base class for all domain-specific language (DSL) deserializers. The
 * deserializer converts a (text) stream back into the object-model.
 */
class DSL_Deserializer
{
public:
  /// Default constuctor.
  DSL_Deserializer (void);

  /// Destructor.
  virtual ~DSL_Deserializer (void);

  /**
   * Serialize the stream to the object.
   *
   * @param[in]       obj       Target object
   * @param[out]      stream    Input stream for retrieving text.
   * @retval          0         Success
   * @retval          -1        Failure
   */
  virtual int deserialize (std::istream & stream, ::GAME::Object_in obj) = 0;
};

#endif  // !define _DSL_SERIALIZER_H_
