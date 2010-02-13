// -*- C++ -*-

//=============================================================================
/**
 * @file      Quantifier_Node.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _T3_QUANTIFIER_NODE_H_
#define _T3_QUANTIFIER_NODE_H_

#include "Node.h"

/**
 * @class T3_Quantifier_Node
 *
 * Base class for adding quantifier suppport to a node.
 */
class T3_Quantifier_Node : public T3_Node
{
public:
  /// Destructor.
  virtual ~T3_Quantifier_Node (void);

  enum type_t
  {
    Q_NONE          = 0,
    Q_ONE_OR_MORE   = 1,
    Q_ZERO_OR_MORE  = 2
  };

  type_t quantifier_value (void) const;

  void quantifier_value (type_t type);

protected:
  /// Default constructor.
  T3_Quantifier_Node (void);

private:
  type_t quantifier_;
};

#include "Quantifier_Node.inl"

#endif  // !defined _T3_QUANTIFIER_NODE_H_
