// -*- C++ -*-

//=============================================================================
/**
 * @file    Time_Metric_Test.h
 *
 * $Id: Time_Metric_Test.h,v 1.1.2.2 2006/05/20 18:10:12 hillj Exp $
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_TIME_METRIC_TEST_H_
#define _CUTS_TIME_METRIC_TEST_H_

#include "Test.h"
#include "Unit_Test.h"
#include "Test_Macros.h"

// main test
CUTS_TEST_DECLARE (CUTS_Time_Metric_Test);

// unit test
CUTS_UNIT_TEST_DECLARE (Unit_Test_TM_Time_Value);
CUTS_UNIT_TEST_DECLARE (Unit_Test_TM_Operators);
CUTS_UNIT_TEST_DECLARE (Unit_Test_TM_Reset);

#endif  // !defined _CUTS_TIME_METRIC_TEST_H_
