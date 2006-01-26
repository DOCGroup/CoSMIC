// $Id$

#include "cuts/DatabaseWorker.h"
#include "ace/OS_NS_stdlib.h"

#if !defined (__CUTS_INLINE__)
#include "DatabaseWorker.inl"
#endif

#define MAX_DATA_SIZE 255

//
// CUTS_DatabaseWorker
//
CUTS_DatabaseWorker::CUTS_DatabaseWorker (void)
: hostname_ (CUTS_DEFAULT_HOSTNAME),
  conn_ (new MyODBC_Connection ())
{

}

//
// ~CUTS_DatabaseWorker
//
CUTS_DatabaseWorker::~CUTS_DatabaseWorker (void)
{
  if (this->conn_->is_connected ())
    this->conn_->disconnect ();
}

//
// process
//
void CUTS_DatabaseWorker::process (long reps)
{
  // calculate the size of the data
  static char fill_value = 'A';

  ostringstream sqlstr;
  char dataset[MAX_DATA_SIZE];
  auto_ptr <ODBC_Stmt> stmt (this->conn_->create_statement ());
  int size;

  // determine if there is an established connection. if there
  // is not a connection then create one and remember to kill
  // the connection if the end
  bool connected = this->conn_->is_connected ();

  if (!connected)
    create_connection ();

  // perform the database operations
  for (int i = 0; i < reps; i ++)
  {
    // calculate the size of the <dataset>
    size = ACE_OS::rand () % MAX_DATA_SIZE;

    // determine the fill character
    fill_value =
      static_cast <int> (fill_value) >= static_cast <int> ('Z')
      ? 'A' : fill_value + 1;

    // fill the dataset with the next value
    fill (dataset, dataset + size, fill_value);
    dataset[size] = '\0';

    // create a SQL statement for the testing record
    sqlstr << "insert into worker (wlgTag, data) values (" << this->parent_ << ", '" << dataset << "');" << ends;

    stmt->query (sqlstr.str ().c_str ());
    sqlstr.seekp(0);
  }

  // create a SQL statement to delete all the records w/ my <idWLG_>.
  sqlstr << "delete from worker where wlgTag =" << this->parent_ << ";" << ends;
  stmt->query (sqlstr.str ().c_str ());

  // if there was not a connection in the beginning, then we should
  // destory the connection before we leave.
  if (!connected)
    destroy_connection ();
}
