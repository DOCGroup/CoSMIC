// -*- C++ -*-

//=============================================================================
/**
 * @file        Output_Event_Builder.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _OUTPUT_EVENT_BUILDER_H_
#define _OUTPUT_EVENT_BUILDER_H_

#include "game/GME_fwd.h"

/**
 * @class CBML_Output_Event_Builder
 */
class CBML_Output_Event_Builder
{
public:
  CBML_Output_Event_Builder (GAME::Model & output);

  ~CBML_Output_Event_Builder (void);

private:
  GAME::Model & output_;
};

#endif  // !defined _OUTPUT_EVENT_BUILDER_H_
