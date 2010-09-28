// $Id$

//
// add_edge
//
template <typename T, typename P>
void IDL_File_Ordering_Processor::
add_edge (const Udm::Object & o)
{
  typedef vector <T> VECTOR;
  typedef vector <T>::const_iterator ITER;
  
  VECTOR children = Udm::ChildrenAttr <T> (o.__impl (), Udm::NULLCHILDROLE);

  for (ITER it=children.begin (); it!=children.end (); ++it)
  { 
    if ((*it).getReferencedObject () == Udm::null)
      continue;
    
    if (((*it).type () == T::meta) && (Udm::IsDerivedFrom ((*it).getReferencedObject ().type (), PICML::PredefinedType::meta) == false))
    {
      Udm::Object reference_parent = (*it).getReferencedObject ();
      Udm::Object parent = find_parent<P> ((*it));
      
      if (this->same_parent_before_file (parent, reference_parent) == false)
        reference_parent = this->parent_before_file ((*it).getReferencedObject ());
      
      if (this->map_.find (reference_parent) == this->map_.end () && this->map_.find (parent) == this->map_.end ())
      {
        this->add_vertices (reference_parent, parent, this->current_graph_);
      }
      else
      {
        bool found_parent = false;
        bool found_ref_parent = false;
        
        VERTEX reference = find_vertex (reference_parent, this->current_graph_, found_ref_parent);
        VERTEX direct = find_vertex (parent, this->current_graph_, found_parent);
        
        if (found_parent == true && found_ref_parent == true)
        {
          boost::add_edge (reference, direct, *this->current_graph_);
        }
        else if (found_parent == false && found_ref_parent == false)
        {
          this->add_vertices (reference_parent, parent, this->current_graph_);
        }
        else if (found_parent == false && found_ref_parent == true)
        {
          this->add_vertex (parent, this->current_graph_);
          
          VERTEX direct = find_vertex (parent, this->current_graph_, found_parent);
          boost::add_edge (reference, direct, *this->current_graph_);
        }
        else
        {
          this->add_vertex (reference_parent, this->current_graph_);
          
          VERTEX reference = find_vertex (reference_parent, this->current_graph_, found_ref_parent);
          boost::add_edge (reference, direct, *this->current_graph_);
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
  
  for (parent = o.GetParent (); parent.type () != T::meta; parent = parent.GetParent ())
  {}
  
  return parent;
}
