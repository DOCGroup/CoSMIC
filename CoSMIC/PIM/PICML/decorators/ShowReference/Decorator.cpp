// $Id$

#include "StdAfx.h"
#include "Decorator.h"
#include "resource.h"
#include "DecoratorLib_i.c"
#include "DecoratorUtil.h"

#include "game/be/Decorator_Module.h"
#include "game/FCO.h"
#include "game/Reference.h"
#include "game/Project.h"
#include "game/MetaRole.h"
#include "game/MetaFCO.h"
#include "game/MetaPart.h"
#include "game/utils/Parser.hpp"
#include <fstream>

static CDecoratorUtil d_util;

//
// registrar_
//
GAME::utils::Registrar Show_Reference_Decorator_Impl::registrar_;

DECLARE_DECORATOR_MODULE (LIBID_ShowReferenceDecoratorLibrary, IDR_DECORATOR, "{CDD72C3A-3340-4225-83D6-46B10E9A763E}")

//
// Show_Reference_Decorator_Impl
//
Show_Reference_Decorator_Impl::Show_Reference_Decorator_Impl (void)
{

}

//
// ~Show_Reference_Decorator_Impl
//
Show_Reference_Decorator_Impl::~Show_Reference_Decorator_Impl (void)
{

}

//
// initialize
//
int Show_Reference_Decorator_Impl::
initialize (const GAME::Project & proj, 
            const GAME::Meta::Part & part, 
            const GAME::FCO & fco,
            IMgaCommonDecoratorEvents * eventSink, 
            ULONGLONG parentWnd)
{
	return this->initialize (proj, part, fco);
}

//
// initialize
//
int Show_Reference_Decorator_Impl::
initialize (const GAME::Project & project, 
            const GAME::Meta::Part & part,
            const GAME::FCO & fco)
{
  // Set the parser configuration.
  GAME::utils::PathParserConfig config (project);

  // Initialize the parser.
  std::vector <std::string> paths;
  GAME::utils::PathParser <std::string::const_iterator> grammar (config, paths);

  // Extract paths from registrar and tokenize the string.
  std::string path = this->registrar_.icon_path (GAME::utils::Registrar::ACCESS_BOTH);
  
  using boost::phoenix::ref;
  namespace qi = boost::spirit::qi;
  namespace ascii = boost::spirit::ascii;

  bool result = qi::phrase_parse (path.begin (), 
                                  path.end (), 
                                  grammar, 
                                  ascii::space);

  std::string icon_filename;

  if (fco.is_nil ())
  {
    // Get the icon for the element in the parts browser.
    GAME::Meta::FCO metafco = part.role ().kind ();

    icon_filename = metafco.registry_value ("icon");
    this->label_ = metafco.display_name ().c_str ();
  }
  else
  {
    // Get the icon filename for the referenced element. If no 
    // element is referenced, then display the reference's icon.
    GAME::Reference ref = GAME::Reference::_narrow (fco);
    GAME::FCO refers_to = ref.refers_to ();


    if (!refers_to.is_nil ())
      icon_filename = refers_to.registry_value ("icon");
    else
      icon_filename = ref.registry_value ("icon");

    // Determine if we need to show the label for the element.
    std::string show_name = ref.registry_value ("isNameEnabled");

    if (show_name.empty () || show_name == "true")
      this->label_ = ref.name ().c_str ();
  }

  // Determine the exact location of the filename based on the
  // paths retrieved from the registrar.
  std::string filename;
  std::vector <std::string>::const_iterator 
    iter = paths.begin (), iter_end = paths.end ();

  CFile bitmap_file;
  for (; iter != iter_end; ++ iter)
  {
    filename = *iter + "\\" + icon_filename;

    if (bitmap_file.Open (filename.c_str (), CFile::modeRead | CFile::shareDenyWrite))
      break;
  }

  // If we are not able to locate the bitmap, we should just load
  // the default bitmap for the reference.

  // Now, let's load the bitmap into memory.
  this->bitmap_.Read (bitmap_file);
  bitmap_file.Close ();

  return S_OK;
}

////
//// GetMnemonic
////
//STDMETHODIMP CDecorator::GetMnemonic (BSTR *mnemonic)
//{
//  *mnemonic = CComBSTR (L"MGA.Decorator.ShowReference").Detach ();
//  return S_OK;
//}

//
// GetPreferredSize
//
int Show_Reference_Decorator_Impl::
get_preferred_size (long & sx, long & sy)
{
  sx = this->bitmap_.Width ();
  sy = this->bitmap_.Height ();

  return 0;
}

//
// draw
//
int Show_Reference_Decorator_Impl::draw (CDC & context)
{
  CRect rect (this->location_.x_, 
              this->location_.y_, 
              this->location_.cx_, 
              this->location_.cy_);

  this->bitmap_.Draw (&context, rect);
 
  CPoint name_location (rect.left + this->bitmap_.Width () / 2,
                        rect.bottom + 20);

  COLORREF name_color (RGB (0x00, 0x00, 0x00));

  d_util.DrawText (&context,
                   this->label_,
                   name_location,
                   d_util.GetFont (GME_NAME_FONT),
                   name_color,
                   TA_BOTTOM | TA_CENTER);

  return S_OK;
}

//
// draw
//
int Show_Reference_Decorator_Impl::
draw (CDC & context, Gdiplus::Graphics & g)
{
  return this->draw (context);
}
