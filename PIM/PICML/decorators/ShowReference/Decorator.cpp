#include "StdAfx.h"
#include "resource.h"

#include "Decorator.h"
#include "DecoratorLib.h"
#include "game/mga/decorator/Decorator_T.h"

#include "game/mga/decorator/Decorator_Module.h"
#include "DecoratorLib_i.c"

DECLARE_DECORATOR_MODULE (LIBID_ShowReferenceDecoratorLibrary, IDR_DECORATOR, "{CDD72C3A-3340-4225-83D6-46B10E9A763E}")

DECLARE_DECORATOR (ShowReferenceDecorator, Show_Reference_Decorator_Impl);

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
