#ifndef _EXPORT_IMPL_H_
#define _EXPORT_IMPL_H_

#include "export.hpp"

template <typename IteratorT>
idl_export <IteratorT>::idl_export (void)
: base_type (idl_export_)
{
  this->idl_export_ =
    (this->type_decl_ (qi::_r1) >> ";") |
    (this->const_decl_ (qi::_r1) >> ";") |
    (this->except_decl_ (qi::_r1) >> ";") |
    (this->attr_decl_ (qi::_r1)  >> ";") |
    (this->op_decl_ (qi::_r1) >> ";");
    //(this->type_id_decl_ (qi::_r1)  >> ";") |
    //(this->type_prefix_decl_ (qi::_r1)  >> ";");
}

#endif
