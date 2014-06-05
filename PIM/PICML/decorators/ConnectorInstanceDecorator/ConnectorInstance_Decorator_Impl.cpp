// $Id$

#include "StdAfx.h"
#include "ConnectorInstance_Decorator.h"
#include "ConnectorInstance_Decorator_Impl.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Model.h"
#include "game/mga/Reference.h"
#include "game/mga/Iterator_T.h"
#include "game/mga/Collection_T.h"
#include "game/mga/graphics/Stock_Objects.h"

#include "boost/bind.hpp"

DECLARE_DECORATOR (ConnectorInstance_Decorator, ConnectorInstance_Decorator_Impl);

//
// ConnectorInstance_Decorator_Impl
//
ConnectorInstance_Decorator_Impl::ConnectorInstance_Decorator_Impl (void)
{

}

//
// ~ConnectorInstance_Decorator_Impl
//
ConnectorInstance_Decorator_Impl::~ConnectorInstance_Decorator_Impl (void)
{

}

//
// initialize
//
int ConnectorInstance_Decorator_Impl::
initialize (const GAME::Mga::Project & proj,
            const GAME::Mga::Meta::Part_in part,
            const GAME::Mga::FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  if (0 != GAME::Mga::FCO_Decorator::initialize (proj, part, fco, sink, window))
    return -1;

  // The label is the name of the object. We also can initialize
  // the implementation label for this element since we are in the
  // active window.
  using GAME::Mga::Model;
  using GAME::Mga::Reference;
  using GAME::Mga::Iterator;

  Model model = Model::_narrow (fco);
  GAME::Mga::Collection_T <Reference> collection = model->children <Reference> ("ConnectorImplementationType").first();

  if (collection.count()!=0)
  {
    using GAME::Mga::FCO;
    FCO refers_to = collection.first();

    if (!refers_to.is_nil ())
      this->impl_label_ = refers_to->name ();
  }

  // Since there is no implementation label, we should set it
  // to undefined. This will help the modeler know that it is
  // missing its implementation.
  if (this->impl_label_.empty ())
    this->impl_label_ = "<undefined>";

  return 0;
}

//
// draw
//
int ConnectorInstance_Decorator_Impl::draw (Gdiplus::Graphics * g)
{
  if (0 != GAME::Mga::FCO_Decorator::draw (g))
    return -1;

  if (!this->impl_label_.empty ())
  {
    const float height = (float)this->location_.height ();
    const float py = static_cast <float> (this->location_.y_) + (height + 30.0f);
    const float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);

    using GAME::Mga::graphics::Stock_Objects;
    const Stock_Objects * stock = GAME::Mga::graphics::GLOBAL_STOCK_OBJECTS::instance ();

    std::string inst_label ("[");
    inst_label += this->impl_label_ + "]";

    CComBSTR inst_bstr (inst_label.length (), inst_label.c_str ());
    g->DrawString (inst_bstr,
                   inst_label.length (),
                   stock->label_font (),
                   Gdiplus::PointF (px, py),
                   stock->label_string_format (),
                   stock->label_brush ());
  }

  return 0;
}
