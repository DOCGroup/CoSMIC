// -*- C++ -*-

//=============================================================================
/**
 * @file      Filter.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_FILTER_H_
#define _GME_FILTER_H_

#include "Exception.h"
#include "Collection_T.h"

namespace GAME
{
// Forward decl.
class Project;

/**
 * @class Filter
 *
 * Help class for filter objects in a project.
 */
class GAME_Export Filter
{
public:
  /**
   * Initializing constructor
   */
  Filter (Project & project);

  /// Destructor.
  ~Filter (void);

  /**
   * Apply the filter. The elements that match the filter are
   * returned in \a result.
   *
   * @param[in]     result        Number of elements in result.
   */
  size_t apply (std::vector <FCO> & result) const;

  /**
   * Set the kind attribute for the filter.
   *
   * @param[in]       name        The kind value
   */
  void kind (const std::string & value);
  void kind (std::vector <std::string> & value);
  void kind (std::vector <Meta::FCO> & fcos);

  void name (const std::string & value);
  void name (std::vector <std::string> & value);

private:
  /// Reference to the project.
  GAME::Project & project_;

  /// Pointer to the actual filter.
  mutable ATL::CComPtr <IMgaFilter> filter_;
};

}

#endif  // !defined _GME_FILTER_H_
