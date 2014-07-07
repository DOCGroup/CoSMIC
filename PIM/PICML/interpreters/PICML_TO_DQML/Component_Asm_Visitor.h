//=============================================================================
/**
* @file       Component_Asm_Visitor.h
*
* $Id$
*
* @author     Hossein Karimy
*/
//=============================================================================
#ifndef _COMPONENT_ASM_VISITOR_H_
#define _COMPONENT_ASM_VISITOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"
#include "DQML_Model_Factory.h"

namespace PICML_To_DQML
{
  class Component_Asm_Visitor :
    public PICML::Visitor
  {
  public:
    Component_Asm_Visitor (DQML_Model_Factory & factory, GAME::Mga::Object current_node);
    
    ~Component_Asm_Visitor(void);

    void visit_ComponentAssembly (PICML::ComponentAssembly_in item);
    void visit_ComponentInstance (PICML::ComponentInstance_in item);
    void visit_InEventPortInstance (PICML::InEventPortInstance_in item);
    void visit_OutEventPortInstance (PICML::OutEventPortInstance_in item);
    void visit_InEventPort (PICML::InEventPort_in item);
    void visit_OutEventPort (PICML::OutEventPort_in item);
                                    
  private :
    DQML_Model_Factory & factory_;
    GAME::Mga::Object current_node_;

    std::vector <PICML::AttributeInstance> messages;
  };
}

#endif  // !defined _COMPONENT_ASM_VISITOR_H_ 
