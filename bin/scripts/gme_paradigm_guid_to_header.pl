#!/usr/bin/perl

###############################################################################
#
#  @file      gme_paradigm_guid_to_header.pl
#
#
#
#  @author    James H. Hill
###############################################################################

use strict;
use warnings;
use File::Basename;

#
# print_guid_header
#
sub print_guid_header {
  my ($filename) = basename (shift, ".xmp");
  my ($name)     = shift;
  my ($uuid)     = shift;

  open (FILE, ">${filename}_GUID.h");

  print FILE "// -*- C++ -*-\n";
  print FILE "\n";
  print FILE "\#ifndef _${name}_PARADIGM_GUID_H_\n";
  print FILE "\#define _${name}_PARADIGM_GUID_H_\n";
  print FILE "\n";
  print FILE "\#define ${name}_PARADIGM_GUID \"${uuid}\"\n";
  print FILE "\n";
  print FILE "\#endif  // !defined _${name}_PARADIGM_GUID_H_\n";
}

# open the target file for reading.
open FILE, $ARGV[0] or die $!;

while (<FILE>) {
  if ($_ =~ /name=\"(\w+)\"\s+guid=\"{([a-fA-F0-9]{8}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{4}\-[a-fA-F0-9]{12})\}"/) {
    print_guid_header ($ARGV[0], $1, $2);
    last;
  }
}
