/*
 *  Inline methods for the BooleanOption.
 */

inline
BooleanOption::BooleanOption(const char* name, const char* description)
    : BasicOption<bool>(ovk_boolean, name, description)
{
}

/*
 *  Inline methods for the StringOption.
 */

inline
StringOption::StringOption(const char* name, const char* description)
    : BasicOption<std::string>(ovk_string, name, description)
{
}

/*
 *  Inline methods for the IntegerOption.
 */

inline
IntegerOption::IntegerOption(const char* name, const char* description)
    : BasicOption<int>(ovk_integer, name, description)
{
}

/*
 *  Inline methods for the EnumOption.
 */

inline
EnumOption::EnumOption(const char* name, const char* description)
    : BasicOption<std::string>(ovk_enum, name, description)
{
}

inline void
EnumOption::add_item(const char* item_name)
{
  items_.push_back(std::string(item_name));
}
