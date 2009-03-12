// $Id$

#include "stdafx.h"
#include "Object.h"
#include "Exception.h"
#include "MetaBase.h"
#include "Project.h"
#include <stack>
#include <sstream>

namespace GME
{
//
// Object
//
Object::Object (void)
{

}

//
// Object
//
Object::Object (IMgaObject * object)
: object_ (object)
{

}
//
// Object
//
Object::Object (const Object & obj)
: object_ (obj.object_)
{

}

//
// ~Object
//
Object::~Object (void)
{

}

//
// status
//
long Object::status (void) const
{
  long status;
  VERIFY_HRESULT (this->object_->get_Status (&status));

  return status;
}

//
// id
//
std::string Object::id (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_ID (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// relative_id
//
long Object::relative_id (void) const
{
  long relid;
  VERIFY_HRESULT (this->object_->get_RelID (&relid));

  return relid;
}

//
// relative_id
//
void Object::relative_id (long relid)
{
  VERIFY_HRESULT (this->object_->put_RelID (relid));
}

//
// is_writable
//
bool Object::is_writable (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_IsWritable (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// is_lib_object
//
bool Object::is_lib_object (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_IsLibObject (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// name
//
std::string Object::name (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_Name (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// name
//
void Object::name (const std::string & name)
{
  CComBSTR bstr (name.c_str ());
  VERIFY_HRESULT (this->object_->put_Name (bstr));
}

//
// absolute_path
//
std::string Object::absolute_path (void) const
{
  CComBSTR bstr;
  VERIFY_HRESULT (this->object_->get_AbsPath (&bstr));

  CW2A tempstr (bstr);
  return tempstr.m_psz;
}

//
// check
//
void Object::check (void)
{
  VERIFY_HRESULT (this->object_->Check ());
}

//
// check_tree
//
void Object::check_tree (void)
{
  VERIFY_HRESULT (this->object_->CheckTree ());
}

//
// exempt
//
bool Object::exempt (void) const
{
  VARIANT_BOOL status;
  VERIFY_HRESULT (this->object_->get_Exempt (&status));

  return status == VARIANT_TRUE ? true : false;
}

//
// exempt
//
void Object::exempt (bool exempt)
{
  VARIANT_BOOL status = exempt ? VARIANT_TRUE : VARIANT_FALSE;
  VERIFY_HRESULT (this->object_->put_Exempt (status));
}

//
// readonly_access
//
void Object::readonly_access (bool readonly, bool propagate)
{
  // Convert the parameter.
  VARIANT_BOOL temp_readonly =
    readonly ? VARIANT_TRUE : VARIANT_FALSE;

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
bool Object::readonly_access (void) const
{
  VARIANT_BOOL temp_readonly;

  VERIFY_HRESULT (this->object_->HasReadOnlyAccess (&temp_readonly));
  return temp_readonly == VARIANT_TRUE ? true : false;
}

//
// meta
//
Meta::Base Object::meta (void) const
{
  CComPtr <IMgaMetaBase> meta;
  VERIFY_HRESULT (this->impl ()->get_MetaBase (&meta));

  return Meta::Base (meta);
}

//
// objectinterface_type
//
objtype_enum Object::type (void) const
{
  objtype_enum type;
  VERIFY_HRESULT (this->object_->get_ObjType (&type));

  return type;
}

//
// operator bool
//
Object::operator bool (void)
{
  return this->object_.p != 0;
}

//
// parent
//
Object Object::parent (void) const
{
  Object object;
  VERIFY_HRESULT (this->object_->GetParent (&object.object_, 0));

  return object;
}

//
// attach
//
void Object::attach (IMgaObject * object)
{
  this->object_.Attach (object);
}

//
// operator =
//
const Object & Object::operator = (const Object & object)
{
  if (this != &object)
    this->object_ = object.object_;

  return *this;
}

//
// path
//
std::string Object::path (const std::string & separator,
                          bool leading_separator) const
{
  // Store the *this object on the bottom of the stack.
  std::stack <Object> stack_trace;
  stack_trace.push (*this);

  // Place each of the parents onto the stack until we
  // reach the root element.
  Object parent = this->parent ();

  while (parent)
  {
    stack_trace.push (parent);
    parent = parent.parent ();
  }

  // Pop all the element from the stack while adding their
  // name to the path string. This will allow us to easily
  // construct the path of the element.
  std::ostringstream pathstr;

  // Write the first element, which could be the only one.
  if (leading_separator)
    pathstr << separator;

  std::string name = stack_trace.top ().name ();

  if (!name.empty ())
    pathstr << name;
  else
    pathstr << "<noname>";

  stack_trace.pop ();

  while (!stack_trace.empty ())
  {
    name = stack_trace.top ().name ();

    pathstr << separator;

    if (!name.empty ())
      pathstr << name;
    else
      pathstr << "<noname>";

    stack_trace.pop ();
  }

  /// @todo Allow an optional trailing separator.
  return pathstr.str ();
}

//
// destroy
//
void Object::destroy (void)
{
  VERIFY_HRESULT (this->object_->DestroyObject ());
  this->object_.Release ();
}

//
// impl
//
IMgaObject * Object::impl (void) const
{
  return this->object_.p;
}

//
// operator ==
//
bool Object::operator == (const Object & obj)
{
  return this->equals (obj);
}

//
// operator !=
//
bool Object::operator != (const Object & obj)
{
  return !this->equals (obj);
}

//
// is_nil
//
bool Object::is_nil (void) const
{
  return this->object_.p == 0;
}

//
// find_object_by_path
//
GME::Object Object::
find_object_by_path (const std::string & path) const
{
  CComPtr <IMgaObject> object;
  CComBSTR bstr (path.c_str ());

  VERIFY_HRESULT (this->object_->get_ObjectByPath (bstr, &object));
  return object.p;
}

//
// children
//
size_t Object::
children (GME::Collection_T <GME::Object> & children) const
{
  switch (this->type ())
  {
  case OBJTYPE_FOLDER:
  case OBJTYPE_MODEL:
    {
      CComPtr <IMgaObjects> temp;
      VERIFY_HRESULT (this->object_->get_ChildObjects (&temp));

      children.attach (temp.Detach ());
    }
    break;

  default:
    children.clear ();
    break;
  }

  return children.size ();
}

//
// release
//
void Object::release (void)
{
  this->object_.Release ();
}

//
// project
//
GME::Project Object::project (void) const
{
  CComPtr <IMgaProject> proj;
  VERIFY_HRESULT (this->object_->get_Project (&proj));

  return proj.p;
}

//
// project
//
bool Object::equals (const GME::Object & obj) const
{
  VARIANT_BOOL equal;
  VERIFY_HRESULT (this->impl ()->get_IsEqual (obj.object_, &equal));

  return equal == VARIANT_TRUE ? true : false;
}

//
// child_by_relative_id
//
GME::Object Object::child_by_relative_id (long relid)
{
  CComPtr <IMgaObject> object;
  VERIFY_HRESULT (this->impl ()->get_ChildObjectByRelID (relid, &object));

  return object.p;
}

//
// operator <
//
bool Object::operator < (const GME::Object & obj) const
{
  return this->object_.p < obj.object_.p;
}

//
// operator >
//
bool Object::operator > (const GME::Object & obj) const
{
  return this->object_.p > obj.object_.p;
}


}