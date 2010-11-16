// $Id$

#include "ID_Generator_Repo.h"

#if !defined (__GAME_INLINE__)
#include "ID_Generator_Repo.inl"
#endif

#include "GME_ID_Generator.h"
#include "ace/CORBA_macros.h"
#include "ace/Auto_Ptr.h"

//
// operator ()
//
unsigned long ACE_Hash <xercesc::DOMDocument *>::
operator () (xercesc::DOMDocument * ptr) const
{
  return static_cast <unsigned long> (reinterpret_cast <uintptr_t> (ptr));
}

namespace GAME
{
namespace XME
{

//
// open
//
int ID_Generator_Repo::open (xercesc::DOMDocument * proj)
{
  if (this->idgens_.find (proj) == 0)
    return 0;

  // Create a new id generator.
  GME_ID_Generator * idgen = 0;
  ACE_NEW_THROW_EX (idgen, GME_ID_Generator (proj), ACE_bad_alloc ());
  ACE_Auto_Ptr <GME_ID_Generator> auto_clean (idgen);

  // Store it in the map, or use the existing one.
  int retval = this->idgens_.trybind (proj, idgen);

  if (retval == 0)
    auto_clean.release ();

  return retval;
}

//
// close
//
void ID_Generator_Repo::close (xercesc::DOMDocument * proj)
{
  // Remove the element and delete it.
  GME_ID_Generator * idgen = 0;

  if (0 == this->idgens_.unbind (proj, idgen) && 0 != idgen)
    delete idgen;
}

//
// get
//
GME_ID_Generator * ID_Generator_Repo::get (xercesc::DOMDocument * proj)
{
  GME_ID_Generator * idgen = 0;

  this->idgens_.find (proj, idgen);
  return idgen;
}

}
}
