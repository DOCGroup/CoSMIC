// -*- C++ -*-

//=============================================================================
/**
 * @file      CUTS_BE_List_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_LIST_T_H_
#define _CUTS_BE_LIST_T_H_

namespace CUTS_BE
{
  /// End of list marker.
  struct EOL;

  //===========================================================================
  /**
   * @class List_T
   *
   * Metaprogrammable implementation of a linked list. The linked-list
   * allows programmers to create a chain of generators that are to
   * be executed using the same parameters. This solves the problem of
   * iterating the entire multiple times to generate multiple files based
   * on the same parsing algorithm. Currently, the list can handle generators
   * that accept up to 5 parameters.
   */
  //===========================================================================

  template <typename STRATEGY_GENERATOR, typename NEXT = EOL>
  class List_T
  {
  public:
    /// 0-paremeter generate method.
    static inline bool generate (void)
    {
      return
        STRATEGY_GENERATOR::generate () |
        NEXT::generate ();
    }

    /// 1-parameter generate method.
    template <typename P1>
    static inline bool generate (P1 p1)
    {
      return
        STRATEGY_GENERATOR::generate (p1) |
        NEXT::generate (p1);
    }

    /// 2-parameter generate method.
    template <typename P1, typename P2>
    static inline bool generate (P1 p1, P2 p2)
    {
      return
        STRATEGY_GENERATOR::generate (p1, p2) |
        NEXT::generate (p1, p2);
    }

    /// 3-parameter generate method.
    template <typename P1, typename P2, typename P3>
    static inline bool generate (P1 p1, P2 p2, P3 p3)
    {
      return
        STRATEGY_GENERATOR::generate (p1, p2, p3) |
        NEXT::generate (p1, p2, p3);
    }

    /// 4-parameter generate method.
    template <typename P1, typename P2, typename P3, typename P4>
    static inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4)
    {
      return
        STRATEGY_GENERATOR::generate (p1, p2, p3, p4) |
        NEXT::generate (p1, p2, p3, p4);
    }

    /// 5-parameter generate method.
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    static inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      return
        STRATEGY_GENERATOR::generate (p1, p2, p3, p4, p5) |
        NEXT::generate (p1, p2, p3, p4, p5);
    }
  };

  //===========================================================================
  /**
   * @class List_T
   *
   * Specialization of the CUTS_BE::List_T for the CUTS_BE::NIL
   * generator. This shortcuts the
   */
  //===========================================================================

  template <typename STRATEGY_GENERATOR>
  class List_T <STRATEGY_GENERATOR, EOL>
  {
  public:
    /// 0-paremeter generate method.
    static inline bool generate (void)
    {
      return STRATEGY_GENERATOR::generate ();
    }

    /// 1-parameter generate method.
    template <typename P1>
    static inline bool generate (P1 p1)
    {
      return STRATEGY_GENERATOR::generate (p1);
    }

    /// 2-parameter generate method.
    template <typename P1, typename P2>
    static inline bool generate (P1 p1, P2 p2)
    {
      return STRATEGY_GENERATOR::generate (p1, p2);
    }

    /// 3-parameter generate method.
    template <typename P1, typename P2, typename P3>
    static inline bool generate (P1 p1, P2 p2, P3 p3)
    {
      return STRATEGY_GENERATOR::generate (p1, p2, p3);
    }

    /// 4-parameter generate method.
    template <typename P1, typename P2, typename P3, typename P4>
    static inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4)
    {
      return STRATEGY_GENERATOR::generate (p1, p2, p3, p4);
    }

    /// 5-parameter generate method.
    template <typename P1, typename P2, typename P3, typename P4, typename P5>
    static inline bool generate (P1 p1, P2 p2, P3 p3, P4 p4, P5 p5)
    {
      return STRATEGY_GENERATOR::generate (p1, p2, p3, p4, p5);
    }
  };
}

#endif  // !defined _CUTS_BE_LIST_T_H_
