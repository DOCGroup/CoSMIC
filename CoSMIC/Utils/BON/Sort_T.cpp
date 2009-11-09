// $Id$

namespace BON
{
namespace Utils
{
//
// Position_Sorter_T
//
template <typename T, typename SORT>
Position_Sorter_T <T, SORT>::Position_Sorter_T (void)
{

}

template <typename T, typename SORT>
bool Position_Sorter_T <T, SORT>::operator () (const T & lhs, const T & rhs) const
{
  // Get the position of the left object.
  BON::FCOExRegistryNode regnode = lhs->getRegistry ();
  BON::Point pt = regnode->getLocation ("InterfaceDefinition");
  ::Utils::Point lhs_point (pt.first, pt.second);

  // Get the position of the right object.
  regnode = rhs->getRegistry ();
  pt = regnode->getLocation ("InterfaceDefinition");
  ::Utils::Point rhs_point (pt.first, pt.second);

  // Compare the position of the two objects.
  return this->sorter_ (lhs_point, rhs_point);
}

}
}
