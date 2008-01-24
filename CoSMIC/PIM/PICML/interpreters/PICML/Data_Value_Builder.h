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
#include "gme/GME.h"

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
class PICML_Data_Value_Builder
{
public:
  /// Default constructor.
  PICML_Data_Value_Builder (void);

  /// Destructor.
  ~PICML_Data_Value_Builder (void);

  bool build_aggregate (const GME::Model & aggregate,
                        PICML_Data_Value * & value);

  bool build_collection (const GME::Reference & collection,
                         PICML_Data_Value * & value);

  bool build_enum (const GME::Model & e,
                   PICML_Data_Value * & value);

private:
  bool create_data_value (const GME::FCO & type,
                          PICML_Data_Value * & value);
};
}

namespace PICML
{
class Data_Value_Builder
{
public:
  /// Default constructor.
  Data_Value_Builder (void);

  /// Destructor.
  ~Data_Value_Builder (void);

  bool build (const PICML::Aggregate & aggregate, PICML_Data_Value * & value);

  bool build (const PICML::Collection & collection, PICML_Data_Value * & value);

  bool build (const PICML::Enum & e, PICML_Data_Value * & value);

private:
  bool create_data_value (const PICML::MemberType & type,
                          PICML_Data_Value * & value);
};
}

#endif  /* !defined _DATA_VALUE_BUILDER_H_ */
