#include <engine/configurator.hpp>
#include <ace/Log_Msg.h>

void write_indent(size_t indent)
{
  for (; indent; --indent)
    std::cout << "  ";
}

void write_category(OCML::Option_Category* category, size_t indent = 0)
{
  write_indent(indent);
  std::cout << "Category: " << category->name() << std::endl;
  indent++;

  for (OCML::Option_Category::category_iterator iter =
         category->begin_categories();
       iter != category->end_categories(); ++iter)
  {
    write_category(*iter, indent);
  }

  for (OCML::Option_Category::option_iterator iter =
         category->begin_options();
       iter != category->end_options(); ++iter)
  {
    write_indent(indent);
    std::cout << "Option: " << (*iter)->name() << std::endl;
  }
}

int ACE_TMAIN(int, ACE_TCHAR*[])
{
  ACE_LOG_MSG->priority_mask(LM_DEBUG, ACE_Log_Msg::PROCESS);
  OCML::Configurator* c =
    OCML::Configurator::instance("orb_tree.xml", 0, 0, 0, 0);
  write_category(c->root_category());
  delete c;
  return 0;
}
