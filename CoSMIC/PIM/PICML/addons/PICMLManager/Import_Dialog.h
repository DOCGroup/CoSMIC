// -*- C++ -*-

//==============================================================================
/**
 *  @file        Import_Dialog.h
 *
 *  $Id: generate_cpp_class.py 3685 2012-09-26 14:45:04Z dfeiock $
 *
 *  @author      INSERT NAME HERE
 */
//==============================================================================

#ifndef _PICML_IMPORT_DIALOG_H_
#define _PICML_IMPORT_DIALOG_H_

#include <string>
#include "resource.h"

namespace PICML
{
namespace MI
{

// Forward decl.
class Implementation_Configuration;

/**
 * @class Import_Dialog
 */
class Import_Dialog : public CDialog
{
public:
  /// Default constructor.
  Import_Dialog (Implementation_Configuration & config, CWnd * parent);

  /// Destructor.
  virtual ~Import_Dialog (void);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

private:
  /// Configuration of the new component.
  Implementation_Configuration & config_;
};

}
} // namespace PICML

#include "Import_Dialog.inl"

#endif  // _PICML_IMPORT_DIALOG_H_
