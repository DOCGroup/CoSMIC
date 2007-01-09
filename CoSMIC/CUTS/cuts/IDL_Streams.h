// -*- C++ -*-

//=============================================================================
/**
 * @file    CUTS_Streams.h
 *
 * @brief   Defines stream operators for CUTS.idl types
 *
 * $Id$
 *
 * @author  James H. Hill
 */
//=============================================================================

#ifndef _CUTS_IDL_STREAMS_H_
#define _CUTS_IDL_STREAMS_H_

#include /**/ "ace/pre.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif

#include "cuts/CUTS_stub_export.h"
#include "cuts/CUTSC.h"
#include "cuts/Benchmark_Agent.h"
#include "cuts/Port_Measurement.h"
#include "cuts/Port_Measurement_Pool.h"

// forward declarations
class CUTS_Port_Agent;
class CUTS_Time_Metric;
class CUTS_Port_Metric;
class CUTS_System_Metric;

//===========================================================================
// extraction operations

void CUTS_STUB_Export operator >> (const ::CUTS::Time_Sample &,
                                   CUTS_Time_Metric &);

void CUTS_STUB_Export operator >> (const ::CUTS::Mapped_Port_Measurement &,
                                   CUTS_Port_Metric &);

void CUTS_STUB_Export operator >> (const ::CUTS::Benchmark_Data_var &,
                                   CUTS_System_Metric &);

//===========================================================================
// insertion operations

void CUTS_STUB_Export operator << (::CUTS::Time_Sample &,
                                   const CUTS_Time_Measurement &);

#include /**/ "ace/post.h"

#endif  // !defined _CUTS_IDL_STREAMS_H_
