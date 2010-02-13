#ifndef _IDL_ACTORS_HPP_
#define _IDL_ACTORS_HPP_

#include "boost/config/warning_disable.hpp"
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_stl.hpp"

namespace qi = ::boost::spirit::qi;
namespace fusion = ::boost::fusion;

struct create_embedded_type
{
  create_embedded_type (const char * type)
    : type_ (type)
  {

  }

  struct exists
  {
    bool operator () (const GME::Object & ) const
    {
      return true;
    }
  };

  template <typename Context>
  void operator () (qi::unused_type, Context & ctx, bool & result) const
  {
    try
    {
      // Get this object from the context.
      T3::Auto_Model & parent = fusion::at_c <0> (ctx.attributes);

      // Create the return type in *this* object.
      GME::Object object =
        T3_RUNTIME_ENGINE->create_element_if_not (parent.model (),
                                                  this->type_,
                                                  exists ());

      // Since we know its the name, let's set the name.
      object.name (this->type_);
      result = true;
    }
    catch (...)
    {
      result = false;
    }
  }

private:
  const char * type_;
};

#endif  // !defined
