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

namespace BON
{
  // Forward decl.
  class Object;
}

/**
 * @class DSL_Deserializer
 *
 * Base class for all domain-specific language (DSL) serializers.
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
  virtual int deserialize (const BON::Object & obj, std::istream & stream) = 0;
};

#endif  // !define _DSL_SERIALIZER_H_