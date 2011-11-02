eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use lib "$ENV{'ACE_ROOT'}/bin";
use PerlACE::Run_Test;
use Cwd;
use File::Path qw(rmtree);

$GAME_ROOT = "$ENV{'GAME_ROOT'}";
$ACE_ROOT = "$ENV{'ACE_ROOT'}";

$cwd = getcwd;
$target_dir = getcwd . '/' . 'RootFolderTest';

# Remove the target directory.
rmtree ($target_dir, 1, 1);

# Make the target directory.
mkdir ($target_dir);

$test_model = "RootFolderTest.xme";
print "*** info: target directory is $target_dir\n";

$the_opts = "-x GAME.Interpreter.ExtensionClasses --param=OutputPath=$target_dir $test_model";
$the_app = new PerlACE::Process ("$GAME_ROOT/bin/gme_interpret", $the_opts);
$the_app->SpawnWaitKill ();

chdir ($target_dir);

# Build the generated code.
$target_mwc = "RootFolderTest_GAME_Mga.mwc";
$the_app = new PerlACE::Process ("perl", "-- $ACE_ROOT/bin/mwc.pl -features versioned_namespace=1,mfc=1 -type vc9 $target_mwc");
$the_app->IgnoreExeSubDir (1);
$the_app->SpawnWaitKill ();


$target_sln = "RootFolderTest_GAME_Mga.sln";
$the_app = new PerlACE::Process ("devenv.com", "/Build Debug $target_sln");
$the_app->IgnoreExeSubDir (1);
$the_app->SpawnWaitKill ();


exit 0;
