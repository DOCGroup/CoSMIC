/* -*- C++ -*- */

//=============================================================================
/**
 * @file      PICMLManager_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_MANAGER_IMPL_H_
#define _PICML_MANAGER_IMPL_H_

#include "game/be/Event_Handler_Impl.h"

/**
 * @class PICMLManager_Impl
 *
 * Raw COM implementation of the PICML manager add-on.
 */
class PICMLManager_Impl : public GAME::Event_Handler_Impl
{
public:
  /// Constructor.
  PICMLManager_Impl (void);

  /// Destructor.
  virtual ~PICMLManager_Impl (void);

  virtual int initialize (GAME::Project project);
};

#endif // _PICML_MANAGER_IMPL_H_
