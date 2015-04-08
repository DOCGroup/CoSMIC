#include "StdAfx.h"
#include "SendsTo.h"

#if !defined (__GAME_INLINE__)
#include "SendsTo.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/InEventPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/InEventPortDelegate.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/OutEventPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/OutEventPortDelegate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string SendsTo_Impl::metaname ("SendsTo");

  //
  // is_abstract
  //
  const bool SendsTo_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, OutEventPortEnd_in src, InEventPortEnd_in dst)
  //
  SendsTo SendsTo_Impl::_create (const ComponentAssembly_in parent, OutEventPortEnd_in src, InEventPortEnd_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, SendsTo_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void SendsTo_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_SendsTo (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly SendsTo_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // OutEventPortEnd
  //
  OutEventPortEnd SendsTo_Impl::src_OutEventPortEnd (void) const
  {
    return OutEventPortEnd::_narrow (this->src ());
  }

  //
  // InEventPortEnd
  //
  InEventPortEnd SendsTo_Impl::dst_InEventPortEnd (void) const
  {
    return InEventPortEnd::_narrow (this->dst ());
  }
}

