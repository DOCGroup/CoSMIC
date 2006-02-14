#include "cuts/pir/Component.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Component.inl"
#endif

#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventSink.h"
#include "cuts/pir/Event_Source.h"
#include "cuts/pir/Periodic_Action.h"
#include "cuts/pir/Worker_Type.h"
#include "cuts/pir/Facet.h"
#include "cuts/pir/Method.h"
#include "cuts/utils/Functor_T.h"
#include <algorithm>

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
    std::for_each (
      this->event_sinks_.begin (),
      this->event_sinks_.end (),
      Delete_Element_T <Event_Sinks::value_type> ());

    std::for_each (
      this->event_sources_.begin (),
      this->event_sources_.end (),
      Delete_Element_T <Event_Sources::value_type> ());

    std::for_each (
      this->facets_.begin (),
      this->facets_.end (),
      Delete_Element_T <Facets::value_type> ());

    std::for_each (
      this->worker_types_.begin (),
      this->worker_types_.end (),
      Delete_Element_T <Worker_Types::value_type> ());

    std::for_each (
      this->periodic_actions_.begin (),
      this->periodic_actions_.end (),
      Delete_Element_T <Periodic_Actions::value_type> ());
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
