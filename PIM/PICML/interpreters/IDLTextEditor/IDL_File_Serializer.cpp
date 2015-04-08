#include "StdAfx.h"
#include "IDL_File_Serializer.h"
#include "IDL_Generator_File.h"

#include "game/mga/Object.h"
#include "PICML/PICML.h"

#include "UdmGme.h"
#include "UdmStatic.h"

//
// IDL_File_Serializer
//
IDL_File_Serializer::IDL_File_Serializer (void)
{

}

//
// ~IDL_File_Serializer
//
IDL_File_Serializer::~IDL_File_Serializer (void)
{

}

//
// serialize
//
int IDL_File_Serializer::
serialize (const ::GAME::Mga::Object_in obj, std::ostream & stream)
{
  UdmGme::GmeDataNetwork dngBackend (PICML::diagram);

  try
  {
    // Turn this into a UDM object.
    Udm::Object udm_obj = dngBackend.Gme2Udm (obj->impl ());

    // Generate the file to the provided stream.
    PICML::File file = PICML::File::Cast (udm_obj);
    IDL_Generator_File file_gen (stream);
    file_gen.generate (file);

    // Closing backend
    dngBackend.CloseWithUpdate ();
    return 0;
  }
  catch (udm_exception & exc)
  {
    ::AfxMessageBox (exc.what ());
    dngBackend.CloseNoUpdate ();
  }

  return -1;
}
