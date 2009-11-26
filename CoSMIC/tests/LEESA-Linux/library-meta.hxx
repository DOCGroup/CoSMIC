#ifndef __LIBRARY_META_HXX
#define __LIBRARY_META_HXX

#define DOMAIN_NAMESPACE library
#include "Kind_Traits.h"

#include "library.hxx"
#include <ostream>

namespace library {
 
  struct title_lang : title::lang_type {}; 
  struct person_name : person::name_type {};
  struct person_born : person::born_type {};
  struct person_died : person::died_type {};
  struct book_id : book::id_type {};
 
  struct author_name : author::name_type 
  {
    author_name() { }
    author_name(const author::name_type & x) 
      : author::name_type (x)
    { }
  };
  
  struct author_born : author::born_type
  {
    author_born() { }
    author_born(const author::born_type & x) 
      : author::born_type (x)
    { }
  };

  struct author_died : author::died_type
  {
    typedef author::died_type super;
    author_died() { }
    author_died(const super & x) 
      : super (x)
    { }
    author_died (const author_died & x, 
                 ::xml_schema::flags f = 0, 
                 ::xml_schema::container * c = 0)
      : super(x, f, c) 
    { }
    virtual author_died* _clone (::xml_schema::flags f, 
                                 ::xml_schema::container * c) const 
    {
      return new author_died(*this, f, c);
    }
  };


  struct author_recommends : author::recommends_type {};
  class book_available : public ::xml_schema::simple_type
  {
    public:
    
      explicit book_available(book::available_type x = false) 
        : val_(x) { }

      virtual book_available* _clone (::xml_schema::flags f, 
                                      ::xml_schema::container * c) const 
      {
        return new book_available(this->val_);
      }
      
      // safe-bool idiom.
      typedef void (book_available::*bool_convertible) ();
      operator bool_convertible () const
      {
        return val_ ? & book_available::true_ : 0;
      }

      friend std::ostream & operator << (std::ostream & o, 
                                         book_available const & x) 
      {
        o << x.val_;
        return o;
      }

    private:
    
      void true_(); // dummy 
      book::available_type val_;
  };
  

  // ********************* title **************************
  const ::xsd::cxx::tree::optional<title::lang_type> &
  children_kind (title const & x, title_lang); 

  // ********************** book **************************
  const book::isbn_type &
  children_kind (book const & x, book::isbn_type);
  
  const book::id_type &
  children_kind  (book const & x, book_id);
  
  const book::genre_type &
  children_kind (book const & x, book::genre_type);
  
  const book::title_type &
  children_kind (book const & x, book::title_type);
  
  const ::xsd::cxx::tree::sequence<book::author_type> &
  children_kind (book const & x, book::author_type);

  book_available
  children_kind (book const & x, book_available);

  // ************************ person *************************
  const person::name_type &
  children_kind (person const & x, person_name);
  
  const person::born_type &
  children_kind (person const & x, person_born);
  
  const ::xsd::cxx::tree::optional<person::died_type> &
  children_kind (person const & x, person_died);

  // ****************** author (inherits person) ****************
  author_name
  children_kind (author const & x, author_name);
  
  author_born
  children_kind (author const & x, author_born);
  
  ::xsd::cxx::tree::optional<author_died>
  children_kind (author const & x, author_died);

  const ::xsd::cxx::tree::optional<author::recommends_type> &
  children_kind (author const & x, author_recommends);

  // ************************ catalog *************************
  const ::xsd::cxx::tree::sequence<catalog::book_type> &
  children_kind (catalog const & x, catalog::book_type);


  template <class T>
  struct _Wrapper
  {
    typedef typename ::xsd::cxx::tree::sequence <T> Container;
    typedef typename ::xsd::cxx::tree::optional <T> Optional;
  };

  template <>
  struct SchemaTraits<title> : public _Wrapper<title> {
    typedef boost::mpl::vector < title_lang > ChildrenKinds;
    typedef boost::mpl::vector < book > ParentKinds;
    typedef LEESA::ModelMetaTag MetaKind;
  };

  template <>
  struct SchemaTraits<book> : public _Wrapper<book> {
    typedef boost::mpl::vector < isbn, book_id, genre, author, book_available > ChildrenKinds;
    typedef boost::mpl::vector < catalog > ParentKinds;
    typedef LEESA::ModelMetaTag MetaKind;
  };

  template <>
  struct SchemaTraits<person> : public _Wrapper<person> {
    typedef boost::mpl::vector < person_name, person_born, person_died > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::ModelMetaTag MetaKind;
  };

  template <>
  struct SchemaTraits<author> : public _Wrapper<author> {
    typedef boost::mpl::vector < author_name, author_born, author_died, author_recommends > ChildrenKinds;
    typedef boost::mpl::vector < book > ParentKinds;
    typedef LEESA::ModelMetaTag MetaKind;
  };

  template <>
  struct SchemaTraits<catalog> : public _Wrapper<catalog> {
    typedef boost::mpl::vector < book > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::ModelMetaTag MetaKind;
  };

  template <>
  struct SchemaTraits<title_lang> : public _Wrapper<title_lang> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 
  
  template <>
  struct SchemaTraits<person_name> : public _Wrapper<person_name> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<person_born> : public _Wrapper<person_born> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<person_died> : public _Wrapper<person_died> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 


  template <>
  struct SchemaTraits<author_name> : public _Wrapper<author_name> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<author_born> : public _Wrapper<author_born> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<author_died> : public _Wrapper<author_died> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<author_recommends> : public _Wrapper<author_recommends> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<book_id> : public _Wrapper<book_id> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 

  template <>
  struct SchemaTraits<book_available> : public _Wrapper<book_available> {
    typedef boost::mpl::vector < > ChildrenKinds;
    typedef boost::mpl::vector < > ParentKinds;
    typedef LEESA::AtomMetaTag MetaKind;
  }; 




/*
//  template <class Parent, class Child, class Result>
//  Result children_kind (Parent);

  template <class Parent, class Child>
  const typename boost::enable_if_c<false,Child>::type & 
  children_kind (Parent const &);
  
//  template <class Parent, template <typename> class _Wrapper, class Child>
//  const _Wrapper<Child> & children_kind (Parent const &);

  template <class Parent, class Child>
  const typename boost::enable_if_c<false,::xsd::cxx::tree::optional<Child> >::type & 
  children_kind (Parent const &);
  
  template <class Parent, class Child>
  const typename boost::enable_if_c<false,::xsd::cxx::tree::sequence<Child> >::type & 
  children_kind (Parent const &);


  // ********************* title **************************
  template <>
  const ::xsd::cxx::tree::optional<title::lang_type> &
  children_kind <title, title::lang_type> (title const & x); 

  // ********************** book **************************
  template <>
  const book::isbn_type &
  children_kind <book, book::isbn_type> (book const & x);
  
  template <>
  const book::id_type &
  children_kind <book, book::id_type> (book const & x);
  
  template <>
  const book::genre_type &
  children_kind <book, book::genre_type> (book const & x);
  
  template <>
  const book::title_type &
  children_kind <book, book::title_type> (book const & x);
  
  template <>
  const ::xsd::cxx::tree::sequence<book::author_type> &
  children_kind <book, book::author_type> (book const & x);

  // ************************ person *************************
  template <>
  const person::name_type &
  children_kind <person, person::name_type> (person const & x);
  
  template <>
  const person::born_type &
  children_kind <person, person::born_type> (person const & x);
  
  template <>
  const ::xsd::cxx::tree::optional<person::died_type> &
  children_kind <person, person::died_type> (person const & x);

  // ****************** author (inherits person) ****************
  template <>
  const author::name_type &
  children_kind <author, author::name_type> (author const & x);
  
  template <>
  const author::born_type &
  children_kind <author, author::born_type> (author const & x);
  
  template <>
  const ::xsd::cxx::tree::optional<author::died_type> &
  children_kind <author, author::died_type> (author const & x);

  template <>
  const ::xsd::cxx::tree::optional<author::recommends_type> &
  children_kind <author, author::recommends_type> (author const & x);

  // ************************ catalog *************************
  template <>
  const ::xsd::cxx::tree::sequence<catalog::book_type> &
  children_kind <catalog, catalog::book_type> (catalog const & x);
*/


}  // namespace library

#endif // __LIBRARY_META_HXX


