// -*- C# -*-

//=============================================================================
/**
 * @file        PerformanceTimes.cs
 *
 * Defines the object for storing performance times.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

using System;
using System.Data;
using System.Configuration;
using System.Web;
using System.Web.Security;
using System.Web.UI;
using System.Web.UI.WebControls;
using System.Web.UI.WebControls.WebParts;
using System.Web.UI.HtmlControls;

namespace CUTS
{
  public class PerformanceTimes
  {
    public PerformanceTimes()
    {
      this.max_ = this.min_ = this.count_ = 0;
      this.avg_ = 0.0;
    }

    public PerformanceTimes(long min, double avg, long max)
    {
      this.min_ = min;
      this.avg_ = avg;
      this.max_ = max;
    }

    public long Minimum
    {
      set { this.min_ = value; }
      get { return this.min_; }
    }

    public double Average
    {
      set { this.avg_ = value; }
      get { return this.avg_; }
    }

    public long Maximum
    {
      set { this.max_ = value; }
      get { return this.max_; }
    }

    public long Count
    {
      set { this.count_ = value; }
      get { return this.count_; }
    }

    public void Set(long count, long min, double avg, long max)
    {
      this.count_ = count;

      this.min_ = min;
      this.avg_ = avg;
      this.max_ = max;
    }

    private long min_;

    private double avg_;

    private long max_;

    private long count_;
  }
}
