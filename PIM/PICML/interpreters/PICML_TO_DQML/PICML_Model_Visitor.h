//=============================================================================
/**
 * @file       PICML_Model_Visitor.h
 *
 * $Id$
 *
 * @author     Hossein Karimy
 */
//=============================================================================

#ifndef _PICML_MODEL_VISITOR_H_
#define _PICML_MODEL_VISITOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"
#include "DQML_Model_Factory.h"

namespace PICML_To_DQML 
{

  /**
  * @class Participant_File_Locator
  */
  class PICML_Model_Visitor 
    : public PICML::Visitor 
  {
  public:
    PICML_Model_Visitor (DQML_Model_Factory & factory);

    ~PICML_Model_Visitor (void);

    void visit_RootFolder (PICML::RootFolder_in item);
    void visit_ComponentImplementations (PICML::ComponentImplementations_in item);
    void visit_ComponentImplementationContainer (PICML::ComponentImplementationContainer_in item);

  private :
    DQML_Model_Factory & factory_;
    GAME::Mga::Object current_node_;
  };

}
#endif  // !defined _PICML_MODEL_VISITOR_H_ 
