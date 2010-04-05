// $Id$

#include "xercesc/util/PlatformUtils.hpp"
#include "Memory_Manager.h"

/**
 * @class Xerces_Initializer
 *
 * This class's primary role is to initialize the Xerces-C
 * runtime architecture.
 */
class Xerces_Initializer
{
public:
  /// Method that initializes the runtime architecture.
  static bool init (void)
  {
    using xercesc::XMLPlatformUtils;
    using xercesc::XMLUni;

    // When initializing, we need to provide our own memory manager
    // since we know it will stay alive beyond Terminate (). This
    // will therefore allow the framework to have static strings,
    // which will need a memory manager that lives past Terminate ()
    // to safely release its memory.
    XMLPlatformUtils::Initialize (XMLUni::fgXercescDefaultLocale,
                                  0,
                                  0,
                                  Utils::Global_Memory_Manager::instance ());

    return true;
  }

  /**
   * Initializing constructor.
   *
   * @param[in]     init        Initialization state
   */
  explicit Xerces_Initializer (bool init)
    : init_ (init)
  {

  }

  /// Destructor
  ~Xerces_Initializer (void)
  {
    if (this->init_)
      xercesc::XMLPlatformUtils::Terminate ();
  }

private:
  /// Initialization state of xerces-c
  bool init_;
};

// Force initailization of the architecture.
static Xerces_Initializer xi (Xerces_Initializer::init ());
