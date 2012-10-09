// -*- C++ -*-

//==============================================================================
/**
 *  @file        Object_Selector.h
 *
 *  $Id: generate_cpp_class.py 3679 2012-04-30 02:25:20Z hillj $
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_OBJECT_BUILDER_H_
#define _GAME_EXTENSION_CLASSES_OBJECT_BUILDER_H_

#include "game/mga/Visitor.h"

/**
 * @class Object_Builder
 *
 * INSERT CLASS DESCRIPTION HERE
 */
class Object_Builder : public GAME::Mga::Visitor
{
public:
  /// Default constructor.
  Object_Builder (void);

  /// Destructor.
  virtual ~Object_Builder (void);

  // Visit a RootFolder element.
  virtual void visit_RootFolder (GAME::Mga::RootFolder_in folder);

  // Visit a Folder element.
  virtual void visit_Folder (GAME::Mga::Folder_in folder);

  // Visit an Atom element.
  virtual void visit_Atom (GAME::Mga::Atom_in atom);

  // Visit a Model element.
  virtual void visit_Model (GAME::Mga::Model_in model);

private:
  void visit_Folder_i (GAME::Mga::Folder_in folder);
};


#if defined (__GAME_INLINE__)
#include "Object_Builder.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_OBJECT_BUILDER_H_
