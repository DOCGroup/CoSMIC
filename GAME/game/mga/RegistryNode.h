// -*- C++ -*-

//=============================================================================
/**
 * @file      RegistryNode_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_REGISTRY_NODE_H_
#define _GAME_MGA_REGISTRY_NODE_H_

#include <string>
#include <vector>

#include "Refcountable.h"
#include "GME_fwd.h"

namespace GAME
{
namespace Mga
{

/**
 * @class RegistryNode_Impl
 *
 * Wrapper for the IMgaRegNode interface.
 */
class GAME_MGA_Export RegistryNode_Impl : public Refcountable
{
public:
  /// Type definition for the interface.
  typedef IMgaRegNode interface_type;

  /// Default constructor.
  RegistryNode_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       node          Source object.
   */
  RegistryNode_Impl (IMgaRegNode * node);


  /// Destructor.
  ~RegistryNode_Impl (void);

  /**
   * Attach to an existing node.
   *
   * @param[in]       node      The source node.
   */
  void attach (IMgaRegNode * node);

  /**
   * Get the name of the node.
   *
   * @return          Name of the node.
   */
  std::string name (void) const;

  /**
   * Get the status of the registry node.
   *
   * @return          The current status.
   */
  long status (void) const;

  /**
   * Determine if this is a first-class node (i.e., not inherited).
   *
   * @retval          true        The node is here.
   * @retval          false       The node is not here.
   */
  bool status_here (void) const;

  /**
   * Determine if this node is defined in the meta.
   *
   * @retval          true        The node is in meta.
   * @retval          false       The node is not in meta.
   */
  bool status_meta (void) const;

  /**
   * Determine if this node is inherited.
   *
   * @retval          true        The node is inherited.
   * @retval          false       The node is not inherited.
   */
  bool status_inherited (void) const;

  /**
   * Get the current value.
   *
   * @return          The current value of the node.
   */
  std::string value (void) const;

  /**
   * Set the value of the registry node.
   *
   * @param[in]       value       The new value.
   */
  void value (const std::string & value);

  /**
   * Get the path of this node with respect to the root node.
   *
   * @return          The path of the node.
   */
  std::string path (void) const;

  /**
   * Get the parent registry node of this registry node.
   *
   * @return          The parent node of this node.
   */
  RegistryNode parent (void) const;

  /**
   * Get a registry node by name.
   *
   * @param[in]       name        Name of the node.
   * @return          The registry node.
   */
  RegistryNode child (const std::string & name) const;

  /**
   * Get all the child registry nodes of this node.
   *
   * @param[in]       virtualinterface_types       Include the virtual nodes.
   * @return          Collection of child nodes.
   */
  size_t children (std::vector <RegistryNode> & nodes,
                   bool vtypes = false) const;

  /// Clear the current value of this node.
  void clear (void);

  /**
   * Get the opacity value.
   *
   * @return          The current opacity value.
   */
  bool opacity (void) const;

  /**
   * Set the opacity value.
   *
   * @param[in]       opacity       The new opacity value.
   */
  void opacity (bool opacity);

  /// Destroy the current node and all its children.
  void destroy (void);

private:
  /// Pointer to the node.
  ATL::CComPtr <IMgaRegNode> node_;
};

}
}

#if defined (__GAME_INLINE__)
#include "RegistryNode.inl"
#endif

#endif  // !defined _GME_REGISTRYNODE_H_
