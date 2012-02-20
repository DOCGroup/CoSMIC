// -*- C++ -*-

//=============================================================================
/**
 * @file      FCO_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_FCO_H_
#define _GAME_MGA_FCO_H_

#include "GME_fwd.h"
#include "Object.h"
#include "Part.h"
#include "Iterator_T.h"
#include "Attribute.h"

namespace GAME
{
namespace Mga
{

/**
 * @class FCO_Impl
 *
 * Wrapper class for the IMgaFCO interface. Since an FCO is always abstract,
 * is not possible to create one. Instead, you can only narrow an existing
 * object to an FCO type.
 */
class GAME_MGA_Export FCO_Impl : public virtual Object_Impl
{
public:
  /// Type definition of the COM pointer type.
  typedef IMgaFCO interface_type;

  /// Type definition of the type tag.
  typedef fco_tag_t type_tag;

  /// Default constructor.
  FCO_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     fco         Pointer to the source FCO_Impl.
   */
  FCO_Impl (IMgaFCO * fco);

  /// Destructor.
  virtual ~FCO_Impl (void);

  /**
   * Determine if the FCO_Impl is an instance.
   *
   * @retval        true        FCO_Impl is an instance.
   * @retval        false       FCO_Impl is not an instance.
   */
  bool is_instance (void) const;

  /**
   * Get the instance type.
   *
   * @retval        The instance's type. NULL if the object is
   *                not an instance.
   */
  FCO instance_type (void) const;

  /**
   * Determine if the FCO_Impl is the first derivation of anohter
   * object. If there object is not a subtype, this will always
   * return \a false.
   *
   * @retval        true        FCO_Impl is a first derivation.
   * @retval        false       FCO_Impl is not a first derivation.
   */
  bool is_primary_derived (void) const;

  /**
   * Attach the object to another interface.
   *
   * @param[in]     fco         The source FCO_Impl.
   */
  void attach (IMgaFCO * fco);

  /**
   * Get the meta information for this object.
   *
   * @return        Its meta information.
   */
  Meta::FCO meta (void) const;

  /**
   * Get the meta information about its role.
   *
   * @return        Its role's meta information.
   */
  Meta::Role role (void) const;

  /**
   * Helper method to return this IMgaFCO implementation from
   * the object interface. This operation then caches the interface
   * for future usage, as long as the underlying object doesn't
   * change. Otherwise, the interface has to be re-cached.
   *
   * @return      Pointer to the FCO_Impl implementation.
   */
  IMgaFCO * impl (void) const;

  /**
   * Create a new instance of the a model.
   *
   * @param[in]       role          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created model.
   */
  FCO create_instance (const Model_in parent);

  /**
   * Create a new model element.
   *
   * @param[in]       role          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created model.
   */
  FCO create_subtype (const Model_in parent);

  /**
   * Get the archetype for the object. The archetype is the top
   * most basetype in a multi-hierarchial derivation tree.
   *
   * @return      The archetype of the object.
   */
  FCO archetype (void) const;

  /**
   * Determine if the object is a subtype.
   *
   * @retval      true      It is a subtype.
   * @retval      false     It is not a subtype.
   */
  bool is_subtype (void) const;

  /**
   * Get the basetype for the object. The base type is the closet
   * object that the current object is derived from in a multi-
   * hierarchial derivation tree.
   *
   * @return      The basetype for the object.
   */
  FCO basetype (void) const;

  /**
   * Get a registry value.
   *
   * @param[in]   path      The path of the value.
   * @return      The value stored at \a path.
   */
  std::string registry_value (const std::string & path) const;

  /**
   * Set_Impl a registry value.
   *
   * @param[in]   path      The path of the value.
   * @param[in]   value     The new value of \a path.
   */
  void registry_value (const std::string & path, const std::string & value);

  /**
   * Get an attribute by name.
   *
   * @param[in]       name        Name of the attribute.
   * @return          Attribute object.
   */
  Attribute attribute (const std::string & name) const;

  Attribute attribute (const Meta::Attribute_in name) const;

  /**
   * Get the attributes of the FCO_Impl.
   *
   * @param[out]  attrs     The attributes of the FCO_Impl.
   * @return      Number of attributes.
   */
  size_t attributes (std::vector <Attribute> & attrs) const;

  /**
   * Get the parent of the FCO_Impl, which is a model.
   *
   * @return      Parent folder object.
   */
  Model parent_model (void) const;

  /**
   * Get the parent of the FCO_Impl, which is a folder.
   *
   * @return      Parent model object.
   */
  Folder parent_folder (void) const;

  /**
   * Get the collection of connection points that are using
   * this FCO_Impl. It can be either the src or dst connection point
   * of a connection.
   *
   * @param[out]      points      Collection of connection points
   * @return          Number of items in \a points
   */
  size_t in_connection_points (ConnectionPoints & points) const;

  size_t in_connections (std::vector <Connection> & conns) const;
  size_t in_connections (const std::string & type, std::vector <Connection> & conns) const;

  template <typename T>
  size_t in_connections (std::vector <T> & conns) const;

  /**
   * Get the part information for the given aspect.
   *
   * @param[in]       aspect      The target aspect.
   */
  Part part (const Meta::Aspect_in aspect) const;

  /**
   * Get the sets that contains this FCO_Impl.
   *
   * @param[out]      sets        Collection of sets
   * @return          Number of items in \a sets
   */
  size_t in_sets (std::vector <Set> & sets) const;
  Iterator <Set> in_sets (void) const;

  /**
   * Get the collection of objects this object is derived
   * from.
   *
   * @return          The FCO_Impl this FCO_Impl is derived from.
   */
  FCO derived_from (void) const;

  /**
   * Get the registry for the FCO_Impl.
   *
   * @param[out]      nodes         The collection of registry nodes
   * @param[in]       vtypes        Include virtual registry nodes
   */
  size_t registry (std::vector <RegistryNode> & nodes,
                   bool vtypes = false) const;

  /**
   * Get the registry node for this folder object.
   *
   * @return      The registry node.
   */
  RegistryNode registry_node (const std::string & path) const;

  /**
   * Get the referenced objects for this FCO_Impl.
   *
   * @return      size.
   */
  size_t referenced_by (std::vector <Reference> & refs) const;
  Iterator <Reference> referenced_by (void) const;

private:
  /// The COM pointer for the FCO_Impl type.
  mutable ATL::CComPtr <IMgaFCO> fco_;
};

}
}

#if defined (__GAME_INLINE__)
#include "FCO.inl"
#endif

#include "FCO_T.cpp"

#endif  // !define _GME_FCO_H_
