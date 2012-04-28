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

#include "Project.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Filter
 *
 * Help class for filter objects in a project. The main goal of the
 * filter to the perform a recursive search based on where it starts,
 * which can be the project, model, or folder.
 */
class GAME_MGA_Export Filter
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]       project         Owner of the filter.
   */
  Filter (Project project);

  /// Destructor.
  ~Filter (void);

  /**
   * Apply the filter. The elements that match the filter are
   * returned in \a result. This perform a recursive search of the
   * entire project.
   *
   * @param[in]     result        Number of elements in result.
   */
  template <typename T>
  size_t apply (std::vector <T> & result) const;

  template <typename T>
  Iterator <T> apply (void) const;

  /**
   * @overloaded
   *
   * Performs a recursive search starting at the specified model.
   */
  template <typename T>
  size_t apply (const Model_in & model, std::vector <T> & result) const;

  template <typename T>
  Iterator <T> apply (const Model_in & model) const;

  /**
   * @overloaded
   *
   * Performs a recursive search starting at the specified folder.
   */
  template <typename T>
  size_t apply (const Folder_in & folder, std::vector <T> & result) const;

  template <typename T>
  Iterator <T> apply (const Folder_in & folder) const;

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
  Project project_;

  /// Pointer to the actual filter.
  ATL::CComPtr <IMgaFilter> filter_;
};

}
}

#include "Filter_T.cpp"

#endif  // !defined _GME_FILTER_H_
