// $Id$

#include "stdafx.h"
#include "ace/Framework_Component.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Init
 */
class Init
{
public:
  ~Init (void)
  {
    ACE_Framework_Repository::instance ()->remove_dll_components ("GAME_Mga_Component");
  }
};

static Init __init__;

}

}
