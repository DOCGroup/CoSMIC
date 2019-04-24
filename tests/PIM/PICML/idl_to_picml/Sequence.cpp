#include "SequenceC.h"
#include "ace/Log_Msg.h"
#include <typeinfo.h>

//
// ACE_TMAIN
//
int ACE_TMAIN (int argc, ACE_TCHAR * argv [])
{
  static const long SIZE_OF_SEQ = 10;

  using namespace SequenceBasicTypes;

  SeqBoolean boolean_seq(SIZE_OF_SEQ);
  SeqShort short_seq(SIZE_OF_SEQ);
  SeqLong long_seq(SIZE_OF_SEQ);
  SeqChar char_seq(SIZE_OF_SEQ);
  SeqOctet octet_seq(SIZE_OF_SEQ);
  SeqDouble double_seq(SIZE_OF_SEQ);
  SeqFloat float_seq(SIZE_OF_SEQ);

  // use sequence and validate
  ACE_DEBUG ((LM_DEBUG, "*** begin validating sequence type\n"));

  // verify boolean_seq length
  if (boolean_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of boolean_seq set incorrectly\n"));
 
  // verify short_seq length
  if (short_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of short_seq set incorrectly\n"));
 
  // verify long_seq length
  if (long_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of long_seq set incorrectly\n"));
 
  // verify char_seq length
  if (char_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of char_seq set incorrectly\n"));
 
  // verify octet_seq length
  if (octet_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of octet_seq set incorrectly\n"));
 
  // verify double_seq length
  if (double_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of double_seq set incorrectly\n"));
 
  // verify float_seq length
  if (float_seq.length() != SIZE_OF_SEQ)
    ACE_ERROR ((LM_ERROR, "Size of float_seq set incorrectly\n"));
 
  ACE_DEBUG ((LM_DEBUG, "*** end validating sequence type\n"));

  return 0;
}
