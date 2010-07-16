// $Id$

//=============================================================================
/**
 * @file        Data_Value_Controls.h
 *
 * Defines controls for inputing complex types in PICML
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _PICML_DATA_VALUE_CONTROLS_H_
#define _PICML_DATA_VALUE_CONTROLS_H_

#include "PICML/PICML.h"

/**
 * @class PICML_Data_Value_Control
 *
 * Base class for all data base controls.
 */
class PICML_Data_Value_Control
{
public:
  /// Default constructor.
  PICML_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_Data_Value_Control (void);

  void InitControl (size_t item, const PICML::DataValue & value);

  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id) = 0;

  virtual BOOL Destroy (void) = 0;

  /// Get the item number for this control.
  size_t item (void) const;

protected:
  /// The current data value.
  PICML::DataValue value_;

private:
  /// The current index/item number for the control.
  size_t item_;
};

/**
 * @class PICML_Simple_Data_Value_Control
 *
 * Template class for all the simple controls.
 */
template <typename CONTROL>
class PICML_Simple_Data_Value_Control :
  public CONTROL,
  public PICML_Data_Value_Control
{
public:
  /// Type definition of the control type.
  typedef CONTROL control_type;

  /// Destructor.
  virtual ~PICML_Simple_Data_Value_Control (void);

  /**
   * Helper method to create an window.
   *
   * @param[in]       style       Style of the control.
   * @param[in]       rect        Dimensions of the control.
   * @param[in]       parent      The parent of the control.
   * @param[in]       id          Unique id of the control.
   */
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);

  /// Destroy the control.
  virtual BOOL Destroy (void);

protected:
  /**
   * Initializing contructor.
   *
   * @param[in]       name        Name of the control.
   */
  PICML_Simple_Data_Value_Control (void);

  /// The id of the control.
  UINT id_;
};

/**
 * @class PICML_Simple_Data_Value_Control <CEdit>
 */
template < >
class PICML_Simple_Data_Value_Control <CEdit> :
  public CEdit,
  public PICML_Data_Value_Control
{
public:
  /// Type definition of the control type.
  typedef CEdit control_type;

  /// Destructor.
  virtual ~PICML_Simple_Data_Value_Control (void);

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
  PICML_Simple_Data_Value_Control (void);

  /// The id of the control.
  UINT id_;
};

/**
 * @class PICML_Char_Data_Value_Control
 */
class PICML_Char_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_Char_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_Char_Data_Value_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);
};

/**
 * @class PICML_String_Data_Value_Control
 */
class PICML_String_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  /// Default contructor.
  PICML_String_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_String_Data_Value_Control (void);
};

/**
 * @class PICML_Short_Data_Value_Control
 */
class PICML_Short_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  /// Destructor.
  virtual ~PICML_Short_Data_Value_Control (void);

  PICML_Short_Data_Value_Control (void);
};

/**
 * @class PICML_UShort_Data_Value_Control
 */
class PICML_UShort_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  PICML_UShort_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_UShort_Data_Value_Control (void);
};

/**
 * @class PICML_Long_Data_Value_Control
 */
class PICML_Long_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_Long_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_Long_Data_Value_Control (void);
};

/**
 * @class PICML_ULong_Data_Value_Control
 */
class PICML_ULong_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CEdit>
{
public:
  /// Default constructor.
  PICML_ULong_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_ULong_Data_Value_Control (void);
};

/**
 * @class PICML_Boolean_Data_Value_Control
 */
class PICML_Boolean_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CComboBox>
{
public:
  PICML_Boolean_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_Boolean_Data_Value_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);
};

/**
 * @class PICML_Enum_Data_Value_Control
 */
class PICML_Enum_Data_Value_Control :
  public PICML_Simple_Data_Value_Control <CComboBox>,
  public PICML::Visitor
{
public:
  /// Default contructor.
  PICML_Enum_Data_Value_Control (void);

  /// Destructor.
  virtual ~PICML_Enum_Data_Value_Control (void);

  // Create the control for usage.
  virtual BOOL Create (DWORD style, const RECT & rect, CWnd * parent, UINT id);

private:
  virtual void Visit_EnumValue (const PICML::EnumValue & ev);

};

#include "Data_Value_Controls_T.cpp"

#endif  // !defined _PICML_Data_Value_CONTROLS_H_
