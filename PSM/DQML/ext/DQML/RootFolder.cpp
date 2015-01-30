// $Id$

#include "stdafx.h"
#include "RootFolder.h"
#include "Visitor.h"

#include "DQML/iCCM/iCCM/iCCM.h"
#include "DQML/Standard/Main/DDSQoS.h"

namespace DQML
{
  const std::string RootFolder_Impl::metaname ("RootFolder");

  RootFolder_Impl::RootFolder_Impl (void)
  {
  }

  RootFolder_Impl::RootFolder_Impl (IMgaFolder * folder)
  : ::GAME::Mga::Folder_Impl (folder),
    ::GAME::Mga::RootFolder_Impl (folder)
  {
  }

  RootFolder_Impl::~RootFolder_Impl (void)
  {
  }

  void RootFolder_Impl::accept (::GAME::Mga::Visitor * v)
  {
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RootFolder (this);
    else
      v->visit_Folder (this);
  }

  size_t RootFolder_Impl::get_iCCM (std::vector <iCCM> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <iCCM> RootFolder_Impl::get_iCCM (void) const
  {
    return this->folders <iCCM> ();
  }

  size_t RootFolder_Impl::get_DDSQoS (std::vector <DDSQoS> & items) const
  {
    return this->children (items);
  }

  ::GAME::Mga::Collection_T <DDSQoS> RootFolder_Impl::get_DDSQoS (void) const
  {
    return this->children <DDSQoS> ();
  }
}


