// file      : xsd/cxx/tree/template-header.cxx
// author    : Sumant Tambe <http://www.dre.vanderbilt.edu/~sutambe>

#include <cxx/tree/template-header.hxx>

#include <xsd-frontend/semantic-graph.hxx>
#include <xsd-frontend/traversal.hxx>
#include <vector>

namespace CXX
{
  namespace Tree
  {
    namespace
    {
      struct Element : Traversal::Element, protected virtual Context
      {
        Element (Context& c, String const& scope_, std::vector<String> & v)
            : Context (c), scope (scope_), children_(v)
        {
        }

        virtual Void
        traverse (Type& e)
        {
          if (skip (e))
            return;

          String const& aname (eaname (e));

          children_.push_back(e.name());
          os << "template <>" << endl
             << "struct GetChildren <" << scope << ", " << e.name() << "> {";

          if (max (e) != 1)
          {
            // sequence
            //
            os << scope << "::" << e.name() << "_sequence const & operator () ("; 
          }
          else if (min (e) == 0)
          {
            // optional
            //
            os << scope << "::" << e.name() << "_optional const & operator () ("; 
          }
          else
          {
            // one
            //
            os << scope << "::" << e.name() << "_type const & operator () ("; 

          }
          os  << scope << " const & p) {" 
              << "return p." << e.name() << "();" << endl
              << "}" << endl << "};";
        }

      private:
        String scope;
        std::vector<String> & children_;
      };
      struct Complex : Traversal::Complex, protected virtual Context
      {
        Complex (Context& c)
            : Context (c), first_(false)
        {
        }

        virtual Void
        traverse (Type& c)
        {
          String name (ename (c));

          // If renamed name is empty then we do not need to generate
          // anything for this type.
          //
          if (renamed_type (c, name) && !name)
            return;

          if (!first_)
          {
            os << "template <class Parent, class Child>" << endl
               << "struct GetChildren {};";
            os << "template <class Parent>" << endl
               << "struct ST {"
               << "typedef boost::mpl::vector <> Children;"
                  "typedef ST type;"
                  "enum { value = false };};";
            first_ = true;
          }
          {
            Traversal::Names names_member;
            std::vector<String> children;
            Element element (*this, name, children);
            //Attribute attribute (*this);

            names_member >> element;
            //names_member >> attribute;

            names (c, names_member);
            print_traits(name, children);
          }

        }
        Void print_traits (String const &name, std::vector<String> const &children)
        {
          os << "// SchemaTraits" << endl
             << "template <>" << endl
             << "struct ST<" << name << "> {" << "typedef boost::mpl::vector <";
          for (std::vector<String>::const_iterator iter (children.begin());
               iter != children.end();)
          {
            os << *iter;
            if (++iter != children.end())
              os << ", ";
          }
          os << "> Children;" 
                "typedef ST type;" 
                "enum { value = true };};";
        }
        private:
          Boolean first_;
      };
    }

    Void
    generate_template_header (Context& ctx)
    {
      String c (ctx.char_type);
      ctx.os << "#include <boost/mpl/vector.hpp>" << endl << endl;

      Traversal::Schema schema;

      Traversal::Sources sources;
      Traversal::Names names_ns, names;

      Namespace ns (ctx);

      Complex complex (ctx);

      schema >> sources >> schema;
      schema >> names_ns >> ns >> names;
      
      names >> complex;

      schema.dispatch (ctx.schema_root);
    }
  }
}
