// $Id$

#include "UdmBase.h"
#include <algorithm>

namespace CoSMIC
{
	namespace Udm
	{
		template <typename T, typename V>
		void visit_all (T coll, V & v) 
		{
      std::for_each (coll.begin (), coll.end (), [&] (T::value_type item) {
        item.Accept (v);
      });
		}

		template <typename T, typename P, typename V>
		void visit_all (const P & parent, V & v) 
		{
			std::vector <T> children =
        ::UDM_NAMESPACE::ChildrenAttr <T> (parent.__impl (), 
                                           ::UDM_NAMESPACE::NULLCHILDROLE);

			visit_all (children, v);
		}
	}
}
