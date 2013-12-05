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
#include "PICML_Export.h"

// Forward decl.
class PICML_Data_Value_Visitor;

// Forward decl.
class PICML_Sequence_Data_Value;

// Forward decl.
class PICML_Aggregate_Data_Value;

//=============================================================================
/**
 * @class PICML_Data_Value
 *
 * INSERT CLASS DESCRIPTION HERE
 */
//=============================================================================

class PICML_Export PICML_Data_Value
{
  friend class PICML_Aggregate_Data_Value;
  friend class PICML_Sequence_Data_Value;

public:
  /// Destructor.
  virtual ~PICML_Data_Value (void);

  virtual const std::string & value (void) const;

  virtual void value (const std::string & value);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const = 0;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const = 0;

  /// Reset the data value.
  virtual void reset (void);

  const std::string & name (void) const;

  bool is_uptodate (void) const;

protected:
  /// Default constructor.
  PICML_Data_Value (const std::string & name, PICML_Data_Value * parent = 0);

  /// Name associated w/ the data value.
  std::string name_;

  /// Value of the data value.
  std::string value_;

  mutable bool is_uptodate_;

  PICML_Data_Value * parent_;

private:
  // prevent the following operations
  PICML_Data_Value (const PICML_Data_Value & );
  const PICML_Data_Value & operator = (const PICML_Data_Value &);
};

//=============================================================================
/**
 * @class PICML_String_Data_Value
 */
//=============================================================================

class PICML_Export PICML_String_Data_Value : public PICML_Data_Value
{
public:
  PICML_String_Data_Value (const std::string & name,
                           PICML_Data_Value * parent = 0);

  virtual ~PICML_String_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_Char_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Char_Data_Value : public PICML_Data_Value
{
public:
  PICML_Char_Data_Value (const std::string & name,
                         PICML_Data_Value * parent = 0);

  virtual ~PICML_Char_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_Short_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Short_Data_Value : public PICML_Data_Value
{
public:
  PICML_Short_Data_Value (const std::string & name,
                          PICML_Data_Value * parent = 0);

  virtual ~PICML_Short_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_UShort_Data_Value
 */
//=============================================================================

class PICML_Export PICML_UShort_Data_Value : public PICML_Data_Value
{
public:
  PICML_UShort_Data_Value (const std::string & name,
                           PICML_Data_Value * parent = 0);

  virtual ~PICML_UShort_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_Long_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Long_Data_Value : public PICML_Data_Value
{
public:
  PICML_Long_Data_Value (const std::string & name,
                         PICML_Data_Value * parent = 0);

  virtual ~PICML_Long_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_ULong_DT_Control
 */
//=============================================================================

class PICML_Export PICML_ULong_Data_Value : public PICML_Data_Value
{
public:
  PICML_ULong_Data_Value (const std::string & name,
                          PICML_Data_Value * parent = 0);

  virtual ~PICML_ULong_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_Boolean_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Boolean_Data_Value : public PICML_Data_Value
{
public:
  PICML_Boolean_Data_Value (const std::string & name,
                            PICML_Data_Value * parent = 0);

  virtual ~PICML_Boolean_Data_Value (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;
};

//=============================================================================
/**
 * @class PICML_Enum_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Enum_Data_Value : public PICML_Data_Value
{
public:
  typedef std::set <std::string> container_type;

  PICML_Enum_Data_Value (const std::string & name,
                         PICML_Data_Value * parent = 0);

  virtual ~PICML_Enum_Data_Value (void);

  void insert_option (const std::string & v);

  const container_type & options (void) const;

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;

private:
  std::set <std::string> options_;
};

//=============================================================================
/**
 * @class PICML_Aggregate_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Aggregate_Data_Value : public PICML_Data_Value
{
public:
  typedef std::map <std::string, PICML_Data_Value *> container_type;

  typedef container_type::iterator iterator;

  typedef container_type::const_iterator const_iterator;

  PICML_Aggregate_Data_Value (const std::string & name,
                              PICML_Data_Value * parent = 0);

  virtual ~PICML_Aggregate_Data_Value (void);

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  virtual const std::string & value (void);

  virtual void value (const std::string & value);

  virtual void reset (void);

  void insert_member (PICML_Data_Value * member);

  void remove_member (const std::string & name);

  bool find_member (const std::string & name,
                    PICML_Data_Value * & member) const;

  const PICML_Data_Value * operator [] (const std::string & member);

  iterator begin (void);
  iterator end (void);

  const_iterator begin (void) const;
  const_iterator end (void) const;

  size_t size (void) const;

private:
  std::map <std::string, PICML_Data_Value *> members_;

  // prevent the following operations
  PICML_Aggregate_Data_Value (const PICML_Aggregate_Data_Value &);
  const PICML_Aggregate_Data_Value & operator = (const PICML_Aggregate_Data_Value &);
};

//=============================================================================
/**
 * @class PICML_Event_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Event_Data_Value : public PICML_Aggregate_Data_Value
{
public:
  typedef PICML_Aggregate_Data_Value::container_type container_type;

  typedef container_type::iterator iterator;

  typedef container_type::const_iterator const_iterator;

  PICML_Event_Data_Value (const std::string & name,
                          PICML_Data_Value * parent = 0);

  virtual ~PICML_Event_Data_Value (void);

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  //virtual const std::string & value (void);

  //virtual void value (const std::string & value);

  //virtual void reset (void);

  //void insert_member (PICML_Data_Value * member);

  //void remove_member (const std::string & name);

  //bool find_member (const std::string & name,
  //                  PICML_Data_Value * & member) const;

  //const PICML_Data_Value * operator [] (const std::string & member);

  //iterator begin (void);
  //iterator end (void);

  //const_iterator begin (void) const;
  //const_iterator end (void) const;

  //size_t size (void) const;

private:
  //std::map <std::string, PICML_Data_Value *> members_;

  // prevent the following operations
  PICML_Event_Data_Value (const PICML_Event_Data_Value &);
  const PICML_Event_Data_Value & operator = (const PICML_Event_Data_Value &);
};

//=============================================================================
/**
 * @class PICML_Sequence_Data_Value
 */
//=============================================================================

class PICML_Export PICML_Sequence_Data_Value : public PICML_Data_Value
{
public:
  typedef std::vector <PICML_Data_Value *> container_type;

  typedef container_type::iterator iterator;

  typedef container_type::const_iterator const_iterator;

  PICML_Sequence_Data_Value (const std::string & name,
                             PICML_Data_Value * type,
                             PICML_Data_Value * parent = 0);

  virtual ~PICML_Sequence_Data_Value (void);

  virtual PICML_Data_Value * _create (const std::string & name,
                                      PICML_Data_Value * parent = 0) const;

  virtual const std::string & value (void);

  virtual void value (const std::string & value);

  virtual void reset (void);

  virtual void accept (PICML_Data_Value_Visitor & visitor) const;

  PICML_Data_Value * operator [] (int index);

  const PICML_Data_Value * operator [] (int index) const;

  size_t size (void) const;

  PICML_Data_Value * new_element (void);

  void remove (PICML_Data_Value * value);
  void remove (size_t index);

  iterator begin (void);
  iterator end (void);

  const_iterator begin (void) const;
  const_iterator end (void) const;

  bool move_up (PICML_Data_Value * value);

  bool move_down (PICML_Data_Value * value);

  bool get_index (const PICML_Data_Value * value, size_t & index) const;

private:
  void remove_i (size_t index);

  std::auto_ptr <PICML_Data_Value> type_;

  container_type sequence_;

  // prevent the following operations
  PICML_Sequence_Data_Value (const PICML_Sequence_Data_Value &);
  const PICML_Sequence_Data_Value & operator = (const PICML_Sequence_Data_Value &);
};

#endif  /* !defined _DATA_VALUE_H_ */
