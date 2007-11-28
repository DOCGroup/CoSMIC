// -*- C++ -*-

//=============================================================================
/**
 * @file      GME.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#include "Attribute.h"
#include "Project.h"
#include "Folder.h"
#include "Model.h"
#include "Atom.h"
#include "Set.h"
#include "Reference.h"

#include "MetaAttribute.h"
#include "MetaEnumItem.h"
#include "MetaModel.h"
#include "MetaFolder.h"
#include "MetaRole.h"

namespace GME
{
  /**
   * Initialize the GME backend. This method must be called each
   * time the backend is used with a stand-alone GME application.
   * If this backend is used in a GME component, it is not necessary
   * to invoke this method.
   */
  void GME_Export init (void);

  /**
   * Finalize the GME backend. This method must be invoked each
   * time the init () method is invoked.
   */
  void GME_Export fini (void);
}
