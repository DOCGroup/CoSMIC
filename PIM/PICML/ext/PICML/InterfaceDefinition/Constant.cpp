#include "StdAfx.h"
#include "Constant.h"

#if !defined (__GAME_INLINE__)
#include "Constant.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "PICML/InterfaceDefinition/TemplatePackageAlias.h"
#include "PICML/InterfaceDefinition/TemplatePackageInstance.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
#include "PICML/NamedTypes/Enum.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Constant_Impl::metaname ("Constant");

  //
  // is_abstract
  //
  const bool Constant_Impl::is_abstract = false;

  //
  // _create (const Package_in)
  //
  Constant Constant_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Constant Constant_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // _create (const HasOperations_in)
  //
  Constant Constant_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create < Constant > (parent, Constant_Impl::metaname);
  }

  //
  // accept
  //
  void Constant_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Constant (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Package
  //
  Package Constant_Impl::parent_Package (void)
  {
    return Package::_narrow (this->parent ());
  }

  //
  // parent_File
  //
  File Constant_Impl::parent_File (void)
  {
    return File::_narrow (this->parent ());
  }

  //
  // parent_HasOperations
  //
  HasOperations Constant_Impl::parent_HasOperations (void)
  {
    return HasOperations::_narrow (this->parent ());
  }

  //
  // ConstantType_is_nil
  //
  bool Constant_Impl::ConstantType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_ConstantType
  //
  void Constant_Impl::refers_to_ConstantType (ConstantType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ConstantType
  //
  ConstantType Constant_Impl::refers_to_ConstantType (void) const
  {
    return ConstantType::_narrow (this->refers_to ());
  }
}

