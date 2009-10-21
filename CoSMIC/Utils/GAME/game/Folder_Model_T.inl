// -*- C++ -*-
// $Id$

namespace GME
{
//
// Folder_Model_T
//
template <typename T, typename BASE>
GME_INLINE
Folder_Model_T <T, BASE>::Folder_Model_T (void)

{

}

//
// Folder_Model_T
//
template <typename T, typename BASE>
GME_INLINE
Folder_Model_T <T, BASE>::Folder_Model_T (T * type)
: BASE (type)
{

}

//
// Folder_Model_T
//
template <typename T, typename BASE>
GME_INLINE
Folder_Model_T <T, BASE>::
Folder_Model_T (const Folder_Model_T & type)
: BASE (type)
{

}

//
// Folder_Model_T
//
template <typename T, typename BASE>
GME_INLINE
Folder_Model_T <T, BASE>::~Folder_Model_T (void)
{

}

//
// attach
//
template <typename T, typename BASE>
GME_INLINE
void Folder_Model_T <T, BASE>::attach (T * type)
{
  BASE::attach (type);
}
}
