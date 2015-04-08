// -*- C++ -*-

//=============================================================================
/**
 * @file          Symbols.h
 *
 * @author        James H. Hill
 */
//=============================================================================

#ifndef _IDML_SYMBOLS_H_
#define _IDML_SYMBOLS_H_

#include "t3/runtime/Symbol.h"

/**
 * @class fq_name
 *
 * Fully qualified name symbol generator.
 */
class fq_name : public T3_Symbol
{
public:
  /// Default constructor.
  fq_name (void);

  /// Destructor.
  virtual ~fq_name (void);

  // Generate the symbol.
  virtual int generate (const GAME::Mga::FCO_in fco, ACE_CString & symbol);
};

#endif  // !defined _IDML_SYMBOLS_H_
