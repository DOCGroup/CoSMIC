// $Id$

#include "BE_Options.h"
#include "BE_Preprocessor.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <sstream>
#include <fstream>

//
// CUTS_BE_Workspace_Generator_T
//
template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
CUTS_BE_Workspace_Generator_T <WORKSPACE_STRATEGY, PROJ_STRATEGY>::
CUTS_BE_Workspace_Generator_T (void)
{

}

//
// ~CUTS_BE_Workspace_Generator_T
//
template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
CUTS_BE_Workspace_Generator_T <WORKSPACE_STRATEGY, PROJ_STRATEGY>::
~CUTS_BE_Workspace_Generator_T (void)
{

}

//
// generate
//
template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
bool CUTS_BE_Workspace_Generator_T <WORKSPACE_STRATEGY, PROJ_STRATEGY>::generate (void)
{
  // We are writing all the implementation projects.
  std::for_each (
    CUTS_BE_PREPROCESSOR ()->impls ().graph ().begin (),
    CUTS_BE_PREPROCESSOR ()->impls ().graph ().end (),
    boost::bind (&CUTS_BE_Workspace_Generator_T::generate_impl_project,
                 this,
                 boost::bind (&CUTS_BE_Impl_Graph::Node_Map::value_type::second,
                              _1)));

  // We are writing all the stub projects.
  std::for_each (
    this->required_stubs_.begin (),
    this->required_stubs_.end (),
    boost::bind (&CUTS_BE_Workspace_Generator_T::generate_stub_project,
                 this,
                 _1));

  if (!this->workspace_generator_.open_workspace_file ())
    return false;

  // Write the prologue.
  this->workspace_generator_.write_prologue ();

  // Write all the valid project files.
  std::for_each (this->project_files_.begin (),
                 this->project_files_.end (),
                 boost::bind (&WORKSPACE_STRATEGY::write_project_file,
                              boost::ref (this->workspace_generator_),
                              _1));

  // Write the epilogue.
  this->workspace_generator_.write_epilogue ();

  // Close the workspace file.
  this->workspace_generator_.close_workspace_file ();
  return true;
}

//
// write_impl_project
//
template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
void CUTS_BE_Workspace_Generator_T <WORKSPACE_STRATEGY, PROJ_STRATEGY>::
generate_impl_project (const CUTS_BE_Impl_Node * node)
{
  // Generate the implementation project. We need to make sure that we
  // recognize if the impl is a proxy or executor. It would be easier
  // if we recognize it ourselves at this level and tell the generator
  // which type of project to generate (i.e., exec or proxy).
  if (this->proj_generator_.write_exec_project (*node))
  {
    std::string filename =
      node->name_ + CUTS_BE_OPTIONS ()->exec_suffix_;

    this->project_files_.insert (filename);
  }

  // Now, we need to add all the stubs for this implementation to the
  // collection of <required_stubs_>. We will iterate over this collection
  // once we have finished all the implementation projects.
  std::for_each (node->references_.begin (),
                 node->references_.end (),
                 boost::bind (&IDL_Node_Set::insert,
                              boost::ref (this->required_stubs_),
                              _1));
}

//
// write_stub_project
//
template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
void CUTS_BE_Workspace_Generator_T <WORKSPACE_STRATEGY, PROJ_STRATEGY>::
generate_stub_project (const CUTS_BE_IDL_Node * node)
{
  // Locate the node in the <visited_nodes_> before we continue
  // process. The main idea is to only process nodes that we
  // haven't seen yet.
  IDL_Node_Set::const_iterator iter = this->visited_nodes_.find (node);

  if (iter == this->visited_nodes_.end ())
  {
    // Insert the node into the collection.
    this->visited_nodes_.insert (node);

    // Generate the project for the stub.
    if (this->proj_generator_.write_stub_project (*node))
    {
      std::string filename = node->name_ + "_stub";
      this->project_files_.insert (filename);
    }

    // Generate all the project for this stub references.
    std::for_each (
      node->references_.begin (),
      node->references_.end (),
      boost::bind (&CUTS_BE_Workspace_Generator_T::generate_stub_project,
                   this,
                   _1));
  }
}
