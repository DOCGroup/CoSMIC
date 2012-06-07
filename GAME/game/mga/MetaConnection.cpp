// $Id$

#include "stdafx.h"
#include "Mga.h"
#include "MetaConnection.h"
#include "Collection_T.h"


#if !defined (__GAME_INLINE__)
#include "MetaConnection.inl"
#endif

#include "Exception.h"
#include "MetaRole.h"
#include "MetaProject.h"
#include "MetaFolder.h"
#include <string>

namespace GAME
{
namespace Mga
{
namespace Meta
{

///////////////////////////////////////////////////////////////////////////////
// ConnectionPoint_Impl

//
// parent
//
Connection ConnectionPoint_Impl::parent (void) const
{
  CComPtr <IMgaMetaConnection> conn;
  VERIFY_HRESULT (this->impl ()->get_Parent (&conn));

  return new Connection_Impl (conn.p);
}

//
// roles
//
size_t ConnectionPoint_Impl::roles (std::vector <std::string> &rls) 
{
  // Get all the reference pointer specifications.
  CComPtr <IMgaMetaPointerSpecs> specs;
  VERIFY_HRESULT (this->impl ()->get_PointerSpecs (&specs));

  // Locate each specification in the project and store it.
  long count = 0;
  specs->get_Count (&count);

  for (long i = 1; i <= count; ++ i)
  {
	  // Get a reference pointer specification.
	  CComPtr <IMgaMetaPointerSpec> spec;
	  VERIFY_HRESULT (specs->get_Item (i, &spec));

	  // Get the name of the reference pointer
	  CComBSTR name;
	  VERIFY_HRESULT (spec->get_Name (&name));
	  CW2A tempstr (name);

	  rls.push_back (tempstr.m_psz);
  }  
  return rls.size ();
}

//
// targets
//
size_t ConnectionPoint_Impl::targets (std::vector<FCO> &fcos)
{
  // Get all the reference pointer specifications.
  CComPtr <IMgaMetaPointerSpecs> specs;
  VERIFY_HRESULT (this->impl ()->get_PointerSpecs (&specs));

  // Locate each specification in the project and store it.
  long count = 0;
  specs->get_Count (&count);

  for (long i = 1; i <= count; ++ i)
  {
	  // Get a reference pointer specification.
	  CComPtr <IMgaMetaPointerSpec> spec;
	  VERIFY_HRESULT (specs->get_Item (i, &spec));

	  // Get each of the items in the specification.
	  CComPtr <IMgaMetaPointerItems> items;
	  VERIFY_HRESULT (spec->get_Items (&items));

	  // Get the root folder for this project.
	  Folder root_folder = this->parent ()->project ().root_folder (); //Collecting it from the parent

	  // Locate each item in the project and store it.
	  long num = 0;
	  items->get_Count (&num);

	  for (long j = 1; j <= num; ++ j)
	  {
		  CComBSTR name;
		  CComPtr <IMgaMetaPointerItem> item;

		  // Get the next item in the collection.
		  VERIFY_HRESULT (items->get_Item (j, &item));
		  VERIFY_HRESULT (item->get_Desc (&name));

		  // Locate the FCO with the specified name.
		  CComPtr <IMgaMetaFCO> fco;
		  VERIFY_HRESULT (root_folder->impl ()->get_DefinedFCOByName (name, VARIANT_TRUE, &fco));

		  if (0 != fco.p)
			  fcos.push_back (fco.p);
	  }
  }
  return fcos.size ();
}

//
// get_src
//
FCO ConnectionPoint_Impl::get_src (void)
{
  FCO source;

  // Get all the reference pointer specifications.
  CComPtr <IMgaMetaPointerSpecs> specs;
  VERIFY_HRESULT (this->impl ()->get_PointerSpecs (&specs));

  // Locate each specification in the project and store it.
  long count = 0;
  specs->get_Count (&count);

  for (long i = 1; i <= count; ++ i)
  {
	  // Get a reference pointer specification.
	  CComPtr <IMgaMetaPointerSpec> spec;
	  VERIFY_HRESULT (specs->get_Item (i, &spec));

	  // Get the name of the reference pointer
	  CComBSTR spec_name;
	  VERIFY_HRESULT (spec->get_Name (&spec_name));

	  if (spec_name == "src")
	  {
		  // Get each of the items in the specification.
		  CComPtr <IMgaMetaPointerItems> items;
		  VERIFY_HRESULT (spec->get_Items (&items));

		  // Get the root folder for this project.
		  Folder root_folder = this->parent ()->project ().root_folder (); //Collecting it from the parent

		  // Locate each item in the project and store it.
		  long num = 0;
		  items->get_Count (&num);

		  for (long j = 1; j <= num; ++ j)
		  {
			  CComBSTR name;
			  CComPtr <IMgaMetaPointerItem> item;

			  // Get the next item in the collection.
			  VERIFY_HRESULT (items->get_Item (j, &item));
			  VERIFY_HRESULT (item->get_Desc (&name));

			  // Locate the FCO with the specified name.
			  CComPtr <IMgaMetaFCO> fco;
			  VERIFY_HRESULT (root_folder->impl ()->get_DefinedFCOByName (name, VARIANT_TRUE, &fco));

				source = fco.p;
				
		  }
	  }
  }
  return source;
}


//
// get_dsts
//
std::vector <std::vector<FCO>> ConnectionPoint_Impl::get_dsts (void)
{
  std::vector <std::vector<FCO>> destinations;
  
  // Get all the reference pointer specifications.
  CComPtr <IMgaMetaPointerSpecs> specs;
  VERIFY_HRESULT (this->impl ()->get_PointerSpecs (&specs));

  // Locate each specification in the project and store it.
  long count = 0;
  specs->get_Count (&count);

  for (long i = 1; i <= count; ++ i)
  {
	  // Get a reference pointer specification.
	  CComPtr <IMgaMetaPointerSpec> spec;
	  VERIFY_HRESULT (specs->get_Item (i, &spec));

	  // Get the name of the reference pointer
	  CComBSTR spec_name;
	  VERIFY_HRESULT (spec->get_Name (&spec_name));

	  if (spec_name == "dst")
	  {
		  // Get each of the items in the specification.
		  CComPtr <IMgaMetaPointerItems> items;
		  VERIFY_HRESULT (spec->get_Items (&items));

		  // Get the root folder for this project.
		  Folder root_folder = this->parent ()->project ().root_folder (); //Collecting it from the parent

		  // Locate each item in the project and store it.
		  long num = 0;
		  items->get_Count (&num);

		  for (long j = 1; j <= num; ++ j)
		  {
        // Holds the vector to be pushed into main vector
        std::vector <FCO> temps;

			  CComBSTR name;
			  CComPtr <IMgaMetaPointerItem> item;

			  // Get the next item in the collection.
			  VERIFY_HRESULT (items->get_Item (j, &item));
        VERIFY_HRESULT (item->get_Desc (&name));

        // Spliting the name into two halves
        std::wstring conv = name;
        std::wstring::size_type pos = conv.find(L' ');
        CComBSTR name1, name2;
        name1 = conv.substr(0, pos).c_str();
        name2 = conv.substr(pos+1).c_str();

			  // Locate the first FCO with the specified name.
			  CComPtr <IMgaMetaFCO> fco1;
			  VERIFY_HRESULT (root_folder->impl ()->get_DefinedFCOByName (name1, VARIANT_TRUE, &fco1));
			  
        temps.push_back (fco1.p);

        // Locate the second FCO if it exists
        if (name2.Length () > 0 && name1 != name2)
        {
          CComPtr <IMgaMetaFCO> fco2;
			    VERIFY_HRESULT (root_folder->impl ()->get_DefinedFCOByName (name2, VARIANT_TRUE, &fco2));
  			  
          temps.push_back (fco2.p);
        }

        destinations.push_back (temps);
		  }
	  }
  }
  return destinations;
}

///////////////////////////////////////////////////////////////////////////////
// Connection_Impl

//
// impl
//
IMgaMetaConnection * Connection_Impl::impl (void) const
{
  // Optimize for the quick path.
  if (this->conn_.p == this->metabase_.p)
    return this->conn_;

  // So, we have to actually initalize the <meta_fco_>.
  if (this->conn_)
    this->conn_.Release ();

  VERIFY_HRESULT (this->metabase_.QueryInterface (&this->conn_));
  return this->conn_;
}

//
// points
//
size_t Connection_Impl::connectors (std::vector <ConnectionPoint> & points) const
{
  CComPtr <IMgaMetaConnJoints> temp;
  VERIFY_HRESULT (this->impl ()->get_Joints (&temp));

  return iter_to_collection (temp.p, points);
}

}
}
}
