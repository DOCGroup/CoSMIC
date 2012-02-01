// $Id$

//
// add_edge
//
template <typename T, typename P>
void IDL_File_Ordering_Processor::add_edge (const Udm::Object & o)
{
  // We need to get all the children of the specified type from
  // this object. We are going to then iterate over each item
  // and add it to the dependency graph.
  typedef vector <T> VECTOR;
  typedef vector <T>::const_iterator ITER;

  VECTOR children = Udm::ChildrenAttr <T> (o.__impl (), Udm::NULLCHILDROLE);

  for (ITER it = children.begin (); it != children.end (); ++ it)
  {
    // Get the object that is refered to by this reference. There is not
    // need to continue if this is a null reference.
    Udm::Object refobj = it->getReferencedObject ();

    if (refobj == Udm::null)
      continue;

    if (it->type () == T::meta && !(Udm::IsDerivedFrom (refobj.type (), PICML::PredefinedType::meta)))
    {
      Udm::Object reference_parent = refobj;
      Udm::Object parent = find_parent<P> ((*it));

      if (!this->same_parent_before_file (parent, reference_parent))
        reference_parent = this->parent_before_file (refobj);

      if (!this->parent_in_same_file (parent, reference_parent))
      {
        if (this->map_.find (parent) == this->map_.end ())
          this->add_vertex (parent, this->current_graph_);
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
}

//
// find_parent
//
template <typename T>
Udm::Object IDL_File_Ordering_Processor::
find_parent (const Udm::Object & o)
{
  Udm::Object parent;
  for (parent = o.GetParent (); parent.type () != T::meta; parent = parent.GetParent ());

  return parent;
}
