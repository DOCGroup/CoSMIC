// -*- C++ -*-

//=============================================================================
/**
 * @file      Model_Impl.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_MODEL_H_
#define _GAME_MGA_MODEL_H_

#include "FCO.h"
#include "Iterator_T.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Model_Impl
 *
 * Wrapper class for the IMgaModel interface.
 */
class GAME_MGA_Export Model_Impl : public virtual FCO_Impl
{
public:
  /// Type definition of the COM interface.
  typedef IMgaModel interface_type;

  /// Type definition of the type tag.
  typedef model_tag_t type_tag;

  /**
   * Create a new model element.
   *
   * @param[in]       type          The role of the new object, i.e.,
   *                                its meta name.
   * @param[in]       parent        The parent model.
   * @return          The newly created model.
   */
  static Model _create (const Model_in parent, const std::string & type);
  static Model _create (const Model_in parent, const Meta::Role_in role);

  /**
   * Create a new model element.
   *
   * @param[in]       type          The model's type.
   * @param[in]       parent        Parent folder of the model.
   * @return          The newly created model.
   */
  static Model _create (const Folder_in parent, const std::string & type);
  static Model _create (const Folder_in parent, const Meta::FCO_in type);

  /// Default constructor.
  Model_Impl (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       model       The source interface.
   */
  Model_Impl (IMgaModel * model);

  /// Destructor.
  virtual ~Model_Impl (void);

  /**
   * Get the meta information for this model.
   *
   * @return      The meta information for the model.
   */
  Meta::Model meta (void) const;

  /// Accept a visitor object.
  virtual void accept (Visitor * v);

  /**
   * Generic implementation for gathering the children. This version
   * of the children () method is designed to work with extension
   * classes.
   *
   * @param[in]         children      The selected children
   * @return            Number of children selected
   */
  template <typename T>
  size_t children (std::vector <T> & items) const;

  /**
   * Get an iterator to the children. The actual item type is defined
   * using the template parameter for this method (i.e., children <T> ()).
   *
   * @return            Iterator to the children.
   */
  template <typename T>
  Iterator <T> children (void) const;

  /**
   * @overloaded
   *
   * This version of the children () method will not only select child
   * elements of /a type, but it will also cast them to an Mga object
   * of type T.
   *
   * @param[in]         type          Type to select
   * @param[in]         children      The selected children
   * @return            Number of children selected
   */
  template <typename T>
  size_t children (const std::string & type, std::vector <T> & children) const;

  /**
   * @overloaded
   */
  template <typename T>
  Iterator <T> children (const std::string & type) const;

  /**
   * @overloaded
   *
   * This version of the children () method will not only select child
   * elements in \a aspect, but it will also cast them to an Mga object
   * of type T.
   *
   * @param[in]         aspect        Aspect to select from
   * @param[in]         children      The selected children
   * @return            Number of children selected
   */
  template <typename T>
  size_t children (const Meta::Aspect_in aspect, std::vector <T> & children) const;

  /// Attach to the IMgaModel interface.
  void attach (IMgaModel * model);

  /// Helper method to get the correct implementation.
  IMgaModel * impl (void) const;

private:
  /// Pointer to the underlying COM interface.
  mutable ATL::CComPtr <IMgaModel> model_;
};

/**
 * @struct object_type_t
 *
 * Specialization of the object type for Model_Impl.
 */
template < >
struct object_type_t <Model_Impl>
{
  static const int result_type = OBJTYPE_MODEL;
};

}
}

#if defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#include "Model_T.cpp"

#endif // !defined _GAME_MODEL_H_
