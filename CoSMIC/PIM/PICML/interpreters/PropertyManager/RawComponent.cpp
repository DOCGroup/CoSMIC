// $Id$

#include "StdAfx.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "game/GME.h"

#include "PICML/Data_Value.h"
#include "PICML/Data_Value_Builder.h"

#include "PropertyManager_Dialog.h"
#include <strstream>

//
// RawComponent
//
RawComponent::RawComponent (void)
{

}

//
// ~RawComponent
//
RawComponent::~RawComponent (void)
{

}

//
// Initialize
//
STDMETHODIMP RawComponent::Initialize (struct IMgaProject *)
{
  return S_OK;
}

//
// Invoke
//
STDMETHODIMP RawComponent::Invoke (IMgaProject* gme,
                                   IMgaFCOs *models,
                                   long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// InvokeEx
//
STDMETHODIMP RawComponent::
InvokeEx (IMgaProject * proj, IMgaFCO * curr,
          IMgaFCOs * selected, long param)
{
  try
  {
    GAME::Project project (proj);

    try
    {
      // Begin a new transaction for the project.
      project.begin_transaction ();

      // Extract the selected objects.
      typedef std::vector <GAME::FCO> FCO_set;
      FCO_set properties;

      GAME::get_children (selected, properties);

      typedef FCO_set::iterator iterator;

      for (iterator iter = properties.begin ();
           iter != properties.end ();
           iter ++)
      {
        if (iter->meta ().name () == "Property")
        {
          // Get the data type of the property.
          GAME::FCO datatype;

          if (this->get_datatype (*iter, datatype))
          {
            // Construct the data value object based on the type. In
            // actuallity, we are only concerned with the complex data
            // types.
            PICML_Data_Value * value = 0;
            GME::PICML_Data_Value_Builder data_value_builder;

            if (data_value_builder.create_data_value (iter->name (),
                                                      datatype,
                                                      value))
            {
              std::auto_ptr <PICML_Data_Value> auto_clean (value);

              // Now that we have built the data value, we need to
              // initialize its value.
              PICML_DT_Control * control = 0;

              // Get the data value of the property. We are going to
              // initialize all the values of the <data_value>.
              GAME::Attribute attr = iter->attribute ("DataValue");
              value->value (attr.string_value ());

              // Display the dialog to the user. This will enable him to
              // edit the values of the properties.
              PICML_Property_Manager_Dialog dlg (value, ::AfxGetMainWnd ());

              if (dlg.DoModal () == IDOK)
                attr.string_value (value->value ());
            }
            else
            {
              ::AfxMessageBox ("Failed to create data value",
                               MB_OK | MB_ICONERROR);
            }
          }
        }
      }

      // Save all the changes we made to the model.
      project.commit_transaction ();
    }
    catch (GAME::Failed_Result & )
    {
      // Abort the transaction since we encountered an
      // error during the update process.
      project.abort_transaction ();
    }
  }
  catch (GAME::Failed_Result &)
  {

  }

  return S_OK;
}

//
// ObjectsInvokeEx
//
STDMETHODIMP RawComponent::ObjectsInvokeEx (IMgaProject *project,
                                            IMgaObject *currentobj,
                                            IMgaObjects *selectedobjs,
                                            long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// get_ComponentParameter
//
STDMETHODIMP RawComponent::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}

//
// put_ComponentParameter
//
STDMETHODIMP RawComponent::
put_ComponentParameter(BSTR name, VARIANT newVal)
{
  return S_OK;
}

//
// get_datatype
//
bool RawComponent::
get_datatype (const GAME::FCO & property, GAME::FCO & datatype)
{
  try
  {
    // Try to convert the object into a model.
    GAME::Model model = GAME::Model::_narrow (property);

    // Get the datatype, which is a reference. If there aren't
    // any datatypes in the models, then we need to just leave.
    std::vector <GAME::Reference> datatypes;

    if (model.children ("DataType", datatypes) == 0)
      return false;

    // Now, get the referenced object. This is the actual
    // data type that we need to build the for.
    datatype = datatypes[0].refers_to ();
    return true;
  }
  catch (const GAME::Failed_Result &)
  {

  }

  return false;
}
