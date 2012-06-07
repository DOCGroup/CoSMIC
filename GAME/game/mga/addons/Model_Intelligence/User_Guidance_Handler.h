// -*- C++ -*-

//=============================================================================
/**
 * @file          User_Guidance_Handler.h
 *
 * $Id: Association_Handler.h 2899 2012-05-01 20:01:10Z tpati $
 *
 * @author        Tanumoy Pati
 */
//=============================================================================

#ifndef _GAME_MODEL_INTELLIGENCE_USER_GUIDANCE_HANDLER_H_
#define _GAME_MODEL_INTELLIGENCE_USER_GUIDANCE_HANDLER_H_

#include "game/mga/Object.h"
#include <iostream>
#include "game/mga/component/Global_Event_Handler.h"

/**
 * @class User Guidance Handler
 *
 * Class used for providing user guidance to modelers.
 * This class is invoked after every handler.
 */

class User_Guidance_Handler :
  public GAME::Mga::Global_Event_Handler
{
public:
  static const unsigned long eventmask = GLOBALEVENT_NOTIFICATION_READY;

  /// Default Construcotr
  User_Guidance_Handler (void);

  /// Destructor
  virtual ~User_Guidance_Handler (void);

  virtual int handle_notification_ready (void);

  // Displays the list of models under rootfolder
  int rootmodel_add (GAME::Mga::RootFolder & root_folder,
                     std::vector<GAME::Mga::Meta::Model> & rootmodels);

  // Displays the parent models
  int aspect_add (GAME::Mga::RootFolder & root_folder,
                  std::vector<GAME::Mga::Model> & models);

  // Provides action option list
  int option_list (GAME::Mga::Model & mod);

  // Adds a model or atom to the model
  int element_add (GAME::Mga::Model & parent_model, 
                   std::vector <GAME::Mga::Meta::Role> & fcos);

  // Adds a reference to the model
  int reference_add (GAME::Mga::Model & parent_model, 
                      std::vector <GAME::Mga::Meta::Role> & ref);

  // Adds a connection to the model
  int connection_add (GAME::Mga::Model & parent_model, 
                       std::vector <GAME::Mga::Meta::Role> & conn);

  // Displays a list of sources for connection
  int select_source (GAME::Mga::Model & parent_model, 
                      GAME::Mga::Meta::Role & conn);
};

#endif //_GAME_MODEL_INTELLIGENCE_USER_GUIDANCE_HANDLER_H_
