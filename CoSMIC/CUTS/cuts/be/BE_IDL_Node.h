#ifndef _CUTS_BE_IDL_NODE_H_
#define _CUTS_BE_IDL_NODE_H_

#include "BE_export.h"
#include "String_Set.h"
#include <bitset>

// Forward decl.
struct CUTS_BE_IDL_Node;

/// Type definition for a collection of CUTS_BE_IDL_Node objects.
typedef std::set <const CUTS_BE_IDL_Node *> CUTS_BE_IDL_Node_Set;

//=============================================================================
/**
 * @class CUTS_BE_IDL_Node
 *
 * Dependency information for an IDL file.
 */
//=============================================================================

struct CUTS_BE_Export CUTS_BE_IDL_Node
{
  /**
   * Initializing constructor.
   *
   * @param[in]     name        Name of the node.
   */
  CUTS_BE_IDL_Node (const std::string & name);

  /// Flags for the dependency node.
  enum _idl_bits_
  {
    /// The stub project is necessary.
    IDL_STUB    = 0,

    /// The IDL file has been visited.
    IDL_VISITED = 1
  };

  /// Node flags.
  std::bitset <2> flags_;

  /// Name of the node.
  const std::string name_;

  /// Basename of the <name_>.
  const std::string basename_;

  /// Reference set for the node.
  CUTS_BE_IDL_Node_Set references_;
};

#endif  // !defined _CUTS_BE_IDL_NODE_H_
