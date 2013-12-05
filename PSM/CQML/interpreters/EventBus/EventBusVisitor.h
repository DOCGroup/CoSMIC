#ifndef EVENTBUSVISITOR_H
#define EVENTBUSVISITOR_H

#include "CQML/CQML.h"
#include "EventBus/EventBus_Export.h"

namespace CQML
{
	/// Forward declaration for the "compilation-firewall" effect.
	class EventBusVisitorImpl;

	class EventBus_Export EventBusVisitor: public Visitor
	{
	public:
		EventBusVisitor (const std::string& outputPath);
		~EventBusVisitor();
		virtual void Visit_RootFolder(const RootFolder &);

	private:
		EventBusVisitor (const EventBusVisitor &);
		/// Compilation firewall idiom and const auto_ptr idiom
		/// for non-transferable ownership
		const std::auto_ptr <EventBusVisitorImpl> impl_;
	};

} // namespace CQML

#endif //EVENTBUSVISITOR_H
