// $Id$

//
// get_data
//
CUTS_INLINE
void ODBC_Stmt::get_data (USHORT column, long & buffer)
throw (ODBC_Stmt_Exception)
{
  // Get the data at the current line in the cursor.
  this->get_data (column,
                  &buffer,
                  sizeof (long),
                  0,
                  SQL_C_LONG);
}

CUTS_INLINE
void ODBC_Stmt::get_data (USHORT column, short & buffer)
throw (ODBC_Stmt_Exception)
{
  // Get the data at the current line in the cursor.
  this->get_data (column,
                  &buffer,
                  sizeof (short),
                  0,
                  SQL_C_SHORT);
}

CUTS_INLINE
void ODBC_Stmt::get_data (USHORT column, float & buffer)
throw (ODBC_Stmt_Exception)
{
  // Get the data at the current line in the cursor.
  this->get_data (column,
                  &buffer,
                  sizeof (float),
                  0,
                  SQL_C_FLOAT);
}

CUTS_INLINE
void ODBC_Stmt::get_data (USHORT column, double & buffer)
throw (ODBC_Stmt_Exception)
{
  // Get the data at the current line in the cursor.
  this->get_data (column,
                  &buffer,
                  sizeof (double),
                  0,
                  SQL_C_DOUBLE);
}

CUTS_INLINE
void ODBC_Stmt::get_data (USHORT column, int & buffer)
throw (ODBC_Stmt_Exception)
{
#if (ACE_SIZEOF_INT == ACE_SIZEOF_LONG)
  this->get_data (column,
                  &buffer,
                  sizeof (long),
                  0,
                  SQL_C_LONG);
#else /* ACE_SIZEOF_INT == ACE_SIZEOF_SHORT */
  this->get_data (column,
                  &buffer,
                  sizeof (short),
                  0,
                  SQL_C_SHORT);
#endif
}
