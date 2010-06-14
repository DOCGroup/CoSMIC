// $Id$

#include "Preprocessor_Importer.h"
#include "game/xme/Model.h"
#include "game/utils/modelgen.h"

#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/include/support_istream_iterator.hpp" 
#include "boost/spirit/repository/include/qi_confix.hpp"
#include "boost/fusion/include/adapt_struct.hpp"
#include "boost/bind.hpp"

#include <fstream>
#include <stack>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

///////////////////////////////////////////////////////////////////////////////
// Preprocessor_Importer_Grammar

namespace constants
{
namespace attrs
{
  static const ::Utils::XStr PrePreprocessorDirectives ("PrePreprocessorDirectives");
  static const ::Utils::XStr PostPreprocessorDirectives ("PostPreprocessorDirectives");
}
};

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

      Model child;
      Model model = this->stack_.top ();
      static const ::Utils::XStr meta_Package ("Package");

      if (GAME::find (model, meta_Package, child, 
          boost::bind (std::equal_to <::Utils::XStr> (),
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
      ::Utils::XStr curr_value (attr.value (), false);

      //// Let's make sure the is an eol at the end of the statement.
      std::string append_value ("#pragma ");
      append_value += val.ident1_ + " typesupport " + val.ident2_ + "\n";

      // Append this statement to the current value and save it back
      // to the model.
      curr_value.append (::Utils::XStr (append_value));
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
      ::Utils::XStr curr_value (attr.value (), false);

      //// Let's make sure the is an eol at the end of the statement.
      std::string append_value ("#pragma ");
      append_value += val.ident1_ + " lem " + val.ident2_ + "\n";

      // Append this statement to the current value and save it back
      // to the model.
      curr_value.append (::Utils::XStr (append_value));
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

      // Locate the Aggregate in the current scope that has the 
      // name identified in <val>.
      Model model = this->stack_.top ();

      static const ::Utils::XStr meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find (model, meta_Aggregate, aggregate, 
          boost::bind (std::equal_to <::Utils::XStr> (),
                       ::Utils::XStr (ident),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        // This is a signal for use to create a Key element.
        Atom key;
        static const ::Utils::XStr meta_Key ("Key");

        if (GAME::create_if_not (aggregate, meta_Key, key,
            GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                         ::Utils::XStr (meta_Key),
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

      // Locate the Aggregate in the current scope that has the 
      // name identified in <val>.
      Model model = this->stack_.top ();

      // Locate the struct that we are about to update.
      static const ::Utils::XStr meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find (model, meta_Aggregate, aggregate, 
          boost::bind (std::equal_to <::Utils::XStr> (),
                       ::Utils::XStr (val.ident1_),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        static const ::Utils::XStr meta_Key ("Key");
        static const ::Utils::XStr meta_Member ("Member");
        static const ::Utils::XStr meta_KeyMember ("KeyMember");

        Atom key;

        // Make sure the key element exists, and retrieve it.
        if (GAME::create_if_not (aggregate, meta_Key, key,
            GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                         ::Utils::XStr (meta_Key),
                                         boost::bind (&Atom::kind, _1)))))
        {
          key.name (meta_Key);
        }

        // Locate the Member element in the aggregate.
        using GAME::XME::FCO;
        FCO member;

        if (GAME::find (aggregate, meta_Member, member, 
            boost::bind (std::equal_to <::Utils::XStr> (),
                         ::Utils::XStr (val.ident2_),
                         boost::bind (&FCO::name, _1))))
        {
          // Make sure there is a connection between the key 
          // and the member.
          using GAME::XME::Connection;
          Connection key_member;

          if (!GAME::find (aggregate, meta_KeyMember, key_member,
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

      // Locate the Aggregate in the current scope that has the 
      // name identified in <val>.
      Model model = this->stack_.top ();

      static const ::Utils::XStr meta_Aggregate ("Aggregate");
      Model aggregate;

      if (GAME::find (model, meta_Aggregate, aggregate, 
          boost::bind (std::equal_to <::Utils::XStr> (),
                       ::Utils::XStr (keylist.ident_),
                       boost::bind (&Model::name, _1))))
      {
        using GAME::XME::Atom;

        // This is a signal for use to create a Key element.
        Atom key;
        static const ::Utils::XStr meta_Key ("Key");

        if (GAME::create_if_not (aggregate, meta_Key, key,
            GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                                         ::Utils::XStr (meta_Key),
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

          static const ::Utils::XStr meta_Member ("Member");

          if (GAME::find (aggregate, meta_Member, member, 
              boost::bind (std::equal_to <::Utils::XStr> (),
                           ::Utils::XStr (*iter),
                           boost::bind (&FCO::name, _1))))
          {
            // Make sure there is a connection between the key 
            // and the member.
            using GAME::XME::Connection;
            Connection key_member;

            static const ::Utils::XStr meta_KeyMember ("KeyMember");

            if (!GAME::find (aggregate, meta_KeyMember, key_member,
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



  /// Type definition of the iterator type.
  typedef IteratorT iterator_type;

  Preprocessor_Importer_Grammar (GAME::XME::Model & file)
    : Preprocessor_Importer_Grammar::base_type (this->file_content_),
      file_ (file),
      file_content_ (std::string ("file_content")),
      garbage_ (std::string ("garbage")),
      pragma_stmts_ (std::string ("pragma_stmts")),
      module_ (std::string ("module")),
      module_content_ (std::string ("module_content")),
      keywords_ (std::string ("keywords")),
      pragma_typesupport_ (std::string ("pragma_typesupport")),
      ident_ (std::string ("ident")),
      ignorable_scope_ (std::string ("ignorable_scope")),
      ignorable_scope_keyword_ (std::string ("ignorable_scope_keyword")),
      quoted_string_ (std::string ("quoted_string")),
      filepath_ (std::string ("filepath")),
      usr_filepath_ (std::string ("usr_filepath")),
      sys_filepath_ (std::string ("sys_filepath")),
      pragma_dcps_data_type_ (std::string ("pragma_dcps_data_type")),
      pragma_dcps_data_key_ (std::string ("pragma_dcps_data_key")),
      pragma_keylist_ (std::string ("pragma_keylist"))
  {
    namespace repo = boost::spirit::repository;

    // This is the first object on the stack.
    this->model_stack_.push (file);

    this->file_content_ =
      * (this->pragma_stmts_ |
         this->module_ |
         this->ignorable_scope_ |
         this->garbage_);

    // We need to set the structure as the active model.
    this->module_ =
      qi::lit ("module") >> this->ident_[open_module (this->model_stack_)] >>
      qi::lit ('{') >> *this->module_content_ >>
      qi::lit ('}') >>
      qi::lit (';')[close_module (this->model_stack_)];

    this->module_content_ =
      this->module_ |
      this->ignorable_scope_ |
      this->garbage_;

    // List of keyworks that we must be able to recognize. This will
    // stop the parser from gobbling unused characters.
    this->keywords_ = 
      qi::lit ("#pragma") | 
      qi::lit ("module");

    // Rules for recognizing #pragma statements in the code.
    this->pragma_stmts_ =
      this->pragma_typesupport_/*[append_typesupport_directive (this->file_)]*/ |
      this->pragma_lem_/*[append_lem_directive (this->file_)]*/ |
      this->pragma_dcps_data_type_[append_dcps_data_type (this->model_stack_)] |
      this->pragma_dcps_data_key_[append_dcps_data_key (this->model_stack_)] |
      this->pragma_keylist_[append_keylist (this->model_stack_)];

    this->pragma_typesupport_ %=
      qi::lit ("#pragma") >>
      this->ident_ >> 
      qi::lit ("typesupport") >> 
      this->usr_filepath_;

    this->pragma_lem_ %=
      qi::lit ("#pragma") >>
      this->ident_ >> 
      qi::lit ("lem") >> 
      this->usr_filepath_;

    this->pragma_dcps_data_type_ %=
      qi::lit ("#pragma") >>
      qi::lit ("DCPS_DATA_TYPE") >>
      qi::lit ("\"") >>
      this->ident_ >>
      qi::lit ("\"");

    this->pragma_dcps_data_key_ %=
      qi::lit ("#pragma") >>
      qi::lit ("DCPS_DATA_KEY") >>
      qi::lit ("\"") >>
      this->ident_ >>
      this->ident_ >>
      qi::lit ("\"");

    this->pragma_keylist_ %=
      qi::lit ("#pragma") >>
      qi::lit ("keylist") >>
      this->ident_ >> +this->ident_;

    // The parsers below are for parsing C/C++ style comments.
    this->comment_ =
      this->comment_c_ | this->comment_cpp_;

    this->comment_cpp_ =
      qi::lexeme[qi::lit ("//") >> *(qi::print - qi::eol) >> qi::omit[qi::eol]];

    this->comment_c_ = 
      qi::lexeme[repo::confix ("/*", "*/")[*(ascii::char_ - "*/")]];

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

    this->filepath_ %= 
      this->usr_filepath_ | 
      this->sys_filepath_;

    this->usr_filepath_ %= 
      qi::lexeme[ascii::char_ ("\"") >> *(ascii::print - "\"") >> ascii::char_ ("\"")];

    this->sys_filepath_ %= 
      qi::lexeme[ascii::char_ ("<") >> *(ascii::print - "\"") >> ascii::char_ (">")];

    debug (file_content_);
    debug (module_);
    debug (module_content_);
    debug (garbage_);
    debug (ignorable_scope_);
    debug (ignorable_scope_keyword_);
    debug (ident_);
    debug (pragma_stmts_);
    debug (pragma_typesupport_);
    debug (pragma_keylist_);
    debug (filepath_);
    debug (usr_filepath_);
    debug (sys_filepath_);
  }

private:
  GAME::XME::Model & file_;

  model_stack_t model_stack_;

  qi::rule <IteratorT, void (), ascii::space_type> file_content_;

  qi::rule <IteratorT, void (), ascii::space_type> module_;

  qi::rule <IteratorT, void (), ascii::space_type> ignorable_scope_;
  qi::rule <IteratorT, void (), ascii::space_type> ignorable_scope_keyword_;

  qi::rule <IteratorT, void (), ascii::space_type> module_content_;

  qi::rule <IteratorT, void (), ascii::space_type> pragma_stmts_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_typesupport_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_lem_;
  qi::rule <IteratorT, std::string (), ascii::space_type> pragma_dcps_data_type_;
  qi::rule <IteratorT, data::ident2_t (), ascii::space_type> pragma_dcps_data_key_;
  qi::rule <IteratorT, data::keylist_t (), ascii::space_type> pragma_keylist_;

  qi::rule <IteratorT, void (), ascii::space_type> comment_;
  qi::rule <IteratorT, void (), ascii::space_type> comment_cpp_;
  qi::rule <IteratorT, void (), ascii::space_type> comment_c_;

  qi::rule <IteratorT, void (), ascii::space_type> garbage_;

  qi::rule <IteratorT, void (), ascii::space_type> keywords_;

  qi::rule <IteratorT, std::string (), ascii::space_type> quoted_string_;

  qi::rule <IteratorT, std::string (), ascii::space_type> filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> usr_filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> sys_filepath_;
  qi::rule <IteratorT, std::string (), ascii::space_type> filename_;

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
parse (const char * filename, GAME::XME::Model & model)
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
  Preprocessor_Importer_Grammar <spirit::istream_iterator> g (model);
  bool retval = qi::phrase_parse (begin_iter, 
                                  end_iter, 
                                  g, 
                                  ascii::space);

  // Close the file before exiting.
  infile.close ();

  return retval;
}