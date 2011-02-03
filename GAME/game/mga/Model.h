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

namespace GAME
{
namespace Mga
{
/**
 * @class Model_Impl
 *
 * Wrapper class for the IMgaModel interface.
 */
class GAME_MGA_Export Model_Impl : public FCO_Impl
{
public:
  /// Type definition of the COM interface.
  typedef IMgaModel interface_type;

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

  virtual void accept (Visitor * v);

  size_t children (std::vector <FCO> & children) const;
  size_t children (const std::string & type, std::vector <FCO> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <FCO> & children) const;

  size_t children (std::vector <Atom> & children) const;
  size_t children (const std::string & type, std::vector <Atom> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <Atom> & children) const;

  size_t children (std::vector <Model> & children) const;
  size_t children (const std::string & type, std::vector <Model> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <Model> & children) const;

  size_t children (std::vector <Reference> & children) const;
  size_t children (const std::string & type, std::vector <Reference> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <Reference> & children) const;

  size_t children (std::vector <Connection> & children) const;
  size_t children (const std::string & type, std::vector <Connection> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <Connection> & children) const;

  size_t children (std::vector <Set> & children) const;
  size_t children (const std::string & type, std::vector <Set> & children) const;
  size_t children (const Meta::Aspect_in aspect, std::vector <Set> & children) const;

  void attach (IMgaModel * model);

  /// Helper method to get the correct implementation.
  IMgaModel * impl (void) const;

private:
  /// Pointer to the underlying COM interface.
  mutable ATL::CComPtr <IMgaModel> model_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Model.inl"
#endif

#endif // !defined _GAME_MODEL_H_
