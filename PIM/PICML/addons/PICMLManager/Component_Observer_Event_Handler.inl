// -*- C++ -*-
namespace PICML
{
namespace MI
{

//
// ~Component_Observer_Event_Handler
//
inline
Component_Observer_Event_Handler::~Component_Observer_Event_Handler (void)
{

}

//
// insert
//
inline
void Component_Observer_Event_Handler::
insert (Component_in comp, ComponentInstance_in inst)
{
  this->map_[comp].insert (inst);
}

} // namespace PICML
} // namespace MI
