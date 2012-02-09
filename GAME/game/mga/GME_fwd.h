// -*- C++ -*-

//=============================================================================
/**
 * @file      GME_fwd.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_FWD_H_
#define _GAME_MGA_FWD_H_

#include "Smart_Ptr.h"

namespace GAME
{
namespace Mga
{
  // Forward decl.
  class Attribute_Impl;
  typedef Smart_Ptr <Attribute_Impl> Attribute;
  typedef Attribute_Impl * Attribute_in;

  // Forward decl.
  class Object_Impl;
  typedef Smart_Ptr <Object_Impl> Object;
  typedef Object_Impl * Object_in;

  // Forward decl.
  class FCO_Impl;
  typedef Smart_Ptr <FCO_Impl> FCO;
  typedef FCO_Impl * FCO_in;

  // Forward decl.
  class Model_Impl;
  typedef Smart_Ptr <Model_Impl> Model;
  typedef Model_Impl * Model_in;

  // Forward decl.
  class Atom_Impl;
  typedef Smart_Ptr <Atom_Impl> Atom;
  typedef Atom_Impl * Atom_in;

  // Forward decl.
  class Reference_Impl;
  typedef Smart_Ptr <Reference_Impl> Reference;
  typedef Reference_Impl * Reference_in;

  // Forward decl.
  class RegistryNode_Impl;
  typedef Smart_Ptr <RegistryNode_Impl> RegistryNode;
  typedef RegistryNode_Impl * RegistryNode_in;

  // Forward decl.
  class Project;

  // Forward decl.
  class Set_Impl;
  typedef Smart_Ptr <Set_Impl> Set;
  typedef Set_Impl * Set_in;

  // Forward decl.
  class Folder_Impl;
  typedef Smart_Ptr <Folder_Impl> Folder;
  typedef Folder_Impl * Folder_in;

  // Forward decl.
  class RootFolder_Impl;
  typedef Smart_Ptr <RootFolder_Impl> RootFolder;
  typedef RootFolder_Impl * RootFolder_in;

  // Forward decl.
  class Connection_Impl;
  typedef Smart_Ptr <Connection_Impl> Connection;
  typedef Connection_Impl * Connection_in;

  // Forward decl.
  class ConnectionPoint_Impl;
  typedef Smart_Ptr <ConnectionPoint_Impl> ConnectionPoint;
  typedef ConnectionPoint_Impl * ConnectionPoint_in;

  // Forward decl.
  class ConnectionPoints;

  // Forward decl.
  class Component_Impl;
  typedef Smart_Ptr <Component_Impl> Component;
  typedef Component_Impl * Component_in;

  // Forward decl.
  class ComponentEx_Impl;
  typedef Smart_Ptr <ComponentEx_Impl> ComponentEx;
  typedef ComponentEx_Impl * ComponentEx_in;

  // Forward decl.
  class Visitor;

  namespace Meta
  {
    // Foward decl.
    class Aspect_Impl;
    typedef Smart_Ptr <Aspect_Impl> Aspect;
    typedef Aspect_Impl * Aspect_in;

    // Foward decl.
    class Atom_Impl;
    typedef Smart_Ptr <Atom_Impl> Atom;
    typedef Atom_Impl * Atom_in;

    // Foward decl.
    class Constraint_Impl;
    typedef Smart_Ptr <Constraint_Impl> Constraint;
    typedef Constraint_Impl * Constraint_in;

    // Forward decl.
    class Attribute_Impl;
    typedef Smart_Ptr <Attribute_Impl> Attribute;
    typedef Attribute_Impl * Attribute_in;

    // Foward decl.
    class Part_Impl;
    typedef Smart_Ptr <Part_Impl> Part;
    typedef Part_Impl * Part_in;

    // Forward decl.
    class Base_Impl;
    typedef Smart_Ptr <Base_Impl> Base;
    typedef Base_Impl * Base_in;

    // Forward decl.
    class EnumItem;

    // Forward decl.
    class FCO_Impl;
    typedef Smart_Ptr <FCO_Impl> FCO;
    typedef FCO_Impl * FCO_in;

    // Forward decl.
    class Folder_Impl;
    typedef Smart_Ptr <Folder_Impl> Folder;
    typedef Folder_Impl * Folder_in;

    // Forward decl.
    class Model_Impl;
    typedef Smart_Ptr <Model_Impl> Model;
    typedef Model_Impl * Model_in;

    // Forward decl.
    class Role_Impl;
    typedef Smart_Ptr <Role_Impl> Role;
    typedef Role_Impl * Role_in;

    // Forward decl.
    class Reference_Impl;
    typedef Smart_Ptr <Reference_Impl> Reference;
    typedef Reference_Impl * Reference_in;

    // Forward decl.
    class Set_Impl;
    typedef Smart_Ptr <Set_Impl> Set;
    typedef Set_Impl * Set_in;

    // Forward decl.
    class Connection_Impl;
    typedef Smart_Ptr <Connection_Impl> Connection;
    typedef Connection_Impl * Connection_in;

    // Forward decl.
    class ConnectionPoint_Impl;
    typedef Smart_Ptr <ConnectionPoint_Impl> ConnectionPoint;
    typedef ConnectionPoint_Impl * ConnectionPoint_in;

    // Forward decl.
    class Project;
  }
}
}


#endif  // !defined _GME_FWD_H_
