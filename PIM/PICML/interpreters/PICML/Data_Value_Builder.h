/* -*- C++ -*- */

//=============================================================================
/**
 * @file          Data_Value_Builder.h
 *
 * INSERT FILE DESCRIPTION HERE
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DATA_VALUE_BUILDER_H_
#define _DATA_VALUE_BUILDER_H_

#include "PICML.h"
#include "game/GME_fwd.h"

// Forward decl.
class PICML_Data_Value;

//=============================================================================
/**
 * @class PICML_Data_Value_Builder
 *
 * INSERT CLASS DESCRIPTION HERE
 */
//=============================================================================

namespace GME
{
  class FCO;

class PICML_Export PICML_Data_Value_Builder
{
public:
  /// Default constructor.
  PICML_Data_Value_Builder (void);

  /// Destructor.
  ~PICML_Data_Value_Builder (void);

  bool create_data_value (const std::string & name,
                          const GAME::FCO & type,
                          PICML_Data_Value * & value,
                          PICML_Data_Value * parent = 0);

private:
  bool build_complex (const std::string & name,
                      const GAME::FCO & datatype,
                      PICML_Data_Value * & value,
                      PICML_Data_Value * parent = 0);

  bool build_aggregate (const std::string & name,
                        const GAME::Model & aggregate,
                        PICML_Data_Value * & value,
                        PICML_Data_Value * parent = 0);

  bool build_collection (const std::string & name,
                         const GAME::Reference & collection,
                         PICML_Data_Value * & value,
                         PICML_Data_Value * parent = 0);

  bool build_enum (const std::string & name,
                   const GAME::Model & en,
                   PICML_Data_Value * & value,
                   PICML_Data_Value * parent = 0);

  bool build_alias (const std::string & name,
                    const GAME::Reference & alias,
                    PICML_Data_Value * & value,
                    PICML_Data_Value * parent = 0);

  bool build_event (const std::string & name,
                    const GAME::Model & model,
                    PICML_Data_Value * & value,
                    PICML_Data_Value * parent = 0);

  bool build_complex_i (const std::string & name,
                        const std::string & meta,
                        const GAME::FCO & model,
                        PICML_Data_Value * & value,
                        PICML_Data_Value * parent = 0);

};
}

namespace PICML
{
class PICML_Export Data_Value_Builder
{
public:
  /// Default constructor.
  Data_Value_Builder (void);

  /// Destructor.
  ~Data_Value_Builder (void);

  bool create_data_value (const std::string & name,
                          const PICML::MemberType & type,
                          PICML_Data_Value * & value);

   static std::string create_repo_id (const ::PICML::MgaObject &type);
private:
  bool build (const std::string & name,
              const PICML::Aggregate & aggregate,
              PICML_Data_Value * & value);

  bool build (const std::string & name,
              const PICML::Collection & collection,
              PICML_Data_Value * & value);

  bool build (const std::string & name,
              const PICML::Enum & e,
              PICML_Data_Value * & value);

  //private:

  bool build (const std::string & name,
              const PICML::Alias & alias,
              PICML_Data_Value * & value);

private:
  struct RepoID
  {
    std::string format;
    std::string prefix;
    std::string rest;
    std::string version;
  };

  static void create_repositoryID_Impl (const ::PICML::MgaObject &type,
          RepoID &repoid);

};
}

#endif  /* !defined _DATA_VALUE_BUILDER_H_ */
