// $Id$

#include "StdAfx.h"

#include "DeploymentStatusDecorator_Impl.h"
#include "DeploymentStatusDecorator.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/Set.h"
#include "game/mga/Connection.h"
#include "game/mga/graphics/Image_Resource.h"
#include "game/mga/graphics/Stock_Objects.h"

#include "resource.h"

DECLARE_DECORATOR (DeploymentStatusDecorator, DeploymentStatusDecorator_Impl);

//
// DeploymentStatusDecorator_Impl
//
DeploymentStatusDecorator_Impl::DeploymentStatusDecorator_Impl (void)
: GAME::Mga::Reference_Decorator (true, true)
{

}

//
// ~DeploymentStatusDecorator_Impl
//
DeploymentStatusDecorator_Impl::~DeploymentStatusDecorator_Impl (void)
{

}

//
// initialize
//
int DeploymentStatusDecorator_Impl::
initialize (const GAME::Mga::Project & project,
            const GAME::Mga::Meta::Part_in part,
            const GAME::Mga::FCO_in fco,
            IMgaCommonDecoratorEvents * sink,
            ULONGLONG window)
{
  if (0 != GAME::Mga::Reference_Decorator::initialize (project, part, fco, sink, window))
    return -1;

  // Get the elements deployment information.
  GAME::Mga::Iterator <GAME::Mga::Set> sets = fco->in_sets ();

  if (sets.count ())
  {
    // Save the name of the collocation group.
    GAME::Mga::Set group = sets.item ();
    this->deployment_ = group->name () + "@";

    // Trace the collocation group to its node.
    std::vector <GAME::Mga::Connection> conns;
    if (group->in_connections ("InstanceMapping", conns))
      this->deployment_ += conns[0]->dst ()->name ();
  }
  else
  {
    using GAME::Mga::graphics::Image_Resource;
    this->question_.reset (Image_Resource::load (IDB_QUESTION, "PNG"));
  }

  return 0;
}

//
// draw
//
int DeploymentStatusDecorator_Impl::draw (Gdiplus::Graphics * g)
{
  // First, pass control to the base class.
  if (0 != GAME::Mga::Reference_Decorator::draw (g))
    return -1;

  if (0 == this->question_.get ())
  {
    // Draw the deployment location to the window. The deployment
    // location will appear below the name of the element.
    const float height = static_cast <float> (this->location_.height ());
    const float px = static_cast <float> (this->location_.x_) + (this->location_.width () / 2.0f);
    const float py = static_cast <float> (this->location_.y_) + (height + 45.0f);

    using GAME::Mga::graphics::Stock_Objects;
    using GAME::Mga::graphics::GLOBAL_STOCK_OBJECTS;

    const CComBSTR bstr (this->deployment_.length (), this->deployment_.c_str ());
    Stock_Objects * sos = GLOBAL_STOCK_OBJECTS::instance ();

    g->DrawString (bstr,
                   this->deployment_.length (),
                   sos->label_font (),
                   Gdiplus::PointF (px, py),
                   sos->label_string_format (),
                   sos->label_brush ());

  }
  else
  {
    // Since we do not know where this element is deployed, we are
    // going to overlay a question mark.
    const Gdiplus::Point pt (this->location_.x_ - 10, this->location_.y_ - 10);
    g->DrawImage (this->question_.get (), pt);
  }

  return 0;
}
