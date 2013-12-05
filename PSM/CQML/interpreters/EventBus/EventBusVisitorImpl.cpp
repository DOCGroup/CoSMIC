#include "EventBusVisitorImpl.h"

#include <algorithm>
#include <functional>
#include <sstream>

#include <boost/bind.hpp>
#include <boost/ref.hpp>

namespace CQML
{
using boost::bind;
using boost::ref;
using boost::cref;

EventBusVisitorImpl::EventBusVisitorImpl (const std::string& outputPath)
: outputpath_ (outputPath)
{
	this->begin ();
}

EventBusVisitorImpl::~EventBusVisitorImpl()
{

}

void EventBusVisitorImpl::begin ()
{
	std::list <std::string> dll_list;
	dll_list.push_back (std::string ("FaultToleranced"));
	this->member_manager_.load_members (dll_list);
}


void EventBusVisitorImpl::Visit_RootFolder(const RootFolder &rf)
{

}

///////////////////////
///  MemberManager
///////////////////////

std::string MemberManager::start_symbol_ ("create_member");

MemberManager::MemberManager ()
{
}

MemberManager::~MemberManager()
{
    std::for_each (member_map_.begin (), 
		           member_map_.end (), 
				   bind (&MemberManager::destroy_member, ref (*this), _1));
	member_map_.clear ();
}

void MemberManager::destroy_member (std::pair <std::string, DLL_Member_Pair> const &pair)
{
	delete pair.second.member_;
	const_cast <ACE_DLL &>(pair.second.dll_).close ();	
}

void MemberManager::load_members (std::list <std::string> const &dll_list)
{
	std::for_each (dll_list.begin (), 
		           dll_list.end (),
                   bind (&MemberManager::load_dll, ref (*this), _1));
}

int MemberManager::load_dll (std::string const &dll_file)
{
  ACE_DLL dll (0);
  std::ostringstream ostr;
  int retval = dll.open (dll_file.c_str(), ACE_DEFAULT_SHLIB_MODE, 0);

  if (retval != 0)
  {
	  ostr << "EventBus: ACE_DLL.open (\"" << dll_file << "\") failed!";
	  throw udm_exception (ostr.str());
  }

  Member_Creator mc;

  // Cast the void* to non-pointer type first - it's not legal to
  // cast a pointer-to-object directly to a pointer-to-function.

  void *void_ptr = dll.symbol (ACE_TEXT (MemberManager::start_symbol_.c_str()));
  ptrdiff_t tmp = reinterpret_cast<ptrdiff_t> (void_ptr);
  mc = reinterpret_cast<Member_Creator> (tmp);

  if (mc == 0)
  {
	  ostr << "EventBus: ACE_DLL.symbol (\"" << MemberManager::start_symbol_
		  << "\") failed for " << dll_file 
		  << " DLL.";
	  dll.close ();
	  throw udm_exception (ostr.str());
  }

  std::auto_ptr <EventBusMember> member ((*mc )());
  std::pair <std::string, DLL_Member_Pair> pair;
  pair.first = dll_file;
  pair.second.dll_ = dll;
  pair.second.member_ = member.release ();
  this->member_map_.insert (pair);
  
  return 0;
}


};