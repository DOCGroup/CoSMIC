/* -*- C++ -*- */

//=============================================================================
/**
 * @file          Data_Value.h
 *
 * INSERT FILE DESCRIPTION HERE
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DATA_VALUE_H_
#define _DATA_VALUE_H_

#include <string>
#include <map>
#include <set>
#include <vector>
#include "Utils_Export.h"

// Forward decl.
class PICML_Data_Value_Visitor;

//=============================================================================
/**
 * @class PICML_Data_Value
 *
 * INSERT CLASS DESCRIPTION HERE
 */
//=============================================================================

class Utils_Export PICML_Data_Value
{
public:
  /// Default constructor.
  PICML_Data_Value (void);

  /// Destructor.
  virtual ~PICML_Data_Value (void);

  const std::string & value (void) const;

  virtual void value (const std::string & value);

  virtual void accept (PICML_Data_Value_Visitor & visitor) = 0;

  virtual PICML_Data_Value * _create (void) const = 0;

private:
  /// Value of the data value.
  std::string value_;

  // prevent the following operations
  PICML_Data_Value (const PICML_Data_Value & );
  const PICML_Data_Value & operator = (const PICML_Data_Value &);
};

//=============================================================================
/**
 * @class PICML_String_Data_Value
 */
//=============================================================================

class Utils_Export PICML_String_Data_Value : public PICML_Data_Value
{
public:
  PICML_String_Data_Value (void);

  virtual ~PICML_String_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_Char_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Char_Data_Value : public PICML_Data_Value
{
public:
  PICML_Char_Data_Value (void);

  virtual ~PICML_Char_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_Short_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Short_Data_Value : public PICML_Data_Value
{
public:
  PICML_Short_Data_Value (void);

  virtual ~PICML_Short_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_UShort_Data_Value
 */
//=============================================================================

class Utils_Export PICML_UShort_Data_Value : public PICML_Data_Value
{
public:
  PICML_UShort_Data_Value (void);

  virtual ~PICML_UShort_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_Long_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Long_Data_Value : public PICML_Data_Value
{
public:
  PICML_Long_Data_Value (void);

  virtual ~PICML_Long_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_ULong_DT_Control
 */
//=============================================================================

class Utils_Export PICML_ULong_Data_Value : public PICML_Data_Value
{
public:
  PICML_ULong_Data_Value (void);

  virtual ~PICML_ULong_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_Boolean_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Boolean_Data_Value : public PICML_Data_Value
{
public:
  PICML_Boolean_Data_Value (void);

  virtual ~PICML_Boolean_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;
};

//=============================================================================
/**
 * @class PICML_Enum_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Enum_Data_Value : public PICML_Data_Value
{
public:
  typedef std::set <std::string> container_type;

  PICML_Enum_Data_Value (void);

  virtual ~PICML_Enum_Data_Value (void);

  void insert_option (const std::string & v);

  const container_type & options (void) const;

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual PICML_Data_Value * _create (void) const;

private:
  std::set <std::string> options_;
};

//=============================================================================
/**
 * @class PICML_Aggregate_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Aggregate_Data_Value : public PICML_Data_Value
{
public:
  typedef std::map <std::string, PICML_Data_Value *> container_type;

  typedef container_type::iterator iterator;

  typedef container_type::const_iterator const_iterator;

  PICML_Aggregate_Data_Value (void);

  virtual ~PICML_Aggregate_Data_Value (void);

  virtual PICML_Data_Value * _create (void) const;

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  virtual void value (const std::string & value);

  void insert_member (const std::string & name,
                      PICML_Data_Value * member);

  void remove_member (const std::string & name);

  bool find_member (const std::string & name,
                    PICML_Data_Value * & member) const;

  PICML_Data_Value * operator [] (const std::string & member);

  iterator begin (void);
  iterator end (void);

  const_iterator begin (void) const;
  const_iterator end (void) const;

private:
  std::map <std::string, PICML_Data_Value *> members_;
};

//=============================================================================
/**
 * @class PICML_Sequence_Data_Value
 */
//=============================================================================

class Utils_Export PICML_Sequence_Data_Value : public PICML_Data_Value
{
public:
  typedef std::vector <PICML_Data_Value *> container_type;

  typedef container_type::iterator iterator;

  typedef container_type::const_iterator const_iterator;

  PICML_Sequence_Data_Value (PICML_Data_Value * type);

  virtual ~PICML_Sequence_Data_Value (void);

  virtual PICML_Data_Value * _create (void) const;

  virtual void value (const std::string & value);

  virtual void accept (PICML_Data_Value_Visitor & visitor);

  PICML_Data_Value * operator [] (int index);
  const PICML_Data_Value * operator [] (int index) const;

  size_t size (void) const;

  PICML_Data_Value * new_element (void);

  iterator begin (void);
  iterator end (void);

  const_iterator begin (void) const;
  const_iterator end (void) const;

private:
  PICML_Data_Value * type_;

  container_type sequence_;
};

#endif  /* !defined _DATA_VALUE_H_ */
