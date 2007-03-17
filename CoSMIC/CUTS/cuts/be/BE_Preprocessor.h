// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Preprocessor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_PREPROCESSOR_H_
#define _CUTS_BE_PREPROCESSOR_H_

#include "BE_export.h"
#include "BE_IDL_Graph.h"
#include "BE_Impl_Graph.h"
#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @class CUTS_BE_Preprocessor
 *
 * Preprocessor object for PICML models. This object provides
 * methods for preprocessing stub and implemenation models. The
 * preprocessed data is stored in the respective singleton
 * objects, i.e., CUTS_BE_IDL_Graph
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Preprocessor :
  public PICML::Visitor
{
public:
  /// Default constructor.
  CUTS_BE_Preprocessor (void);

  /// Destructor.
  ~CUTS_BE_Preprocessor (void);

  /**
   * Preprocess a file.
   *
   * @param[in]     file            Source file.
   * @retval        true            Success
   * @retval        false           Failure
   */
  bool preprocess (const PICML::File & file);

  /**
   * Preprocess an implementation.
   *
   * @param[in]     container       Source implementation.
   * @retval        true            Success
   * @retval        false           Failure
   */
  bool preprocess (
    const PICML::ComponentImplementationContainer & container);

  /**
   * Remove an implementation from the proprocessor.
   *
   * @param[in]     container       The target containe to remove.
   */
  void remove (
    const PICML::ComponentImplementationContainer & container);

  /**
   * Get a reference to the preprocessed implementations. Clients
   * are not able to modify the implementation graph.
   *
   * @return  Reference to a implementation graph.
   */
  const CUTS_BE_Impl_Graph & impls (void) const;

  /**
   * Get a reference to the preprocessed stub (i.e., interface
   * definition files). Clients are not able to modify the
   * implementation graph.
   *
   * @return  Reference to a stub graph.
   */
  const CUTS_BE_IDL_Graph & stubs (void) const;

private:
  /// The IDL graph.
  CUTS_BE_IDL_Graph idl_graph_;

  /// The implementation graph.
  CUTS_BE_Impl_Graph impl_graph_;

  /// The current implementation being preprocessed.
  CUTS_BE_Impl_Node * current_impl_;

  // prevent the following operations
  CUTS_BE_Preprocessor (const CUTS_BE_Preprocessor &);
  const CUTS_BE_Preprocessor & operator = (const CUTS_BE_Preprocessor &);
};

CUTS_BE_SINGLETON_DECLARE(ACE_Singleton,
                          CUTS_BE_Preprocessor,
                          ACE_Null_Mutex);

#define CUTS_BE_PREPROCESSOR() \
  ACE_Singleton <CUTS_BE_Preprocessor, \
                 ACE_Null_Mutex>::instance ()

#if defined (__CUTS_INLINE__)
#include "BE_Preprocessor.inl"
#endif

#endif  // !defined _CUTS_BE_PREPROCESSOR_H_
