#!/usr/bin/perl
# $Id$

###############################################################################
#
#  @file      gme_paradigm_guid_to_header.pl
#
#  $Id$
#
#  @author    James H. Hill
###############################################################################

use strict;
use warnings;

sub print_guid_header {
  my ($filename) = shift;
  my ($name)     = shift;
  my ($uuid)     = shift;

  open (FILE, ">${filename}.h");

  print FILE "\#ifndef _${name}_PARADIGM_GUID_H_\n";
  print FILE "\#define _${name}_PARADIGM_GUID_H_\n";
  print FILE "\n";
  print FILE "\#define ${name}_PARADIGM_GUID \"${uuid}\"\n";
  print FILE "\n";
  print FILE "\#endif  // !defined _${name}_PARADIGM_GUID_H_\n";
}

# open the target file for reading.
open FILE, $ARGV[1] or die $!;

while (<FILE>) {
  if ($_ =~ /name=\"(\w+)\"\s+guid=\"{([a-fA-F0-9]{8}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{12})\}"/) {
    print_guid_header ($ARGV[0], $1, $2);
    last;
  }
}
