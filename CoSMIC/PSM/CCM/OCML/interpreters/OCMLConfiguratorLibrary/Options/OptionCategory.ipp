/*
 * OptionCategory inline methods.
 */

OptionCategory::OptionCategory(const char* name, const char* description)
  : DescribedItem(name, description)
{
}

/*
 * STL begin & end markers.
 */

OptionCategory::category_iterator
OptionCategory::begin_categories()
{
  return categories_.begin();
}

OptionCategory::category_iterator
OptionCategory::end_categories()
{
  return categories_.end();
}

OptionCategory::option_iterator
OptionCategory::begin_options()
{
  return options_.begin();
}

OptionCategory::option_iterator
OptionCategory::end_options()
{
  return options_.end();
}

/*
 * STL begin & end markers. - const versions -
 */

OptionCategory::const_category_iterator
OptionCategory::begin_categories() const
{
  return categories_.begin();
}

OptionCategory::const_category_iterator
OptionCategory::end_categories() const
{
  return categories_.end();
}

OptionCategory::const_option_iterator
OptionCategory::begin_options() const
{
  return options_.begin();
}

OptionCategory::const_option_iterator
OptionCategory::end_options() const
{
  return options_.end();
}

void
OptionCategory::add_option(Option* option)
{
  options_.push_back(option);
}

void
OptionCategory::add_category(OptionCategory* category)
{
  categories_.push_back(category);
}

