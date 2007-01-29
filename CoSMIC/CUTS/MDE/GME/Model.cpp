// $Id$

#include "Model.h"
#include "Set.h"
#include "Atom.h"
#include "Reference.h"

namespace GME
{
  //
  // Model
  //
  Model::Model (void)
  {

  }

  //
  // Model
  //
  Model::Model (IMgaModel * model)
    : FCO (model)
  {

  }

  //
  // Model
  //
  Model::Model (const Model & model)
    : FCO (model)
  {

  }

  //
  // ~Model
  //
  Model::~Model (void)
  {

  }

  //
  // operator =
  //
  const Model & Model::operator = (const Model & model)
  {
    if (this != &model)
      this->object_ = model.object_;

    return *this;
  }

  //
  // operator =
  //
  void Model::attach (IMgaModel * model)
  {
    VERIFY_HRESULT (model->QueryInterface (&this->object_));
  }

  //
  // get_children
  //
  template <typename T>
  std::vector <T> Model::get_children (const std::string & type) const
  {
    CComPtr <IMgaFCOs> fcos;
    CComBSTR bstr (type.length (), type.c_str ());
    VERIFY_HRESULT (this->impl ()->GetChildrenOfKind (bstr, &fcos));

    // Determine how many folders there are.
    long count;
    VERIFY_HRESULT (fcos->get_Count (&count));
    std::vector <T> children (count);

    if (count > 0)
    {
      // Store all the folders in a vector.
      CComPtr <IMgaFCO> * array = new CComPtr <IMgaFCO> [count];
      VERIFY_HRESULT (fcos->GetAll (count, &(*array)));

      for (long i = 0; i < count; i ++)
      {
        typename T::_type * temp = 0;
        array[i].QueryInterface (&temp);

        children[i].attach (temp);
      }

      // Delete the temp array.
      delete [] array;
    }

    return children;
  }

  //
  // models
  //
  std::vector <Model> Model::models (const std::string & type) const
  {
    return this->get_children <Model> (type);
  }

  //
  // fcos
  //
  std::vector <FCO> Model::fcos (const std::string & type) const
  {
    return this->get_children <FCO> (type);
  }


  //
  // atoms
  //
  std::vector <Atom> Model::atoms (const std::string & type) const
  {
    return this->get_children <Atom> (type);
  }


  //
  // set
  //
  std::vector <Set> Model::sets (const std::string & type) const
  {
    return this->get_children <Set> (type);
  }

  //
  // references
  //
  std::vector <Reference> Model::references (const std::string & type) const
  {
    return this->get_children <Reference> (type);
  }

  //
  // impl
  //
  IMgaModel * Model::impl (void) const
  {
    if (this->model_.p != this->object_.p)
      VERIFY_HRESULT (this->object_.QueryInterface (&this->model_));

    return this->model_;
  }
}
