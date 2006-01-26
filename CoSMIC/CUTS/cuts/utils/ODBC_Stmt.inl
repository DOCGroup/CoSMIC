// $Id$

//
// query
//
CUTS_INLINE
bool ODBC_Stmt::query (LPCSTR sqlstr)
{
	this->return_ = ::SQLExecDirect (this->stmt_, (SQLCHAR *)sqlstr, SQL_NTS);
	return SQL_SUCCEED (this->return_);
}

//
// fetch
//
CUTS_INLINE
bool ODBC_Stmt::fetch (void)
{
	this->return_ = ::SQLFetch (this->stmt_);
	return SQL_SUCCEED (this->return_);
}

//
// get_data
// 
CUTS_INLINE
bool ODBC_Stmt::get_data (USHORT column, void * buffer, 									
													ULONG bufsize, long * datalen,
                          int type)
{
	this->return_ = SQLGetData (this->stmt_, column, type, buffer, bufsize, 0);
	return SQL_SUCCEED (this->return_);
}
