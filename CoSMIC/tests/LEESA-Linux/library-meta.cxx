#include "library-meta.hxx"

namespace library {

  // ********************* title **************************
  const ::xsd::cxx::tree::optional<title::lang_type> &
  children_kind (title const & x, title_lang) {
    return x.lang();
  }

  // ********************** book **************************
  const book::isbn_type &
  children_kind (book const & x, book::isbn_type) {
    return x.isbn();
  }
  
  const book::id_type &
  children_kind  (book const & x, book_id) {
    return x.id();
  }
  
  const book::genre_type &
  children_kind (book const & x, book::genre_type) {
    return x.genre();
  }
  
  const book::title_type &
  children_kind (book const & x, book::title_type) {
    return x.title();
  }
  
  const ::xsd::cxx::tree::sequence<book::author_type> &
  children_kind (book const & x, book::author_type) {
    return x.author();
  }

  book_available
  children_kind (book const & x, book_available) {
    return book_available(x.available());
  }

  // ************************ person *************************
  const person::name_type &
  children_kind (person const & x, person_name) {
    return x.name();
  }
  
  const person::born_type &
  children_kind (person const & x, person_born) {
    return x.born();
  }
  
  const ::xsd::cxx::tree::optional<person::died_type> &
  children_kind (person const & x, person_died) {
    return x.died();
  }
  // ****************** author (inherits person) ****************
  author_name
  children_kind (author const & x, author_name) {
    return author_name(x.name());
  }
  
  author_born
  children_kind (author const & x, author_born) {
    return author_born(x.born());
  }
  
  ::xsd::cxx::tree::optional<author_died>
  children_kind (author const & x, author_died) {
    if (x.died()) {
      return ::xsd::cxx::tree::optional<author_died>(x.died().get());
    }
    else {
      return ::xsd::cxx::tree::optional<author_died>();
    }
  }

  const ::xsd::cxx::tree::optional<author::recommends_type> &
  children_kind (author const & x, author_recommends) {
    return x.recommends();
  }

  // ************************ catalog *************************
  const catalog::book_sequence &
  children_kind (catalog const & x, catalog::book_type) {
    return x.book();
  }
  
  
  /*
  // ********************* title **************************
  template <>
  const ::xsd::cxx::tree::optional<title::lang_type> &
  children_kind <title, title::lang_type> (title const & x) {
    return x.lang();
  } 

  // ********************** book **************************
  template <>
  const book::isbn_type &
  children_kind <book, book::isbn_type> (book const & x) {
    return x.isbn();
  }
  
  template <>
  const book::id_type &
  children_kind <book, book::id_type> (book const & x) {
    return x.id();
  }
  
  template <>
  const book::genre_type &
  children_kind <book, book::genre_type> (book const & x) {
    return x.genre();
  }
  
  template <>
  const book::title_type &
  children_kind <book, book::title_type> (book const & x) {
    return x.title();
  }
  
  template <>
  const ::xsd::cxx::tree::sequence<book::author_type> &
  children_kind <book, book::author_type> (book const & x) {
    return x.author();
  }

  // ************************ person *************************
  template <>
  const person::name_type &
  children_kind <person, person::name_type> (person const & x) {
    return x.name();
  }
  
  template <>
  const person::born_type &
  children_kind <person, person::born_type> (person const & x) {
    return x.born();
  }
  
  template <>
  const ::xsd::cxx::tree::optional<person::died_type> &
  children_kind <person, person::died_type> (person const & x) {
    return x.died();
  }

  // ****************** author (inherits person) ****************
  template <>
  const author::name_type &
  children_kind <author, author::name_type> (author const & x) {
    return x.name();
  }
  
  template <>
  const author::born_type &
  children_kind <author, author::born_type> (author const & x) {
    return x.born();
  }
  
  template <>
  const ::xsd::cxx::tree::optional<author::died_type> &
  children_kind <author, author::died_type> (author const & x) {
    return x.died();
  }

  template <>
  const ::xsd::cxx::tree::optional<author::recommends_type> &
  children_kind <author, author::recommends_type> (author const & x) {
    return x.recommends();
  }

  // ************************ catalog *************************
  template <>
  const ::xsd::cxx::tree::sequence<catalog::book_type> &
  children_kind <catalog, catalog::book_type> (catalog const & x) {
    return x.book();
  }

*/

} // namespace library

