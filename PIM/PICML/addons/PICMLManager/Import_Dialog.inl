// -*- C++ -*-
// $Id: generate_cpp_class.py 3685 2012-09-26 14:45:04Z dfeiock $

namespace PICML
{
namespace MI
{

//
// Import_Dialog
//
inline
Import_Dialog::Import_Dialog (Implementation_Configuration & config, CWnd * parent)
: CDialog (IDD_IMPORT, parent),
  config_ (config)
{

}

//
// ~Import_Dialog
//
inline
Import_Dialog::~Import_Dialog (void)
{

}

}
} // namespace PICML
