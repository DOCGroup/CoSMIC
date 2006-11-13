// $Id$

#include "BE_File_Generator_Manager.h"

#if !defined (__CUTS_INLINE__)
#include "BE_File_Generator_Manager.inl"
#endif

#include "BE_Options.h"
#include "BE_File_Generator.h"
#include "BE_Method_Visitor.h"
#include "BE_Variable_Visitor.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <algorithm>
#include <sstream>

//
// CUTS_BE_File_Generator_Manager
//
CUTS_BE_File_Generator_Manager::
CUTS_BE_File_Generator_Manager (void)
{

}

//
// CUTS_BE_File_Generator_Manager
//
CUTS_BE_File_Generator_Manager::
~CUTS_BE_File_Generator_Manager (void)
{
  this->remove_all ();
}

//
// Visit_ComponentImplementationContainer
//
void CUTS_BE_File_Generator_Manager::
Visit_ComponentImplementationContainer (
  const PICML::ComponentImplementationContainer & container)
{
  // Reset all the information in this object.
  this->clear ();

  typedef std::vector <PICML::MonolithicImplementation> Monolithic_Set;
  Monolithic_Set monos = container.MonolithicImplementation_kind_children ();

  // Open all the files for writing if we know we have at least
  // one <MonolithicImplementation> in this <container>.
  if (monos.empty ())
    return;

  // Create the pathname for the file.
  std::ostringstream pathname;
  pathname << CUTS_BE_OPTIONS ()->output_directory_ << "\\" << container.name ();

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::open,
                              _1,
                              pathname.str ()));

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_preamble,
                              _1,
                              container));

  // Visit all the monolithic implementations.
  std::for_each (monos.begin (),
                 monos.end (),
                 boost::bind (&Monolithic_Set::value_type::Accept,
                              _1,
                              boost::ref (*this)));

  // Be sure to close all the open files.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_postamble,
                              _1,
                              container));

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::close,
                              _1));
}

//
// Visit_MonolithicImplementation
//
void CUTS_BE_File_Generator_Manager::
Visit_MonolithicImplementation (const PICML::MonolithicImplementation & monolithic)
{
  // Get the <Implements> connection b/t the <MonolithicImplementation>
  // and the <ComponentRef>.
  PICML::Implements implements = monolithic.dstImplements ();

  if (implements == Udm::null)
    return;

  // Get the <Component> that is being implemented.
  PICML::ComponentRef ref = implements.dstImplements_end ();
  PICML::Component component = PICML::Component::Cast (ref.ref ());

  if (component == Udm::null)
    return;

  // Preprocess the <component> and begin writing the monolithic
  // implemenation for the target <component>.
  component.Accept (this->ppd_);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_monolithic_begin,
                              _1,
                              monolithic));

  // We are now visting the component portion of the monolithic
  // implemenation.
  component.Accept (*this);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_monolithic_end,
                              _1));
}

//
// Visit_Component
//
void CUTS_BE_File_Generator_Manager::
Visit_Component (const PICML::Component & component)
{
  // Begin writing the component.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_component_begin,
                              _1,
                              component));

  // We need to remove the const specification from the <component>
  // to use it in the following operations.
  PICML::Component temp_component =
    const_cast <PICML::Component &> (component);

  // Generate all the methods for the component.
  CUTS_BE_Method_Visitor method_generator (this->generators_);
  temp_component.Accept (method_generator);

  // Generate all the variables for the component.
  CUTS_BE_Variable_Visitor variable_visitor (this->generators_);
  temp_component.Accept (variable_visitor);

  // Finish writing the component.
  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_component_end,
                              _1,
                              component));

  // Locate the factory for the component.
  PICML::ComponentFactory factory = this->get_component_factory (component);

  std::for_each (this->generators_.begin (),
                 this->generators_.end (),
                 boost::bind (&CUTS_BE_File_Generator::write_component_factory_begin,
                              _1,
                              factory,
                              component));
}

//
// remove_all
//
void CUTS_BE_File_Generator_Manager::remove_all (void)
{
  CUTS_BE_File_Generator_Set::iterator iter;

  for (iter  = this->generators_.begin ();
       iter != this->generators_.end ();
       iter ++)
  {
    delete (*iter);
  }

  this->generators_.clear ();
}

//
// clear
//
void CUTS_BE_File_Generator_Manager::clear (void)
{
  this->ppd_.clear ();
}

//
// insert
//
void CUTS_BE_File_Generator_Manager::
insert (CUTS_BE_File_Generator * generator)
{
  if (generator == 0)
    return;

  generator->init (&this->ppd_);
  this->generators_.insert (generator);
}

//
// get_component_factory
//
PICML::ComponentFactory CUTS_BE_File_Generator_Manager::
get_component_factory (const PICML::Component & component)
{
  // Try and locate the real factory for the component.
  typedef std::set <PICML::ManagesComponent> Manages_Set;
  Manages_Set manages = component.srcManagesComponent ();

  if (manages.size () > 0)
  {
    PICML::ManagesComponent manage = (*manages.begin ());
    return manage.srcManagesComponent_end ();
  }

  typedef std::set <PICML::ComponentRef> ComponentRef_Set;
  ComponentRef_Set refs = component.referedbyComponentRef ();

  PICML::MgaObject parent;
  std::string parent_type;

  for (ComponentRef_Set::iterator iter = refs.begin ();
       iter != refs.end ();
       iter ++)
  {
    parent = iter->parent ();
    parent_type = parent.type ().name ();

    if (parent_type == (std::string) PICML::File::meta.name () ||
        parent_type == (std::string) PICML::Package::meta.name ())
    {
      PICML::ComponentFactory factory =
        this->get_component_factory (iter->ref ());

      if (factory != Udm::null)
        return factory;
    }
  }

  return PICML::ComponentFactory ();
}
