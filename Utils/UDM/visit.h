// -*- C++ -*-

//=============================================================================
/**
 *  @file     visit.h
 *
 *  $Id$
 *
 *  @author   James H. Hill
 */
//=============================================================================

#ifndef _UDM_UTILS_VISIT_H_
#define _UDM_UTILS_VISIT_H_
namespace CoSMIC
{
	namespace Udm
	{
		template <typename T, typename V>
		void visit_all (T coll, V & v);

		template <typename T, typename P, typename V>
		void visit_all (const P & parent, V & v);

	}
}

#include "visit.cpp"

#endif  // !defined _UDM_UTILS_VISIT_H_
