// -*- C++ -*-

//=============================================================================
/**
 * @file        MetaModel.h
 *
 * Defines the Meta::Model_Impl class
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_META_MODEL_H_
#define _GAME_MGA_META_MODEL_H_

#include "MetaFCO.h"
#include "MetaAspect.h"
#include "MetaRole.h"
#include <vector>

namespace GAME
{
namespace Mga
{
namespace Meta
{

/**
 * @class Model_Impl
 *
 * Wrapper class for the IMgaMetaModel COM interface.
 */
class GAME_MGA_Export Model_Impl : public FCO_Impl
{
public:
  /// Type definition of COM type.
  typedef IMgaMetaModel interface_type;

  /// Default constructor.
  Model_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       meta        Pointer to the COM interface.
   */
  Model_Impl (IMgaMetaModel * meta);

  /// Destructor.
  virtual ~Model_Impl (void);

  /**
   * Get the role by name.
   *
   * @param[in]       name        Name of the role.
   * @return          The role for the specified \a name.
   */
  Role role (const std::string & name) const;

   /**
   * Get all the roles this Model is associated with.
   *
   * @param[out]      roles      All the metaroles this Model is associated with.
   */
  size_t roles (std::vector <Role> & roles) const;

  /**
   * Get the underlying COM interface pointer.
   *
   * @return          COM interface pointer.
   */
  IMgaMetaModel * impl (void) const;

  /**
   * Get the collection of meta FCO objects.
   *
   * @param[out]      fcos      List of meta FCO objects.
   */
  size_t children (std::vector <FCO> & fcos) const;

  /**
   * Get the aspect for the specified role.
   *
   * @param[in]       name        Name of the aspect.
   * @return          Reference to the aspect.
   */
  Aspect aspect (const std::string & name) const;

  /**
   * Get a listing of all the aspects for this role.
   *
   * @param[out]      aspects     List of aspects.
   */
  size_t aspects (std::vector <Aspect> & children) const;

private:
  /// Pointer to the raw COM interface.
  mutable CComPtr <IMgaMetaModel> metamodel_;
};

}
}
}

#if defined (__GAME_INLINE__)
#include "MetaModel.inl"
#endif

#endif  // !defined _GAME_MGA_META_MODEL_H_
