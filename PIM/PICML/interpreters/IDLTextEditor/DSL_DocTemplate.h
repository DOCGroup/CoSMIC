// -*- C++ -*-

//=============================================================================
/**
 *  @file         DSL_DocTemplate.h
 *
 *  @author       James H. Hill
 */
//=============================================================================

#ifndef _DSL_DOCTEMPLATE_H_
#define _DSL_DOCTEMPLATE_H_

#include <afxwin.h>

/**
 * @class DSL_DocTemplate
 *
 * Document template for domain-specific languages.
 */
class DSL_DocTemplate : public CSingleDocTemplate
{
public:
  /// Default constuctor.
  DSL_DocTemplate (void);

  /// Destructor.
  virtual ~DSL_DocTemplate (void);

  virtual CFrameWnd * CreateNewFrame (CWnd * parent,
                                      CDocument* doc,
                                      CFrameWnd* other);
};

#endif  // !define _DSL_DOCTEMPLATE_H_
