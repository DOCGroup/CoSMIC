#include <xercesc/dom/DOMText.hpp>

/*
 *  class BasicOption methods.
 */

template <typename VALUE_TYPE>
BasicOption<VALUE_TYPE>::BasicOption(value_kind_type value_kind,
                                     const char* name, const char* description)
  : Option(value_kind, name, description),
    value_()
{
}

template <typename VALUE_TYPE>
BasicOption<VALUE_TYPE>::~BasicOption()
{
}

/**
 * The value for the option is stored as a pointer. Whenever an assignment
 * is made a pointer to the specified type is created and assigned with the
 * given value.
 * <P>
 * If the value is NULL, the option is assumed as not assigned.
 */
template <typename VALUE_TYPE> void
BasicOption<VALUE_TYPE>::set(typename BasicOption::value_type value)
{
  value_.reset(new VALUE_TYPE(value));
}

/**
 * The NotAssigned exception is thrown when the value_ ptr points to a NULL
 * pointer.
 */
template <typename VALUE_TYPE> typename BasicOption<VALUE_TYPE>::value_type
BasicOption<VALUE_TYPE>::get() const
{
  if (value_.get() == NULL)
    throw NotAssigned();

  return *value_;
}

/**
 * Appends value to the node created by the Option::write()
 * if the value is not NULL.
 * 
 * @see DescribedItem::write.
 * @see Option::write.
 */
template <typename VALUE_TYPE> xercesc::DOMElement*
BasicOption<VALUE_TYPE>::write(xercesc::DOMDocument* doc) const
{
  xercesc::DOMElement* element = Option::write(doc);

  // If the value is not assigned element is null.
  if (element)
    {
      xercesc::DOMText* text_node =
	doc->createTextNode(XMLUnicodeString(get_str_value().c_str()));
      element->appendChild(text_node);
    }
  
  return element;
}

/**
 * Clears the option by assigning the value to NULL.
 * If the value is not NULL, first deletes it.
 *
 * @see Option::clear.
 */
template <typename VALUE_TYPE> void
BasicOption<VALUE_TYPE>::clear()
{
  value_.reset();
}

/**
 * Returns true if the option is NULL, otherwise false.
 * The option can be cleared by calling the clear method.
 *
 * @see Option::assigned.
 */
template <typename VALUE_TYPE> bool
BasicOption<VALUE_TYPE>::assigned() const
{
  return value_.get() != NULL;
}
