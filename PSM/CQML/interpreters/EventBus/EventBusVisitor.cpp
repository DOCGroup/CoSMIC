#include "EventBus/EventBusVisitor.h"
#include "EventBus/EventBusVisitorImpl.h"

namespace CQML
{

EventBusVisitor::EventBusVisitor (const std::string& outputPath)
: impl_ (new EventBusVisitorImpl(outputPath))
{
	/// Uses compilation firewall.
}

EventBusVisitor::~EventBusVisitor()
{
	/// impl_ is an auto_ptr. It will be deleted.
}

void EventBusVisitor::Visit_RootFolder(const RootFolder &rf)
{
	impl_->Visit_RootFolder (rf);
}

} // namespace CQML
