// -*- C++ -*-

//==============================================================================
/**
 *  @file        Folder_Class_Definition.h
 *
 *  $Id$
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _GAME_EXTENSION_CLASSES_FOLDER_CLASS_DEFINITION_H_
#define _GAME_EXTENSION_CLASSES_FOLDER_CLASS_DEFINITION_H_

#include "Object_Class_Definition.h"

/**
 * @class Folder_Class_Definition
 *
 * Class definition for the Folder model element.
 */
class Folder_Class_Definition :
  public Object_Class_Definition
{
public:
  /// Default constructor.
  Folder_Class_Definition (void);

  /// Destructor.
  virtual ~Folder_Class_Definition (void);

  /// Build the class definition for the FCO element.
  virtual void build (GAME::Mga::FCO_in fco);

  // Generate the folder definition.
  virtual void generate_definition (const Generation_Context & ctx);

protected:
  /// Get the include objects for this class definition. The include
  /// statement for these model elements will appear in the source
  /// file.
  virtual void get_includes (std::set <GAME::Mga::Atom> & includes);

private:
  // Generate folder containment definition.
  void generate_folder_containment (const Generation_Context & ctx,
                                    GAME::Mga::Atom_in);

  /// Collection of contained elements.
  std::set <GAME::Mga::Atom> children_;
};

#if defined (__GAME_INLINE__)
#include "Folder_Class_Definition.inl"
#endif  // !defined __GAME_INLINE__

#endif  // _GAME_EXTENSION_CLASSES_FOLDER_CLASS_DEFINITION_H_
