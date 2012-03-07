// $Id$

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
    ACE_Framework_Repository::instance ()->remove_dll_components ("GAME_XML");
  }
};

static Init __init__;

}

}
