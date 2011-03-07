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

#include "game/mga/decorator/Decorator_T.h"
#include "game/mga/decorator/Decorator_Impl.h"

/**
 * @class ConnectorInstance_Decorator_Impl
 */
class ConnectorInstance_Decorator_Impl :
  public GAME::Mga::Decorator_Impl
{
public:
  /// Default constructor
  ConnectorInstance_Decorator_Impl (void);

  /// Destructor.
  ~ConnectorInstance_Decorator_Impl (void);

  int initialize (const GAME::Mga::Project & proj,
                  const GAME::Mga::Meta::Part_in part,
                  const GAME::Mga::FCO_in fco);

  int initialize_ex (const GAME::Mga::Project & proj,
                     const GAME::Mga::Meta::Part_in part,
                     const GAME::Mga::FCO_in fco,
                     IMgaCommonDecoratorEvents * eventSink,
                     ULONGLONG parentWnd);

  int get_preferred_size (long & sx, long & sy);

  /// Draw the component. This will draw the component's ports
  /// and the components label.
  int draw (Gdiplus::Graphics * g);

protected:
  /// The label for the element.
  std::string label_;

  /// The implementation label.
  std::string impl_label_;

  /// The bitmap for the connector.
  std::auto_ptr <Gdiplus::Bitmap> bitmap_;
};

#endif  // !defined _PORT_LAYOUT_DECORATOR_IMPL_H_
