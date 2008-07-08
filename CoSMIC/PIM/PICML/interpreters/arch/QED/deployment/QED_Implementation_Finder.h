// -*- C++ -*-

//=============================================================================
/**
 * @file      QED_Implementation_Finder.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _QED_IMPLEMENTATION_FINDER_H_
#define _QED_IMPLEMENTATION_FINDER_H_

#include "PICML/PICML.h"

/**
 * @class QED_Implementation_Finder
 *
 * Visitor that is responsible for locating the implementation 
 * for a given instance.
 */
class QED_Implementation_Finder : public PICML::Visitor
{
public:
  /**
   * Initializing constructor
   *
   * @param[in]       instance        Instance in question.
   * @param[out]      monoimpl        Located monolitic implementation.
   */
  QED_Implementation_Finder (void);

  /// Destructor.
  virtual ~QED_Implementation_Finder (void);

  /**
   * Get the search result.
   *
   * @retval          true            The monolithic implementation was found
   */
  bool is_found (void) const;

  /**
   * Get the located monolitic implemenation. This is only valid if
   * the implementation was actually found. Otherwise, this will be
   * null.
   */
  const PICML::MonolithicImplementation & implementation (void) const;

  void Visit_Component (
    const PICML::Component &);

  void Visit_ComponentRef (
    const PICML::ComponentRef &);

  void Visit_Implements (
    const PICML::Implements &);

private:
  /// The located monolithic implementation.
  PICML::MonolithicImplementation impl_;
};

#endif  // !defined _QED_IMPLEMENTATION_FINDER_H_
