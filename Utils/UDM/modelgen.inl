// -*- C++ -*-
// $Id$

namespace CoSMIC
{
	namespace Udm
	{
		//
		// find
		//
		template <typename P, typename T, typename PRED>
		inline
			bool find (P & parent, T & element, PRED predicate)
		{
			contains_t <PRED> c (predicate);
			return c (parent, element);
		}

		//
		// contains_t
		//
		template <typename PRED>
		inline
			contains_t <PRED>::contains_t (PRED predicate)
			: predicate_ (predicate)
		{

		}

		//
		// contains_t::operator ()
		//
		template <typename PRED>
		template <typename T>
		inline
			bool contains_t <PRED>::
			operator () (const std::set <T> & container, T & element)
		{
			return this->find_i (container.begin (), container.end (), element);
		}

		//
		// contains_t::operator ()
		//
		template <typename PRED>
		template <typename T>
		inline
			bool contains_t <PRED>::
			operator () (const std::vector <T> & container, T & element)
		{
			return this->find_i (container.begin (), container.end (), element);
		}

		//
		// contains
		//
		template <typename PRED>
		inline
			contains_t <PRED> contains (PRED predicate)
		{
			return contains_t <PRED> (predicate);
		}
	}
}