// -*- C# -*-

//=============================================================================
/**
 * @file      PathElement.cs
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

namespace CUTS.Data
{
  struct PathElement
  {
    public PathElement(long component, string src, string dst)
    {
      this.component_ = component;
      this.src_ = src;
      this.dst_ = dst;
    }

    public long component_;

    public string src_;

    public string dst_;
  }
}
