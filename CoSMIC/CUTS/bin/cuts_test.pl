#!/usr/bin/perl -w
# $Id$
# -*- perl -*-
# import module and libraries
use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;
# parse the command line arguments
while ($arg = shift) {
  $arg eq "-d" and $plan = shift;
  $arg eq "-t" and $test = shift;
  $arg eq "--help" and print_help() and exit;
}
!defined($plan) and die "*** syntax error: you must specify a plan\n";
!defined($test) and die "*** syntax error: you must specify a test\n";
# run the executor.pl script located in $WLG_ROOT/ComponentWLG/bin
use lib "$ENV{WLG_ROOT}/ComponentWLG/bin";
require "wlg_executor.pl";
sub print_help
{
  print "  SYNTAX: run_wlg_test -t <test> -d <deployment>\n\n";
  print "  EXAMPLES:\n";
  print "    run_wlg_test -t \"RT1A Model\" -d ThreeNodePlan\n";
  print "    run_wlg_test -t \"RT1A Model\\example\" -d OneNodePlan\n";
  1;
}
1;


