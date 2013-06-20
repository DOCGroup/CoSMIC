// $Id$

#include "stdafx.h"
#include "Errors.h"

#if !defined (__GAME_INLINE__)
#include "Errors.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// init
//
void Errors::init (void)
{
  this->errors_.bind (E_MGA_NOT_IMPLEMENTED, "method not implemented");
  this->errors_.bind (E_MGA_NOT_SUPPORTED, "operation not supported");

  this->errors_.bind (E_MGA_MODULE_INCOMPATIBILITY, "module incompatibility");
  this->errors_.bind (E_MGA_PARADIGM_NOTREG, "paradigm is not registered");
  this->errors_.bind (E_MGA_PARADIGM_INVALID, "invalid paradigm");
  this->errors_.bind (E_MGA_COMPONENT_ERROR, "some addons not loaded/initialized");

  this->errors_.bind (E_MGA_DATA_INCONSISTENCY, "inconsistent data in database");
  this->errors_.bind (E_MGA_META_INCOMPATIBILITY, "meta incompatibility");

  this->errors_.bind (E_MGA_PROJECT_OPEN, "project already open");
  this->errors_.bind (E_MGA_PROJECT_NOT_OPEN, "project is not open");
  this->errors_.bind (E_MGA_READ_ONLY_ACCESS, "project is read-only");
  this->errors_.bind (E_MGA_NOT_IN_TERRITORY, "object unknown in territory");
  this->errors_.bind (E_MGA_NOT_IN_TRANSACTION, "project not in transaction");
  this->errors_.bind (E_MGA_ALREADY_IN_TRANSACTION, "project already in transaction");
  this->errors_.bind (E_MGA_MUST_ABORT, "transaction must abort");
  this->errors_.bind (E_MGA_TARGET_DESTROYED, "target already destroyed");
  this->errors_.bind (E_MGA_FOREIGN_PROJECT, "not the callee object's project");
  this->errors_.bind (E_MGA_FOREIGN_OBJECT, "object does not belong to this project");

  this->errors_.bind (E_MGA_OBJECT_DELETED, "object is deleted");
  this->errors_.bind (E_MGA_OBJECT_ZOMBIE, "object is a zombie");
  this->errors_.bind (E_MGA_ZOMBIE_NOPROJECT, "object's project is destroyed");
  this->errors_.bind (E_MGA_ZOMBIE_CLOSED_PROJECT, "object's project is closed");

  this->errors_.bind (E_MGA_INVALID_ARG, "invalid argument");
  this->errors_.bind (E_MGA_ARG_RANGE, "argument out of range");
  this->errors_.bind (E_MGA_INPTR_NULL, "null input COM pointer");
  this->errors_.bind (E_MGA_OUTPTR_NONEMPTY, "non-empty output COM pointer");
  this->errors_.bind (E_MGA_OUTPTR_NULL, "null output COM pointer");

  this->errors_.bind (E_MGA_NAME_NOT_FOUND, "name not found");
  this->errors_.bind (E_MGA_NAME_DUPLICATE, "duplicate name");
  this->errors_.bind (E_MGA_META_VIOLATION, "meta violation");
  this->errors_.bind (E_MGA_NOT_CHANGEABLE, "object is unchangeable");
  this->errors_.bind (E_MGA_OP_REFUSED, "operation refused");
  this->errors_.bind (E_MGA_LIBOBJECT, "object is a library object");

  this->errors_.bind (E_META_INVALIDATTR, "unknown attribute");
  this->errors_.bind (E_META_INVALIDASPECT, "unknown aspect");
  this->errors_.bind (E_MGA_ACCESS_TYPE, "access method conflicts with attribute type");
  this->errors_.bind (E_MGA_BAD_ENUMVALUE, "invalid enumeration value");

  this->errors_.bind (E_MGA_REFPORTS_USED, "reference is used for connections");
  this->errors_.bind (E_MGA_VIRTUAL_NODE, "node is virtual");
  this->errors_.bind (E_MGA_BAD_POSITIONVALUE, "bad position value");
  this->errors_.bind (E_MGA_ROOTFCO, "operation not allowed on root FCOs");
  this->errors_.bind (E_MGA_NOT_ROOTOBJECT, "operation not allowed on non-root FCOs");
  this->errors_.bind (E_MGA_BAD_COLLENGTH, "bad collection length");
  this->errors_.bind (E_MGA_INVALID_ROLE, "invalid role or part");
  this->errors_.bind (E_MGA_BAD_ID, "invalid object id format");
  this->errors_.bind (E_MGA_NOT_DERIVABLE, "object is not derivable");
  this->errors_.bind (E_MGA_OBJECT_NOT_MEMBER, "object is not a member");
  this->errors_.bind (E_MGA_NOT_CONNECTIBLE, "object is not connectible");
  this->errors_.bind (E_MGA_NO_ROLE, "role not specified");
  this->errors_.bind (E_MGA_CONNROLE_USED, "exceeded connection role limit");
  this->errors_.bind (E_MGA_NOT_DERIVED, "object is not derived");
  this->errors_.bind (E_MGA_NOT_INSTANCE, "object is not an instance");
  this->errors_.bind (E_MGA_INSTANCE, "object is a type");
  this->errors_.bind (E_MGA_REFERENCE_EXPECTED, "object is not a reference");
  this->errors_.bind (E_MGA_FILTERFORMAT, "invalid filter format");
  this->errors_.bind (E_MGA_GEN_OUT_OF_SPACE, "cannot generate unique value");
  this->errors_.bind (E_MGA_INVALID_TARGET, "invalid reference target");
  this->errors_.bind (E_MGA_LONG_DERIVCHAIN, "derive chain too long");
  this->errors_.bind (E_MGA_LIB_DIFF, "invalid library changes");

  this->errors_.bind (E_MGA_BAD_MASKVALUE, "invalid event mask value");
  this->errors_.bind (E_MGA_CONSTRAINT_VIOLATION, "constraint violation");

  this->errors_.bind (E_MGA_ERRCODE_ERROR, "error code out of range");
}

//
// lookup
//
void Errors::lookup (size_t error_code, std::string & msg) const
{
  if (0 != this->errors_.find (error_code, msg))
    msg = std::string ("unknown error code");
}

}
}
