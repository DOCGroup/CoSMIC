// -*- C++ -*-

//=============================================================================
/**
 * @file      RegistryNode.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_REGISTRYNODE_H_
#define _GME_REGISTRYNODE_H_

#include "Exception.h"

#if !defined (__ComponentLib_h__)
#include "Mga.h"
#endif

#include <vector>

namespace GME
{
  // Forward decl.
  class RegistryNode;

  /// Collection of registry nodes.
  typedef std::vector <RegistryNode> RegistryNodes;

  //===========================================================================
  /**
   * @class RegistryNode
   *
   * Wrapper for the IMgaRegNode interface.
   */
  //===========================================================================

  class GME_Export RegistryNode
  {
  public:
    /// Default constructor.
    RegistryNode (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       node          Source object.
     */
    RegistryNode (IMgaRegNode * node);

    /**
     * Copy constructor.
     *
     * @param[in]       registry
     */
    RegistryNode (const RegistryNode & registry);

    /// Destructor.
    ~RegistryNode (void);

    /**
     * Attach to an existing node.
     *
     * @param[in]       node      The source node.
     */
    void attach (IMgaRegNode * node);

    /**
     * Assignment operator.
     *
     * @param[in]       node      The right-hand side.
     * @return          Reference to this object.
     */
    const RegistryNode & operator = (const RegistryNode & node);

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
     * @param[in]       virtual_types       Include the virtual nodes.
     * @return          Collection of child nodes.
     */
    size_t children (RegistryNodes & nodes,
                     bool vtypes = false) const;

    /// Empty the current value in this node.
    void empty (void);

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

    /**
     * Convert the node object into a boolean value. This will
     * test if the node is valid (i.e., is a NIL pointer).
     *
     * @retval          true        The object is valid.
     * @retval          false       The object is NIL.
     */
    operator bool (void) const;

    /**
     * Convert the node to its interface pointer.
     *
     * @return          Interface pointer to the object.
     */
    operator IMgaRegNode * (void) const;

  private:
    /// Pointer to the node.
    CComPtr <IMgaRegNode> node_;
  };
}

#if defined (__GME_INLINE__)
#include "RegistryNode.inl"
#endif

#endif  // !defined _GME_REGISTRYNODE_H_
