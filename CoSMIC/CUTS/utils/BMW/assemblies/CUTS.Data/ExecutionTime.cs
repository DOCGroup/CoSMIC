// -*- C# -*-

//=============================================================================
/**
 * @file        ExecutionTime.cs
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

using System;

namespace CUTS.Data
{
  public struct ExecutionTime
  {
    public long samples;

    public long recentmin;
    public long recentmax;
    public long recentavg;

    public long absmin;
    public long absmax;

    public long avgmin;
    public long avgavg;
    public long avgmax;

    public DateTime lastsample;
  }
}
