// $Id$

#include "Type_Trait.h"

//
// add_predefined_type
//
template  <typename T>
void adding_visitor::add_predefined_type (DOMElement * pdt_folder)
{
  DOMElement *pdt = 0;
  const char *pdt_name = IDML::Type_Trait <T>::metaname;

  const size_t index = IDML_PREDEFINED_TYPES_COUNT - IDML::Type_Trait <T>::tk_index;

  if (0 == be_global->input_xme ())
    {
      pdt = doc_->createElement (X ("atom"));
      this->set_id_attr (pdt, BE_GlobalData::ATOM);
      pdt->setAttribute (X ("kind"), X (pdt_name));

      // The relid attributes are numbered in reverse order in all sample
      // files - don't know if it's true for all attached libraries or not.
      char *relid_str = be_global->hex_string (index);
      pdt->setAttribute (X ("relid"), X (relid_str));
      this->add_name_element (pdt, pdt_name);
      pdt_folder->appendChild (pdt);
    }
  else
    {
      pdt =
        be_global->lookup_by_tag_and_kind (pdt_folder,
                                           "atom",
                                           pdt_name);

      if (pdt == 0)
        {
          ACE_ERROR ((LM_ERROR,
                      ACE_TEXT ("PredefinedTypes folder, ")
                      ACE_TEXT ("as seen in %s, has ")
                      ACE_TEXT ("been altered.\n"),
                      be_global->input_xme ()));
          BE_abort ();
        }
    }

  // Store the GME id for possible rererence by other XML elements.
  be_global->decl_id_table ().bind (
    ACE::strnew (pdt_name),
    pdt->getAttribute (X ("id")));
}

//
// add_one_predefined_sequence
//
template <typename T>
unsigned long adding_visitor::
add_one_predefined_sequence (unsigned long model_slot)
{
  // Can't create a basic type sequence more than once in a project.
  // A processed basic type sequence is stored by its GME id.
  const XMLCh *gme_id = 0;
  const char * metaname = IDML::Type_Trait <T>::metaname;
  ACE_CString name (metaname);

  name += be_global->basic_seq_suffix ();
  int result = be_global->decl_id_table ().find (name.c_str (), gme_id);

  if (0 == result)
    return model_slot;

  DOMElement *seq = 0;
  result = be_global->decl_elem_table ().find (name.c_str (), seq);

  if (result != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       ACE_TEXT ("adding_visitor::add_one_predefined_sequence - ")
                       ACE_TEXT ("lookup of sequence DOCElement %s failed\n"),
                       name.c_str ()),
                       model_slot);

  this->set_id_attr (seq, BE_GlobalData::REF);
  seq->setAttribute (X ("relid"), X (be_global->hex_string (model_slot)));
  ++ model_slot;

  seq->setAttribute (X ("kind"), X ("Collection"));
  seq->setAttribute (X ("role"), X ("Collection"));

  //const char **pdts = be_global->pdt_names ();
  const XMLCh *pdt_id = 0;

  result =
    be_global->decl_id_table ().find (metaname, pdt_id);

  if (result != 0)
    ACE_ERROR_RETURN ((LM_ERROR,
                       "adding_visitor::add_one_predefined_sequence - "
                       "lookup of base type id %s failed\n",
                       metaname),
                       model_slot);

  seq->setAttribute (X ("referred"), pdt_id);

  this->add_name_element (seq, name.c_str ());

  be_global->decl_id_table ().bind (ACE::strnew (
    name.c_str ()),
    seq->getAttribute (X ("id")));

  DOMElement *pdt_folder =
    be_global->lookup_by_tag_and_kind (be_global->root_folder (),
                                       "folder",
                                       "PredefinedTypes");
  pdt_folder->appendChild (seq);

  return model_slot;
}
