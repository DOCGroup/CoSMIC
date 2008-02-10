// $Id$

//=============================================================================
/**
 * @file        DT_Controls.h
 *
 * Defines controls for inputing complex types in PICML
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DT_CONTROLS_H_
#define _PICML_DT_CONTROLS_H_

#include <string>
#include <vector>
#include <set>

// Forward decl.
class PICML_Data_Value;

//=============================================================================
/**
 * @class PICML_Data_Value_Control
 */
//=============================================================================

class PICML_Data_Value_Control
{
public:
  PICML_Data_Value_Control (void);

  virtual ~PICML_Data_Value_Control (void);

  void InitControl (size_t item, PICML_Data_Value * value);

  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id) = 0;

  virtual BOOL Destroy (void) = 0;

  size_t item (void) const;

protected:
  PICML_Data_Value * value_;

private:
  size_t item_;
};

//=============================================================================
/**
 * @class PICML_Simple_DT_Control
 */
//=============================================================================

template <typename CONTROL>
class PICML_Simple_DT_Control :
  public CONTROL,
  public PICML_Data_Value_Control
{
public:
  /// Type definition of the control type.
  typedef CONTROL control_type;

  /// Destructor.
  virtual ~PICML_Simple_DT_Control (void);

  /**
   * Helper method to create an window.
   *
   * @param[in]       style       Style of the control.
   * @param[in]       rect        Dimensions of the control.
   * @param[in]       parent      The parent of the control.
   * @param[in]       id          Unique id of the control.
   */
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);

  virtual BOOL Destroy (void);

protected:
  /**
   * Initializing contructor.
   *
   * @param[in]       name        Name of the control.
   */
  PICML_Simple_DT_Control (void);

  /// The id of the control.
  UINT id_;
};

//=============================================================================
/**
 * @class PICML_Simple_DT_Control <CEdit>
 */
//=============================================================================

template < >
class PICML_Simple_DT_Control <CEdit> :
  public CEdit,
  public PICML_Data_Value_Control
{
public:
  /// Type definition of the control type.
  typedef CEdit control_type;

  /// Destructor.
  virtual ~PICML_Simple_DT_Control (void);

  /**
   * Helper method to create an window.
   *
   * @param[in]       style       Style of the control.
   * @param[in]       rect        Dimensions of the control.
   * @param[in]       parent      The parent of the control.
   * @param[in]       id          Unique id of the control.
   */
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);

  virtual BOOL Destroy (void);

protected:
  /**
   * Initializing contructor.
   *
   * @param[in]       name        Name of the control.
   */
  PICML_Simple_DT_Control (void);

  /// The id of the control.
  UINT id_;
};

//=============================================================================
/**
 * @class PICML_Char_DT_Control
 */
//=============================================================================

class PICML_Char_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_Char_DT_Control (void);

  /// Destructor.
  virtual ~PICML_Char_DT_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);
};

//=============================================================================
/**
 * @class PICML_String_DT_Control
 */
//=============================================================================

class PICML_String_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  /// Default contructor.
  PICML_String_DT_Control (void);

  /// Destructor.
  virtual ~PICML_String_DT_Control (void);
};

//=============================================================================
/**
 * @class PICML_Short_DT_Control
 */
//=============================================================================

class PICML_Short_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  /// Destructor.
  virtual ~PICML_Short_DT_Control (void);

  PICML_Short_DT_Control (void);
};

//=============================================================================
/**
 * @class PICML_UShort_DT_Control
 */
//=============================================================================

class PICML_UShort_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  PICML_UShort_DT_Control (void);

  /// Destructor.
  virtual ~PICML_UShort_DT_Control (void);
};

//=============================================================================
/**
 * @class PICML_Long_DT_Control
 */
//=============================================================================

class PICML_Long_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_Long_DT_Control (void);

  /// Destructor.
  virtual ~PICML_Long_DT_Control (void);
};

//=============================================================================
/**
 * @class PICML_ULong_DT_Control
 */
//=============================================================================

class PICML_ULong_DT_Control :
  public PICML_Simple_DT_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_ULong_DT_Control (void);

  /// Destructor.
  virtual ~PICML_ULong_DT_Control (void);
};

//=============================================================================
/**
 * @class PICML_Boolean_DT_Control
 */
//=============================================================================

class PICML_Boolean_DT_Control :
  public PICML_Simple_DT_Control <CComboBox>
{
public:
  PICML_Boolean_DT_Control (void);

  /// Destructor.
  virtual ~PICML_Boolean_DT_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);
};

//=============================================================================
/**
 * @class PICML_Enum_DT_Control
 */
//=============================================================================

class PICML_Enum_DT_Control :
  public PICML_Simple_DT_Control <CComboBox>
{
public:
  /// Default contructor.
  PICML_Enum_DT_Control (void);

  /// Destructor.
  virtual ~PICML_Enum_DT_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);
};

#include "DT_Controls_T.cpp"

#endif  // !defined _PICML_DT_CONTROLS_H_
