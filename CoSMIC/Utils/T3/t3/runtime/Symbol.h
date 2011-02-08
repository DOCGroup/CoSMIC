// -*- C++ -*-

//=============================================================================
/**
 *  @file         Symbol.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _T3_SYMBOL_H_
#define _T3_SYMBOL_H_

#include "Runtime_export.h"
#include "ace/SString.h"
#include "game/mga/GME_fwd.h"

/**
 * @class T3_Symbol
 *
 * Base class for all symbol generators.
 */
class T3_RUNTIME_Export T3_Symbol
{
public:
  /// Default constructor.
  T3_Symbol (void);

  /// Destructor.
  virtual ~T3_Symbol (void);

  /**
   * Generate the symbol for the specified object.
   *
   * @param[in]     fco         Target FCO.
   * @retval        0           Success
   * @retval        -1          Failure
   */
  virtual int generate (const GAME::Mga::FCO_in fco, ACE_CString & symbol) = 0;
};

#include "Symbol.inl"

#endif  // !defined _T3_SYMBOL_H_
