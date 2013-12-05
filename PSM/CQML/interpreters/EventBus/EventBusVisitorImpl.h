#ifndef EVENTBUSVISITORIMPL_H
#define EVENTBUSVISITORIMPL_H

#include "EventBus/BaseMessage.h"
#include "EventBus/EventBusMember.h"
#include "EventBus/EventBus_Export.h"

#include "CQML/CQML.h"
#include "ace/DLL.h"

#include <list>

namespace CQML
{
	class Router
	{
	public:


	};

	class Registrar
	{

	};

	class MemberManager
	{
	public:
		MemberManager ();
		~MemberManager ();
		void load_members (std::list <std::string> const &);
		
		typedef EventBusMember* (*Member_Creator) (void);
		static std::string start_symbol_;

	private:
		struct DLL_Member_Pair
		{
			ACE_DLL dll_;
			EventBusMember *member_;
		};
		void destroy_member (std::pair <std::string, DLL_Member_Pair> const &);
		int load_dll (std::string const &dll);
		std::map <std::string, DLL_Member_Pair> member_map_;
	};

	typedef std::list <BaseMessage <void> *> MessageQueue;
	class EventBusVisitorImpl: public Visitor
	{
	public:
		EventBusVisitorImpl (const std::string& outputPath);
		~EventBusVisitorImpl();
		virtual void Visit_RootFolder(const RootFolder &);

	protected:
		void begin (void);

	private:
		std::string outputpath_;
		MemberManager member_manager_;
	};

} // namespace CQML

#endif EVENTBUSVISITORIMPL_H
