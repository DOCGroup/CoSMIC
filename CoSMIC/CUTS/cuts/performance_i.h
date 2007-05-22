// -*- C++ -*-

//=============================================================================
/**
 * @file      performance_i.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_PERFORMANCE_I_H_
#define _CUTS_PERFORMANCE_I_H_

#include "cuts/CUTS_stub_export.h"
#include "cuts/performanceC.h"
#include "cuts/Benchmark_Agent.h"
#include "cuts/Port_Agent.h"
#include "cuts/Port_Metric.h"
#include "cuts/Component_Metric.h"

///////////////////////////////////////////////////////////////////////////////
// @@ extraction operators

void CUTS_STUB_Export operator >>= (const CUTS::Component_Metric & src,
                                    CUTS_Component_Metric & dst);

void CUTS_STUB_Export operator >>= (const CUTS::Port_Metric & pm,
                                    CUTS_Port_Metric & port);

void CUTS_STUB_Export operator >>= (const CUTS::Sorted_Port_Metrics & sps,
                                    CUTS_Port_Measurement_Map & pmp);

void CUTS_STUB_Export operator >>= (const CUTS::Port_Summary & ps,
                                    CUTS_Port_Measurement & pm);

void CUTS_STUB_Export operator >>= (const CUTS::Endpoint_Time_Infos & eti,
                                    CUTS_Port_Measurement_Endpoint_Map & eps);

void CUTS_STUB_Export operator >>= (const CUTS::Time_Info & ti,
                                    CUTS_Time_Measurement & tm);

void CUTS_STUB_Export operator >>= (const CUTS::Metric_Log & mlog,
                                    CUTS_Activation_Record_Log & log);

void CUTS_STUB_Export operator >>= (const CUTS::Metric_Record & m_record,
                                    CUTS_Activation_Record & a_record);

void CUTS_STUB_Export operator >>= (const CUTS::Action_Time & act,
                                    CUTS_Activation_Record_Entry & entry);

void CUTS_STUB_Export operator >>= (const CUTS::Action_Times & act,
                                    CUTS_Activation_Record_Entry_Log & entries);

void CUTS_STUB_Export operator >>= (const CUTS::Endpoint_Times & ep_times,
                                    CUTS_Activation_Record_Endpoints & endpoints);

void CUTS_STUB_Export operator >>= (const CUTS::Time_Stamp & ts,
                                    ACE_Time_Value & tm);

///////////////////////////////////////////////////////////////////////////////
// @@ insertion operators

void CUTS_STUB_Export operator <<= (CUTS::Component_Metric & cm,
                                    const CUTS_Benchmark_Agent & agent);

void CUTS_STUB_Export operator <<= (CUTS::Port_Metric & pm,
                                    const CUTS_Port_Agent & agent);

void CUTS_STUB_Export operator <<= (CUTS::Sorted_Port_Metrics & sps,
                                    const CUTS_Port_Measurement_Map & pmp);

void CUTS_STUB_Export operator <<= (CUTS::Port_Summary & ps,
                                    const CUTS_Port_Measurement & pm);

void CUTS_STUB_Export operator <<= (CUTS::Endpoint_Time_Infos & eti,
                                    const CUTS_Port_Measurement_Endpoint_Map & eps);

void CUTS_STUB_Export operator <<= (CUTS::Time_Info & ti,
                                    const CUTS_Time_Measurement & tm);

void CUTS_STUB_Export operator <<= (CUTS::Metric_Log & mlog,
                                    const CUTS_Activation_Record_Log & log);

void CUTS_STUB_Export operator <<= (CUTS::Metric_Record & m_record,
                                    const CUTS_Activation_Record & a_record);

void CUTS_STUB_Export operator <<= (CUTS::Action_Time & act,
                                    const CUTS_Activation_Record_Entry & entry);

void CUTS_STUB_Export operator <<= (CUTS::Action_Times & act,
                                    const CUTS_Activation_Record_Entry_Log & entries);

void CUTS_STUB_Export operator <<= (CUTS::Endpoint_Times & ep_times,
                                    const CUTS_Activation_Record_Endpoints & endpoints);

void CUTS_STUB_Export operator <<= (CUTS::Time_Stamp & ts,
                                    const ACE_Time_Value & tm);

#if defined (__CUTS_INLINE__)
#include "cuts/performance_i.inl"
#endif

#endif  // !defined _CUTS_PERFORMANCE_I_H_
