#ifndef _CUTS_BE_IDL_NODE_H_
#define _CUTS_BE_IDL_NODE_H_

#include "BE_export.h"
#include "String_Set.h"

// Forward decl.
struct CUTS_BE_IDL_Node;

/// Type definition for a collection of CUTS_BE_IDL_Node objects.
typedef std::set <CUTS_BE_IDL_Node *> CUTS_BE_IDL_Node_Set;

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
  enum IDL_Flags
  {
    /// None of the flags are set.
    IDL_NONE        = 0x0000,

    /// The stub project is necessary (value 1).
    IDL_STUB        = 0x0001,

    /// The node has been visited (value 2).
    IDL_VISITED     = 0x0002
  };

  /// Node flags.
  long flags_;

  /// Name of the node.
  const std::string name_;

  /// Basename of the <name_>.
  const std::string basename_;

  /// Reference set for the node.
  CUTS_BE_IDL_Node_Set references_;
};

#endif  // !defined _CUTS_BE_IDL_NODE_H_
