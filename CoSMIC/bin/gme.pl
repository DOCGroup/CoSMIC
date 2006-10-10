eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

#==============================================================================
# @file       gme.pl
#
# $Id$
#
# @author     James H. Hill
#==============================================================================

use strict;
use warnings;

# import libraries
use Win32::OLE;
use Win32::OLE::Variant qw(:DEFAULT nothing);

use Getopt::Long;

# global variables for the command-line
my ($help);
my ($version);
my ($version_major);
my ($version_minor);
my ($version_patch);
my ($run);
my ($connstr);
my ($params) = 0;

#
# parse_args
#
# Purpose:
#      parse command-line arguments for the script
#
sub parse_args ()
{
  GetOptions ('version'         => \$version,
              'version-major'   => \$version_major,
              'version-minor'   => \$version_minor,
              'version-patch'   => \$version_patch,
              'run:s'           => \$run,
              'help'            => \$help,
              'connstr:s'       => \$connstr,
              'params:i'        => \$params);

}

#
# get_gme
#
# Purpose:
#     get an instance to the GME COM object.
#
sub get_gme ()
{
  # Create an instance of GME.
  my ($gme) = Win32::OLE->new ('GME.Application')
    or die 'GME is not installed\n';

  return $gme;
}

#
# get_gme_launcher
#
# Purpose:
#     get an instance to the GME launcher COM object.
#
sub get_gme_launcher ()
{
  # Create an instance of GME.
  my ($launcher) = Win32::OLE->new ('Mga.MgaLauncher')
    or die 'GME is not installed\n';

  return $launcher;
}

#
# create_gme_project
#
# Purpose:
#     create a new GME project
#
sub get_gme_project ()
{
  # Create an instance of GME.
  my ($project) = Win32::OLE->new ('Mga.MgaProject')
    or die 'GME is not installed\n';

  return $project;
}

# parse the arguments
parse_args ();


# Execute the command-line.
if ($help)
{
  print 'TODO: print the help screen for gme.pl';
}
elsif ($version)
{
  print get_gme ()->Version ();
}
elsif ($version_major)
{
  print get_gme ()->VersionMajor ();
}
elsif ($version_minor)
{
  print get_gme ()->VersionMinor ();
}
elsif ($version_patch)
{
  print get_gme ()->VersionPatchLevel ();
}
elsif ($run)
{
  if ($connstr)
  {
    # Create a new GME project.
    my ($project) = get_gme_project ();
    $project->Open ($connstr);

    # Create a new GME launcher.
    my ($launcher) = get_gme_launcher ();

    # Run the specified component on the specified project
    $launcher->RunComponent ($run, $project, nothing, nothing, $params);
    $project->Close ();
  }
  else
  {
    print '*** error: missing connection string';
  }
}

1;
