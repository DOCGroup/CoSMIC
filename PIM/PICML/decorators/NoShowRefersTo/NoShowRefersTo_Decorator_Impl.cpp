// $Id$

#include "StdAfx.h"

#include "NoShowRefersTo_Decorator_Impl.h"
#include "NoShowRefersTo_Decorator.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/MetaFCO.h"
#include "game/mga/graphics/Image_Resolver.h"
#include "game/mga/utils/Registrar.h"

DECLARE_DECORATOR (NoShowRefersTo_Decorator, NoShowRefersTo_Decorator_Impl);

//
// NoShowRefersTo_Decorator_Impl
//
NoShowRefersTo_Decorator_Impl::NoShowRefersTo_Decorator_Impl (void)
: GAME::Mga::Reference_Decorator (true, false)
{

}

//
// ~NoShowRefersTo_Decorator_Impl
//
NoShowRefersTo_Decorator_Impl::~NoShowRefersTo_Decorator_Impl (void)
{

}
