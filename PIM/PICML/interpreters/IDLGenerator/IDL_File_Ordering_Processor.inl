template <typename T>
struct is_reference
{
  static const bool result_type = false;
};

template < >
struct is_reference <GAME::Mga::reference_tag_t>
{
  static const bool result_type = true;
};

//
// add_edge
//
template <typename T, typename P>
void IDL_File_Ordering_Processor::add_edge (const GAME::Mga::Model & o)
{
  // Only process references
  if (!is_reference <T::impl_type::type_tag>::result_type)
    return;

  // We need to get all the children of the specified type from
  // this object. We are going to then iterate over each item
  // and add it to the dependency graph.
  for (auto child : o->children <T> ())
  {
    // Skip references to predefined types
    try
    {
      PICML::PredefinedType::_narrow (child->refers_to ());
      continue;
    }
    catch (GAME::Mga::Exception & e)
    {
      ACE_UNUSED_ARG (e);
    }

    GAME::Mga::FCO refers_to = child->refers_to ();
    GAME::Mga::FCO reference_parent = refers_to;
    GAME::Mga::Object parent = find_parent <P> (child);

    if (!this->same_parent_before_file (parent, reference_parent))
      reference_parent = this->parent_before_file (refers_to);

    if (!this->parent_in_same_file (parent, reference_parent))
    {
      if (this->map_.find (parent) == this->map_.end ())
      {
        this->add_vertex (parent, this->current_graph_);
      }
    }
    else if (this->map_.find (reference_parent) == this->map_.end () &&
             this->map_.find (parent) == this->map_.end ())
    {
      this->add_vertices (reference_parent, parent, this->current_graph_);
    }
    else
    {
      bool found_parent = false;
      bool found_ref_parent = false;

      VERTEX reference = this->find_vertex (reference_parent, this->current_graph_, found_ref_parent);
      VERTEX direct = this->find_vertex (parent, this->current_graph_, found_parent);

      if (found_parent && found_ref_parent)
      {
        EDGE e;
        bool added = false;

        boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
      }
      else if (!found_parent && !found_ref_parent)
      {
        this->add_vertices (reference_parent, parent, this->current_graph_);
      }
      else if (!found_parent && found_ref_parent)
      {
        this->add_vertex (parent, this->current_graph_);

        VERTEX direct = this->find_vertex (parent, this->current_graph_, found_parent);

        EDGE e;
        bool added = false;

        boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
      }
      else
      {
        this->add_vertex (reference_parent, this->current_graph_);

        VERTEX reference = this->find_vertex (reference_parent, this->current_graph_, found_ref_parent);

        EDGE e;
        bool added = false;

        boost::tie(e,added) = boost::add_edge (reference, direct, *this->current_graph_);
      }
    }
  }
}

//
// find_parent
//
template <typename T>
GAME::Mga::Object IDL_File_Ordering_Processor::
find_parent (const GAME::Mga::Object & o)
{
  GAME::Mga::Object parent;
  for (parent = o->parent (); parent->meta ()->name () != T::impl_type::metaname; parent = parent->parent ());

  return parent;
}
