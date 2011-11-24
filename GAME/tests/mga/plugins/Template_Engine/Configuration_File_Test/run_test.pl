eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::Run_Test;

$GAME_ROOT = "$ENV{'GAME_ROOT'}";

# Start the DAC
$test_opts = "--detect_memory_leaks=0 --report_level=detailed --log_level=all";
$test_app = new PerlACE::Process ("GAME_Template_Engine_Configuration_File_Test", $test_opts);
$test_app->SpawnWaitKill ();

exit 0;
