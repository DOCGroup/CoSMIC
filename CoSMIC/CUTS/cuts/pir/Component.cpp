#include "cuts/pir/Component.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Component.inl"
#endif

#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/Worker_Type.h"
#include "cuts/pir/Facet.h"

namespace CUTS_PIR
{
  //
  // Component
  //
  Component::Component (void)
    : home_ (0)
  {

  }

  //
  // ~Component
  //
  Component::~Component (void)
  {
    for ( Event_Sinks::iterator iter = this->event_sinks_.begin ();
          iter != this->event_sinks_.end ();
          iter ++)
    {
      delete (*iter);
    }

    for ( Facets::iterator iter = this->facets_.begin ();
          iter != this->facets_.end ();
          iter ++)
    {
      delete (*iter);
    }

    for ( Worker_Types::iterator iter = this->worker_types_.begin ();
          iter != this->worker_types_.end ();
          iter ++)
    {
      delete (*iter);
    }
  }

  //
  // home
  //
  void Component::home (Component_Home * home)
  {
    this->home_.reset (home);
    home->manages (this);
  }
}
