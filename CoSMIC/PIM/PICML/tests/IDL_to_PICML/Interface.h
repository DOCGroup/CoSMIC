// $Id: $

// ============================================================================
//
// = LIBRARY
//    PICML/tests/IDL_to_PICML
//
// = FILENAME
//    Interface.h
//
// = DESCRIPTION
//    This file contains the interfaces for the IDL
//    interface test cases
//
// = AUTHORS
//    Harold Owens II <owensh@cs.iupui.edu>
//
// ============================================================================

#ifndef INTERFACE_H
#define INTERFACE_H

#include "InterfaceC.h"

class MyJustANoun : public JustANoun
{
  public:
    virtual void person (const char * name){}
    virtual void place (const char * name){}
    virtual void thing (::CORBA::Long number_of){}
    virtual void idea (::CORBA::Boolean is_great){}
    virtual void event (::CORBA::Long type){}
};

class MyNounWithAttributes : public NounWithAttributes
{
  public:
    void person(const char * name){}
    void place(const char * name){}
    void thing(::CORBA::Long number_of){}
    void idea(::CORBA::Boolean is_great){}
    void event(::CORBA::Long type){}
};

class MyNounWithAttributesAndException : public NounWithAttributesAndException
{
  public:
    void person(::CORBA::Boolean is_member){}
    void place(::CORBA::Long how_many){}
    void thing(::CORBA::Boolean has_more){}
    void idea(char begin_letter){}
    void event(::CORBA::Double my_double){}
};

class MyPerson : public ModuleOfAnInterface::person
{
  public:
    void my_person(::CORBA::Boolean is_member){}
};

class MyPlace : public ModuleOfAnInterface::place
{
  public:
    void my_place(::CORBA::Long how_many){}
};

class MyThing : public ModuleOfAnInterface::thing
{
  public:
    void my_thing(::CORBA::Boolean has_more){}
};

class MyIdea : public ModuleOfAnInterface::idea
{
  public:
    void my_idea(char begin_letter){}
};

class MyEvent : public ModuleOfAnInterface::event
{
  public:
    void my_event(::CORBA::Double my_double){}
};

class MyForwardDeclarationPlace : public ForwardDeclaration::place
{
  public:
      void my_place(::CORBA::Long how_many){}
};

class MyForwardDeclarationPerson : public ForwardDeclaration::person
{
  public:
      void my_person(::CORBA::Boolean is_member){}
};

class NounWithOneWayOPIdea : public NounWithOneWayOp::idea
{
  public:
    void is_great(::CORBA::Boolean great){}
    void create_idea(){} // oneway non-blocking
};

class NounWithOneWayOPEvent : public NounWithOneWayOp::event
{
  public:
    void get_type(::CORBA::Long &type){}
    void set_type(::CORBA::Long type){}
    void create_event(){} // oneway non-blocking
};

#endif /* INTERFACE_H */