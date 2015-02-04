// -*- C++ -*-

#ifndef _DQML_ICCM_PARTICIPANT_FILE_H_
#define _DQML_ICCM_PARTICIPANT_FILE_H_

#include "DQML/iCCM/DomainParticipantQoS/Participant.h"
#include "DQML/Visitor.h"

namespace DQML_iCCM
{

/**
 * @class Participant_File_Locator
 */
class Participant_File_Locator : public DQML::Visitor
{
public:
  /// Initializing constructor.
  Participant_File_Locator (const std::string & path);

  /// Destructor.
  ~Participant_File_Locator (void);

  void visit_RootFolder (DQML::RootFolder_in item);
  void visit_iCCM (DQML::iCCM_in item);
  void visit_DomainQosFolder (DQML::DomainQosFolder_in item);
  void visit_Domain (DQML::Domain_in item);
  void visit_Participant (DQML::Participant_in item);

private:
  /// Path to generate participant files.
  const std::string & path_;

  /// Name of the current domain.
  std::string domain_;
};

/**
 * @class Participant_File
 */
class Participant_File
{
public:
  /// Default constructor.
  Participant_File (void);

  /// Destructor.
  ~Participant_File (void);

  void generate (const std::string & path, DQML::Participant_in item);
};


}

#endif  // !defined _DQML_ICCM_PARTICIPANT_FILE_H_
