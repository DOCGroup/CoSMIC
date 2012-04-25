// $Id$

#include "stdafx.h"
#include "Mga.h"

#include "Object.h"

#if !defined (__GAME_INLINE__)
#include "Object.inl"
#endif

#include "Collection_T.h"
#include "Exception.h"
#include "MetaBase.h"
#include "Project.h"
#include "Visitor.h"
#include <stack>
#include <sstream>

namespace GAME
{
namespace Mga
{

//
// status
//
long Object_Impl::status (void) const
{
  long status;
  VERIFY_HRESULT (this->object_->get_Status (&status));

  return status;
}

//
// id
//
std::string Object_Impl::id (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_ID (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// relative_id
//
long Object_Impl::relative_id (void) const
{
  long relid;
  VERIFY_HRESULT (this->object_->get_RelID (&relid));

  return relid;
}

//
// relative_id
//
void Object_Impl::relative_id (long relid)
{
  VERIFY_HRESULT (this->object_->put_RelID (relid));
}

//
// is_writable
//
bool Object_Impl::is_writable (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_IsWritable (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// is_lib_object
//
bool Object_Impl::is_lib_object (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_IsLibObject (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// name
//
std::string Object_Impl::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_Name (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// name
//
void Object_Impl::name (const std::string & name)
{
  CComBSTR bstr (name.c_str ());
  VERIFY_HRESULT (this->object_->put_Name (bstr));
}

//
// absolute_path
//
std::string Object_Impl::absolute_path (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_AbsPath (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// check
//
void Object_Impl::check (void)
{
  VERIFY_HRESULT (this->object_->Check ());
}

//
// check_tree
//
void Object_Impl::check_tree (void)
{
  VERIFY_HRESULT (this->object_->CheckTree ());
}

//
// exempt
//
bool Object_Impl::exempt (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_Exempt (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// exempt
//
void Object_Impl::exempt (bool exempt)
{
  VARIANT_BOOL status = exempt ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->object_->put_Exempt (status));
}

//
// readonly_access
//
void Object_Impl::readonly_access (bool readonly, bool propagate)
{
  // Convert the parameter.
  VARIANT_BOOL temp_readonly = readonly ? VARIANT_TRUE : VARIANT_FALSE;

  if (!propagate)
  {
    VERIFY_HRESULT (this->object_->PutReadOnlyAccess (temp_readonly));
  }
  else
  {
    VERIFY_HRESULT (this->object_->PutReadOnlyAccessWithPropagate (temp_readonly));
  }
}

//
// readonly_access
//
bool Object_Impl::readonly_access (void) const
{
  VARIANT_BOOL temp_readonly;

  VERIFY_HRESULT (this->object_->HasReadOnlyAccess (&temp_readonly));
  return temp_readonly == VARIANT_TRUE ? true : false;
}

//
// meta
//
Meta::Base Object_Impl::meta (void) const
{
  CComPtr <IMgaMetaBase> meta;
  VERIFY_HRESULT (this->impl ()->get_MetaBase (&meta));

  return meta.p;
}

//
// is_equal_to
//
GAME_INLINE
bool Object_Impl::is_equal_to (const Object_in obj) const
{
  if (this == obj)
    return true;

  VARIANT_BOOL result;
  VERIFY_HRESULT (this->object_->get_IsEqual (obj->impl (), &result));
  return result == VARIANT_TRUE ? true : false;
}

//
// objectinterface_type
//
objtype_enum Object_Impl::type (void) const
{
  objtype_enum type;
  VERIFY_HRESULT (this->object_->get_ObjType (&type));

  return type;
}

//
// parent
//
Object Object_Impl::parent (void) const
{
  CComPtr <IMgaObject> obj;
  VERIFY_HRESULT (this->object_->GetParent (&obj, 0));

  return obj.p;
}

//
// path
//
std::string Object_Impl::
path (const std::string & separator, bool leading_separator) const
{
  // Place each of the parents onto the stack until we
  // reach the root element.
  std::stack <Object> stack_trace;
  Object parent (this->parent ());

  while (!parent.is_nil ())
  {
    stack_trace.push (parent);
    parent = parent->parent ();
  }

  // Pop all the element from the stack while adding their
  // name to the path string. This will allow us to easily
  // construct the path of the element.
  std::ostringstream pathstr;

  // Write the first element, which could be the only one.
  if (leading_separator)
    pathstr << separator;

  if (!stack_trace.empty ())
  {
    // Prep the path string with the top element in the stack.
    // After the first element, we will insert a seperator between
    // each element on the stack.
    pathstr << stack_trace.top ()->name ();
    stack_trace.pop ();

    while (!stack_trace.empty ())
    {
      // Get the next name on top of the stack.
      pathstr << separator << stack_trace.top ()->name ();

      // Remove the element from the top.
      stack_trace.pop ();
    }
  }

  // Finally, add the name of this object to the path.
  pathstr << separator << this->name ();

  return pathstr.str ();
}

//
// destroy
//
void Object_Impl::destroy (void)
{
  VERIFY_HRESULT (this->object_->DestroyObject ());
  this->object_.Release ();
}

//
// find_object_by_path
//
Object Object_Impl::find_object_by_path (const std::string & path) const
{
  CComPtr <IMgaObject> obj;
  CComBSTR bstr (path.c_str ());

  VERIFY_HRESULT (this->object_->get_ObjectByPath (bstr, &obj));

  return obj.p;
}

//
// children
//
size_t Object_Impl::children (std::vector <Object> & children) const
{
  switch (this->type ())
  {
  case OBJTYPE_FOLDER:
  case OBJTYPE_MODEL:
    {
      CComPtr <IMgaObjects> temp;
      VERIFY_HRESULT (this->object_->get_ChildObjects (&temp));

      return iter_to_collection (temp.p, children);
    }
    break;

  default:
    children.clear ();
    break;
  }

  return children.size ();
}

//
// project
//
Project Object_Impl::project (void) const
{
  CComPtr <IMgaProject> proj;
  VERIFY_HRESULT (this->object_->get_Project (&proj));

  return proj.p;
}

//
// child_by_relative_id
//
Object Object_Impl::child_by_relative_id (long relid)
{
  CComPtr <IMgaObject> object;
  VERIFY_HRESULT (this->impl ()->get_ChildObjectByRelID (relid, &object));

  // TODO Use factory to create the concrete implementation.
  return object.p;
}

}
}
