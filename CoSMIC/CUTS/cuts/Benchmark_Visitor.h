// -*- C++ -*-

//=============================================================================
/**
 * @file      Benchmark_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BENCHMARK_VISITOR_H_
#define _CUTS_BENCHMARK_VISITOR_H_

#include "cuts/CUTS_export.h"

// Forward decl.
class CUTS_Benchmark_Agent;

// Forward decl.
class CUTS_Port_Agent;

// Forward decl.
class CUTS_Port_Measurement;

class CUTS_Export CUTS_Benchmark_Visitor
{
public:
  virtual ~CUTS_Benchmark_Visitor (void);

  virtual void visit_benchmark_agent (
    const CUTS_Benchmark_Agent & agent);

  virtual void visit_port_agent (
    const CUTS_Port_Agent & agent);

  virtual void visit_port_measurement (
    const CUTS_Port_Measurement & measurement);

protected:
  CUTS_Benchmark_Visitor (void);
};

#if defined (__CUTS_INLINE__)
#include "cuts/Benchmark_Visitor.inl"
#endif

#endif  // !defined _CUTS_BENCHMARK_VISITOR_H_
