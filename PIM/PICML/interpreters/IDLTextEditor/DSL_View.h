// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_View.h
 *
 *  $Id$
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_VIEW_H_
#define _DSL_VIEW_H_

#include <afxrich.h>

/**
 * @class DSL_View
 *
 * The view of the domain-specific modeling language
 */
class DSL_View : protected CRichEditView
{
public:
  /// Default constructor.
  DSL_View (void);

  /// Destructor.
  virtual ~DSL_View (void);

  DECLARE_DYNCREATE (DSL_View);

protected:
  virtual int OnCreate (LPCREATESTRUCT create);

  virtual void OnInitialUpdate (void);

private:
  DECLARE_MESSAGE_MAP ()
};

#endif  // !defined _DSL_VIEW_H_

