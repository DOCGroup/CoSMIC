//  -*- C++ -*-

//=============================================================================
/**
 *  @file       ConnectorInstance_Decorator_Impl.h
 *
 *  $Id$
 *
 *  @author     James H. Hill
 */
//=============================================================================

#ifndef _PICML_CONNECTOR_INSTANCE_DECORATOR_IMPL_H_
#define _PICML_CONNECTOR_INSTANCE_DECORATOR_IMPL_H_

#include "game/mga/decorator/FCO_Decorator.h"

/**
 * @class ConnectorInstance_Decorator_Impl
 */
class ConnectorInstance_Decorator_Impl :
  public GAME::Mga::FCO_Decorator
{
public:
  /// Default constructor
  ConnectorInstance_Decorator_Impl (void);

  /// Destructor.
  virtual ~ConnectorInstance_Decorator_Impl (void);

  virtual int initialize (const GAME::Mga::Project & proj,
                          const GAME::Mga::Meta::Part_in part,
                          const GAME::Mga::FCO_in fco,
                          IMgaCommonDecoratorEvents * sink,
                          ULONGLONG window);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  virtual int draw (Gdiplus::Graphics * g);

protected:
  /// The implementation label.
  std::string impl_label_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
