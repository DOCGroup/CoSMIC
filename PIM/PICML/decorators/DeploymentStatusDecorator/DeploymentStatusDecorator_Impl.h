//  -*- C++ -*-

//=============================================================================
/**
 *  @file       Component_Decorator_Impl.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_DEPLOYMENTSTATUSDECORATOR_IMPL_H_
#define _PICML_DEPLOYMENTSTATUSDECORATOR_IMPL_H_

#include "game/mga/decorator/Reference_Decorator.h"

/**
 * @class DeploymentStatusDecorator_Impl
 */
class DeploymentStatusDecorator_Impl :
  public GAME::Mga::Reference_Decorator
{
public:
  /// Default constructor
  DeploymentStatusDecorator_Impl (void);

  /// Destructor.
  ~DeploymentStatusDecorator_Impl (void);

  int initialize (const GAME::Mga::Project & proj,
                  const GAME::Mga::Meta::Part_in part,
                  const GAME::Mga::FCO_in fco,
                  IMgaCommonDecoratorEvents * sink,
                  ULONGLONG window);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics * g);

private:
  /// Current group for the element.
  std::string deployment_;

  /// Question bitmap for undeployed components.
  std::auto_ptr <Gdiplus::Image> question_;
};

#endif  // !defined _PICML_DEPLOYMENTSTATUSDECORATOR_IMPL_H_
