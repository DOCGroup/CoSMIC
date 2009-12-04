// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_Serializer.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_SERIALIZER_H_
#define _DSL_SERIALIZER_H_

#include <ostream>

namespace BON
{
  // Forward decl.
  class Object;
}

/**
 * @class DSL_Serializer
 *
 * Base class for all domain-specific language (DSL) serializers.
 */
class DSL_Serializer
{
public:
  /// Default constuctor.
  DSL_Serializer (void);

  /// Destructor.
  virtual ~DSL_Serializer (void);

  /**
   * Serialize the stream to the object.
   *
   * @param[in]       obj       Target object to serialize.
   * @param[in]       stream    Target output stream for text.
   * @retval          0         Success
   * @retval          -1        Failure
   */
  virtual int serialize (const BON::Object & obj, std::ostream & stream) = 0;
};

#endif  // !define _DSL_SERIALIZER_H_
