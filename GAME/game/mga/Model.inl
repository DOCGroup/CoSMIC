// -*- C++ -*-
// $Id$


namespace GAME
{
namespace Mga
{

//
// Model_Impl
//
GAME_INLINE
Model_Impl::Model_Impl (void)
{

}

//
// Model_Impl
//
GAME_INLINE
Model_Impl::Model_Impl (IMgaModel * model)
{
  this->object_ = model;
}

//
// ~Model_Impl
//
GAME_INLINE
Model_Impl::~Model_Impl (void)
{

}

}
}
