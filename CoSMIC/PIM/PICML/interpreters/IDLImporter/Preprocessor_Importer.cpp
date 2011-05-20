// $Id$

#include "Preprocessor_Importer.h"
#include "game/xme/Model.h"
#include "game/xme/modelgen.h"

#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/support_istream_iterator.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"
#include "boost/fusion/include/adapt_struct.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_fusion.hpp"
#include "boost/spirit/include/phoenix_stl.hpp"
#include "boost/spirit/include/phoenix_object.hpp"

#include "boost/bind.hpp"

#include <fstream>
#include <stack>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

///////////////////////////////////////////////////////////////////////////////
// Preprocessor_Importer_Grammar

namespace data
{
  struct ident2_t
  {
    std::string ident1_;
    std::string ident2_;
  };

  struct keylist_t
  {
    std::string ident_;
    std::vector <std::string> list_;
  };

  typedef std::vector <std::string> scope_t;
}

BOOST_FUSION_ADAPT_STRUCT (
  data::ident2_t,
  (std::string, ident1_)
  (std::string, ident2_)
);

BOOST_FUSION_ADAPT_STRUCT (
  data::keylist_t,
  (std::string, ident_)
  (std::vector <std::string>, list_)
);

/**
 * @struct PathParser
 *
 * Boost grammar for parsing identifiers.
 */
template <typename IteratorT>
struct Preprocessor_Importer_Grammar :
  qi::grammar <IteratorT, void (), ascii::space_type>
{
public:
  typedef std::stack <GAME::XME::Model> model_stack_t;

  struct open_module
  {
    open_module (model_stack_t & s)
      : stack_ (s)
    {

    }

    void operator () (const std::string & name, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Model;
      using GAME::Xme_t;

      Model child;
      Model model = this->stack_.top ();
      static const GAME::Xml::String meta_Package ("Package");

      if (GAME::find <Xme_t> (model, meta_Package, child,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       name,
                       boost::bind (&Model::name, _1))))
      {
        this->stack_.push (child);
      }

      // We should really abort the operation since we did not
      // find the target module...
    }

  private:
    model_stack_t & stack_;
  };

  struct close_module
  {
    close_module (model_stack_t & s)
      : stack_ (s)
    {

    }

    void operator () (qi::unused_type, qi::unused_type, qi::unused_type) const
    {
      this->stack_.pop ();
    }

  private:
    model_stack_t & stack_;
  };

  struct append_typesupport_directive
  {
    append_typesupport_directive (GAME::XME::Model & file)
      : file_ (file)
    {

    }

    void operator () (const data::ident2_t & val, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Attribute;

      // Locate the PrePreprocessorDirectives attribute for the file.
      Attribute attr = this->file_.attribute (constants::attrs::PrePreprocessorDirectives, true);
      GAME::Xml::String curr_value (attr.value (), false);

      //// Let's make sure the is an eol at the end of the statement.
      std::string append_value ("#pragma ");
      append_value += val.ident1_ + " typesupport " + val.ident2_ + "\n";

      // Append this statement to the current value and save it back
      // to the model.
      curr_value.append (GAME::Xml::String (append_value));
      attr.value (curr_value);
    }

  private:
    GAME::XME::Model & file_;
  };

  struct append_lem_directive
  {
    append_lem_directive (GAME::XME::Model & file)
      : file_ (file)
    {

    }

    void operator () (const data::ident2_t & val, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Attribute;

      // Locate the PrePreprocessorDirectives attribute for the file.
      Attribute attr = this->file_.attribute (constants::attrs::PrePreprocessorDirectives, true);
      GAME::Xml::String curr_value (attr.value (), false);

      //// Let's make sure the is an eol at the end of the statement.
      std::string append_value ("#pragma ");
      append_value += val.ident1_ + " lem " + val.ident2_ + "\n";

      // Append this statement to the current value and save it back
      // to the model.
      curr_value.append (GAME::Xml::String (append_value));
      attr.value (curr_value);
    }

  private:
    GAME::XME::Model & file_;
  };

  /**
   * @struct append_dcps_data_type
   *
   * Functor for associating the #pragma DCPS_DATA_TYPE statement with
   * an event/aggregate.
   */
  struct append_dcps_data_type
  {
    append_dcps_data_type (const model_stack_t & stack)
      : stack_ (stack)
    {

    }

    void operator () (const std::string & ident, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Model;
      using GAME::Xme_t;

      // Locate the Aggregate in the current scope that has the
      // name identified in <val>.
      Model model = this->stack_.top ();

      static const GAME::Xml::String meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find <Xme_t> (model, meta_Aggregate, aggregate,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (ident),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        // This is a signal for use to create a Key element.
        Atom key;
        static const GAME::Xml::String meta_Key ("Key");

        if (GAME::create_if_not <Xme_t> (aggregate, meta_Key, key,
            GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                         GAME::Xml::String (meta_Key),
                                         boost::bind (&Atom::kind, _1)))))
        {
          key.name (meta_Key);
        }
      }
    }

  private:
    const model_stack_t & stack_;
  };

  /**
   * @struct append_dcps_data_key
   *
   * Functor for associating the #pragma DCPS_DATA_KEY statement with
   * an event/aggregate.
   */
  struct append_dcps_data_key
  {
    append_dcps_data_key (const model_stack_t & stack)
      : stack_ (stack)
    {

    }

    void operator () (const data::ident2_t & val, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Model;
      using GAME::Xme_t;

      // Locate the Aggregate in the current scope that has the
      // name identified in <val>.
      Model model = this->stack_.top ();

      // Locate the struct that we are about to update.
      static const GAME::Xml::String meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find <Xme_t> (model, meta_Aggregate, aggregate,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (val.ident1_),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        static const GAME::Xml::String meta_Key ("Key");
        static const GAME::Xml::String meta_Member ("Member");
        static const GAME::Xml::String meta_KeyMember ("KeyMember");

        Atom key;

        // Make sure the key element exists, and retrieve it.
        if (GAME::create_if_not <Xme_t> (aggregate, meta_Key, key,
            GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                         GAME::Xml::String (meta_Key),
                                         boost::bind (&Atom::kind, _1)))))
        {
          key.name (meta_Key);
        }

        // Locate the Member element in the aggregate.
        using GAME::XME::FCO;
        FCO member;

        if (GAME::find <Xme_t> (aggregate, meta_Member, member,
            boost::bind (std::equal_to < GAME::Xml::String > (),
                         GAME::Xml::String (val.ident2_),
                         boost::bind (&FCO::name, _1))))
        {
          // Make sure there is a connection between the key
          // and the member.
          using GAME::XME::Connection;
          Connection key_member;

          if (!GAME::find <Xme_t> (aggregate, meta_KeyMember, key_member,
               boost::bind (std::logical_and <bool> (),
                            boost::bind (std::equal_to <FCO> (),
                                         key,
                                         boost::bind (&Connection::src, _1)),
                            boost::bind (std::equal_to <FCO> (),
                                         member,
                                         boost::bind (&Connection::dst, _1)))))
          {
            Connection::_create (aggregate, meta_KeyMember, key, member);
          }
        }
      }
    }

  private:
    const model_stack_t & stack_;
  };

  /**
   * @struct append_dcps_data_key
   *
   * Functor for associating the #pragma DCPS_DATA_KEY statement with
   * an event/aggregate.
   */
  struct append_keylist
  {
    append_keylist (const model_stack_t & stack)
      : stack_ (stack)
    {

    }

    void operator () (const data::keylist_t & keylist, qi::unused_type, qi::unused_type) const
    {
      using GAME::XME::Model;
      using GAME::Xme_t;

      // Locate the Aggregate in the current scope that has the
      // name identified in <val>.
      Model model = this->stack_.top ();

      static const GAME::Xml::String meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find <Xme_t> (model, meta_Aggregate, aggregate,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (keylist.ident_),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        // We are going to add a key element to this aggregate. This does
        // not necessarily mean there are members of the key.
        Atom key;
        static const GAME::Xml::String meta_Key ("Key");

        if (GAME::create_if_not <Xme_t> (aggregate, meta_Key, key,
            GAME::contains <Xme_t> (boost::bind (std::equal_to < GAME::Xml::String > (),
                                         GAME::Xml::String (meta_Key),
                                         boost::bind (&Atom::kind, _1)))))
        {
          key.name (meta_Key);
        }

        std::vector <std::string>::const_iterator
          iter = keylist.list_.begin (),
          iter_end = keylist.list_.end ();

        for (; iter != iter_end; ++ iter)
        {
          // Locate the Member element in the aggregate.
          using GAME::XME::FCO;
          FCO member;

          static const GAME::Xml::String meta_Member ("Member");

          if (GAME::find <Xme_t> (aggregate, meta_Member, member,
              boost::bind (std::equal_to < GAME::Xml::String > (),
                           GAME::Xml::String (*iter),
                           boost::bind (&FCO::name, _1))))
          {
            // Make sure there is a connection between the key
            // and the member.
            using GAME::XME::Connection;
            Connection key_member;

            static const GAME::Xml::String meta_KeyMember ("KeyMember");

            if (!GAME::find <Xme_t> (aggregate, meta_KeyMember, key_member,
                 boost::bind (std::logical_and <bool> (),
                              boost::bind (std::equal_to <FCO> (),
                                           key,
                                           boost::bind (&Connection::src, _1)),
                              boost::bind (std::equal_to <FCO> (),
                                           member,
                                           boost::bind (&Connection::dst, _1)))))
            {
              Connection::_create (aggregate, meta_KeyMember, key, member);
            }
          }
        }
      }
    }

  private:
    const model_stack_t & stack_;
  };

  /**
   * @struct enable_ami4ccm_interface
   */
  struct enable_ami4ccm_interface_t
  {
    enable_ami4ccm_interface_t (const GAME::XME::Model & file)
      : file_ (file)
    {

    }

    void operator () (const data::scope_t & fq_type, qi::unused_type, qi::unused_type) const
    {
      using GAME::Xme_t;

      data::scope_t::const_iterator
        iter = fq_type.begin (), iter_end = fq_type.end () - 1;

      GAME::XME::Model parent (this->file_);

      for (; iter != iter_end; ++ iter)
      {
        static const GAME::Xml::String meta_Package ("Package");

        // Locate the Package with this name.
        if (!GAME::find <Xme_t> (parent, meta_Package, parent,
            boost::bind (std::equal_to < GAME::Xml::String > (),
                         GAME::Xml::String (*iter),
                         boost::bind (&GAME::XME::Model::name, _1))))
        {
          return;
        }
      }

      // The final location is the parent. We now need to locate the
      // object in this parent that has the specified name.
      GAME::XME::Model object;
      static const GAME::Xml::String meta_Object ("Object");

      if (GAME::find <Xme_t> (parent, meta_Object, object,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (*iter),
                       boost::bind (&GAME::XME::Model::name, _1))))
      {
        static const GAME::Xml::String attr_SupportsAsync ("SupportsAsync");
        object.attribute (attr_SupportsAsync, true).value (true);
      }
    }

  private:
    const GAME::XME::Model & file_;
  };

  struct enable_ami4ccm_receptacle_t
  {
    enable_ami4ccm_receptacle_t (GAME::XME::Model & file)
      : file_ (file)
    {

    }

    void operator () (const data::scope_t & fq_type, qi::unused_type, qi::unused_type) const
    {
      using GAME::Xme_t;

      data::scope_t::const_iterator
        iter = fq_type.begin (), iter_end = fq_type.end () - 2;

      GAME::XME::Model parent (this->file_);

      for (; iter != iter_end; ++ iter)
      {
        static const GAME::Xml::String meta_Package ("Package");

        // Locate the Package with this name.
        if (!GAME::find <Xme_t> (parent, meta_Package, parent,
            boost::bind (std::equal_to < GAME::Xml::String > (),
                         GAME::Xml::String (*iter),
                         boost::bind (&GAME::XME::Model::name, _1))))
        {
          return;
        }
      }

      // The next location is the component. We now need to locate
      // the object in this parent that has the specified name.
      GAME::XME::Model component;
      static const GAME::Xml::String meta_Object ("Component");

      if (!GAME::find <Xme_t> (parent, meta_Object, component,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (*iter ++),
                       boost::bind (&GAME::XME::Model::name, _1))))
      {
        return;
      }

      // The final location is the receptacle. We now need to locate
      // the object in this parent that has the specified name.
      GAME::XME::Reference receptacle;
      static const GAME::Xml::String meta_RequiredRequestPort ("RequiredRequestPort");

      if (GAME::find <Xme_t> (component, meta_RequiredRequestPort, receptacle,
          boost::bind (std::equal_to < GAME::Xml::String > (),
                       GAME::Xml::String (*iter),
                       boost::bind (&GAME::XME::Reference::name, _1))))
      {
        static const GAME::Xml::String attr_AsyncCommunication ("AsyncCommunication");
        receptacle.attribute (attr_AsyncCommunication, true).value (true);
      }
    }

  private:
    GAME::XME::Model & file_;
  };

  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  Preprocessor_Importer_Grammar (GAME::XME::Model & file, bool debug = false)
    : Preprocessor_Importer_Grammar::base_type (this->file_content_),
      file_ (file),
      file_content_ (std::string ("file_content")),
      module_ (std::string ("module")),
      ignorable_scope_ (std::string ("ignorable_scope")),
      ignorable_scope_keyword_ (std::string ("ignorable_scope_keyword")),
      module_content_ (std::string ("module_content")),
      pragma_stmts_ (std::string ("pragma_stmts")),
      pragma_lem_ (std::string ("pragma_lem")),
      pragma_typesupport_ (std::string ("pragma_typesupport")),
      pragma_dcps_data_type_ (std::string ("pragma_dcps_data_type")),
      pragma_dcps_data_key_ (std::string ("pragma_dcps_data_key")),
      pragma_keylist_ (std::string ("pragma_keylist")),
      garbage_ (std::string ("garbage")),
      keywords_ (std::string ("keywords")),
      quoted_string_ (std::string ("quoted_string")),
      filepath_ (std::string ("filepath")),
      usr_filepath_ (std::string ("usr_filepath")),
      sys_filepath_ (std::string ("sys_filepath")),
      ident_ (std::string ("ident")),
      pragma_ami4ccm_interface_ (std::string ("pragma_ami4ccm_interface")),
      pragma_ami4ccm_receptacle_ (std::string ("pragma_ami4ccm_receptacle")),
      pragma_ami4ccm_idl_ (std::string ("pragma_ami4ccm_idl"))
  {
    namespace phoenix = boost::phoenix;
    namespace repo = boost::spirit::repository;

    using phoenix::push_back;

    // This is the first object on the stack.
    this->model_stack_.push (file);

    this->file_content_ =
      * (this->pragma_ |
         this->module_ |
         this->ignorable_scope_ |
         this->garbage_);

    // We need to set the structure as the active model.
    this->module_ =
      qi::lit ("module") >> this->ident_[open_module (this->model_stack_)] >>
      qi::lit ('{') >>
      *this->module_content_ >>
      qi::lit ('}') >>
      qi::lit (';')[close_module (this->model_stack_)];

    this->module_content_ =
      this->module_ |
      this->ignorable_scope_ |
      this->pragma_ |
      this->garbage_;

    // List of keyworks that we must be able to recognize. This will
    // stop the parser from gobbling unused characters.
    this->keywords_ =
      qi::lit ("#pragma") |
      qi::lit ("module") |
      this->ignorable_scope_keyword_;

    this->pragma_ =
      qi::lit ("#pragma") >> this->pragma_stmts_;

    // Rules for recognizing #pragma statements in the code.
    this->pragma_stmts_ =
      this->pragma_typesupport_ |
      this->pragma_lem_ |
      this->pragma_dcps_data_type_[append_dcps_data_type (this->model_stack_)] |
      this->pragma_dcps_data_key_[append_dcps_data_key (this->model_stack_)] |
      this->pragma_keylist_[append_keylist (this->model_stack_)] |
      this->pragma_ami4ccm_receptacle_[enable_ami4ccm_receptacle_t (file)] |
      this->pragma_ami4ccm_interface_[enable_ami4ccm_interface_t (file)] |
      this->pragma_ami4ccm_idl_;

    this->pragma_typesupport_ %=
      this->ident_ >>
      qi::lit ("typesupport") >>
      this->usr_filepath_;

    this->pragma_lem_ %=
      this->ident_ >>
      qi::lit ("lem") >>
      this->usr_filepath_;

    this->pragma_dcps_data_type_ %=
      qi::lit ("DCPS_DATA_TYPE") >>
      qi::lit ("\"") >>
      this->ident_ >>
      qi::lit ("\"");

    this->pragma_ami4ccm_interface_ %=
      qi::lit ("ciao") >>
      qi::lit ("ami4ccm") >>
      qi::lit ("interface") >>
      qi::lit ("\"") >>
      this->scoped_name_ >>
      qi::lit ("\"");

    this->pragma_ami4ccm_receptacle_ %=
      qi::lit ("ciao") >>
      qi::lit ("ami4ccm") >>
      qi::lit ("receptacle") >>
      qi::lit ("\"") >>
      this->scoped_name_ >>
      qi::lit ("\"");

    this->pragma_ami4ccm_idl_ %=
      qi::lit ("ciao") >>
      qi::lit ("ami4ccm") >>
      qi::lit ("idl") >>
      this->usr_filepath_;

    this->pragma_dcps_data_key_ %=
      qi::lit ("DCPS_DATA_KEY") >>
      qi::lit ("\"") >>
      this->ident_ >>
      this->ident_ >>
      qi::lit ("\"");

    this->pragma_keylist_ %=
      qi::lit ("keylist") >>
      qi::lexeme[
        qi::skip[this->ident_] >>
          *(qi::omit[+ascii::blank] >> qi::skip[this->ident_]) >>
          qi::omit[*ascii::blank] >> qi::eol];

    // The actual value of the string literal.
    this->quoted_string_ %=
      qi::lit ('"') >> *(ascii::char_ - '"') >> qi::lit ('"');

    // The text that we can skip.
    this->garbage_ = +(ascii::char_ - (this->keywords_ | '}'));

    // Rule definition for parsing identifiers.
    this->ident_ %= qi::lexeme [(qi::alpha >> *(qi::alnum | '_'))];

    this->ignorable_scope_ =
      this->ignorable_scope_keyword_ >> this->ident_ >>
      qi::lit ('{') >> this->garbage_ >>
      qi::lit ('}') >> qi::lit (';');

    this->ignorable_scope_keyword_ =
      qi::lit ("eventtype") |
      qi::lit ("valuetype") |
      qi::lit ("connector") |
      qi::lit ("component") |
      qi::lit ("switch") |
      qi::lit ("struct") |
      qi::lit ("interface") |
      qi::lit ("enum");

    this->scoped_name_ =
      qi::omit[-qi::lit ("::")] >>
      this->ident_[push_back (qi::labels::_val, qi::labels::_1)]  >>
      * (qi::lit ("::") >> this->ident_[push_back (qi::labels::_val, qi::labels::_1)]);

    this->filepath_ %=
      this->usr_filepath_ |
      this->sys_filepath_;

    this->usr_filepath_ %=
      qi::lexeme[ascii::char_ ("\"") >> *(ascii::print - "\"") >> ascii::char_ ("\"")];

    this->sys_filepath_ %=
      qi::lexeme[ascii::char_ ("<") >> *(ascii::print - "\"") >> ascii::char_ (">")];

    if (debug)
      this->enable_debugging ();
  }

private:
  void enable_debugging (void)
  {
    debug (this->file_content_);
    debug (this->module_);
    debug (this->ignorable_scope_);
    debug (this->ignorable_scope_keyword_);
    debug (this->pragma_stmts_);
    debug (this->pragma_typesupport_);
    debug (this->pragma_lem_);
    debug (this->pragma_dcps_data_type_);
    debug (this->pragma_dcps_data_key_);
    debug (this->pragma_keylist_);
    debug (this->garbage_);
    debug (this->keywords_);
    debug (this->quoted_string_);
    debug (this->filepath_);
    debug (this->usr_filepath_);
    debug (this->sys_filepath_);
    debug (this->filename_);
    debug (this->ident_);
    debug (this->pragma_ami4ccm_receptacle_);
    debug (this->pragma_ami4ccm_interface_);
    debug (this->pragma_ami4ccm_idl_);
  }

  GAME::XME::Model & file_;

  model_stack_t model_stack_;

  qi::rule <IteratorT, void (), ascii::space_type> file_content_;

  qi::rule <IteratorT, void (), ascii::space_type> module_;

  qi::rule <IteratorT, void (), ascii::space_type> ignorable_scope_;
  qi::rule <IteratorT, void (), ascii::space_type> ignorable_scope_keyword_;

  qi::rule <IteratorT, void (), ascii::space_type> module_content_;

  qi::rule <IteratorT, void (), ascii::space_type> pragma_;
  qi::rule <IteratorT, void (), ascii::space_type> pragma_stmts_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_typesupport_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_lem_;

  qi::rule <IteratorT, data::scope_t (), ascii::space_type> pragma_ami4ccm_receptacle_;
  qi::rule <IteratorT, data::scope_t (), ascii::space_type> pragma_ami4ccm_interface_;
  qi::rule <IteratorT, std::string (), ascii::space_type> pragma_ami4ccm_idl_;

  qi::rule <IteratorT, std::string (), ascii::space_type> pragma_dcps_data_type_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_dcps_data_key_;
  qi::rule <IteratorT, data::keylist_t (), ascii::space_type> pragma_keylist_;

  qi::rule <IteratorT, void (), ascii::space_type> garbage_;

  qi::rule <IteratorT, void (), ascii::space_type> keywords_;

  qi::rule <IteratorT, std::string (), ascii::space_type> quoted_string_;

  qi::rule <IteratorT, std::string (), ascii::space_type> filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> usr_filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> sys_filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> filename_;

  qi::rule <IteratorT,
            data::scope_t (),
            ascii::space_type> scoped_name_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            ident_;
};

///////////////////////////////////////////////////////////////////////////////
// Preprocessor_Importer

//
// Preprocessor_Importer
//
Preprocessor_Importer::Preprocessor_Importer (void)
{

}

//
// ~Preprocessor_Importer
//
Preprocessor_Importer::~Preprocessor_Importer (void)
{

}

//
// parse
//
bool Preprocessor_Importer::
parse (const char * filename, GAME::XME::Model & model, bool debug)
{
  // Open the specified file for reading.
  std::ifstream infile;
  infile.open (filename);

  if (!infile.is_open ())
    return false;

  namespace spirit = boost::spirit;

  // Adapt the iterator to support Boost backtracking.
  infile.unsetf (std::ios::skipws);
  spirit::istream_iterator begin_iter (infile);
  spirit::istream_iterator end_iter;

  // Parse the open file using the iterators above.
  Preprocessor_Importer_Grammar <spirit::istream_iterator> g (model, debug);
  bool retval = qi::phrase_parse (begin_iter,
                                  end_iter,
                                  g,
                                  ascii::space);

  // Close the file before exiting.
  infile.close ();

  return retval;
}
