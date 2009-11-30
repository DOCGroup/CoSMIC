#!/usr/bin/perl

use strict;
use warnings;

my %children;
my $class;
my $namespace;
my $visitor_mode = 0;
my $accept_found = 0;

# Add the class and its list of children in the hash table.
sub add_children {
  my $class = shift(@_); 
  my $list = shift(@_);
  my @child_array = split (/\s*,\s*/,$list);
  my $full_class = "::" . $namespace . "::" . $class;
  $children{$full_class} = \@child_array;   # Create a reference to the array and put it in the hash.
}

sub add_leave_functions {
  my $line = shift(@_);
  
  if ($line =~ m/^\s*virtual.*const\s*(.*)\s+&.*$/) {
    if ($1 ne "Udm::Object") {
      return $line . "\t\tvirtual void Leave_" . $1 . "(const " . $1 . " &) {}\n";
    }
  }
  # End of the visitor class.
  elsif ($line =~ m/^\s*};$/) {
    $visitor_mode = 0;
    return $line;
  }

  return $line;
}

sub prune {
  my $line = shift(@_);

  if ($visitor_mode == 1) {
    return add_leave_functions($line);
  }
  
  # Match a class declaration and inheritance line. This match, except for 
  # class=Visitor and class=MgaObject, must pair with a list of children, 
  # which is the next regex.  
  if ($line =~ m/^\s*class\s*(.*)\s*:\s*(virtual\s*public|public).*{$/) {
    my @decl = split(/ /, $1); # *_Export link-time visibility specification could be there before class name.
    $class = $decl[-1]; # The last element in the array must be the class name.
    $accept_found = 0;
    # If Visitor class is found then add Leave_* functions in it.
    if ($class eq "Visitor") {
      $visitor_mode = 1;
      return $line;
    }
    elsif (($class ne "MgaObject") && ($class ne "Visitor"))
    {
      $line =~ s/{//;
      $line =~ s/\n//;
      $line = $line.", public LEESA::VisitorAsIndex_CRTP< $class, Visitor > {\n";
    }
    return $line;
  }
  
  # Match ChildrenKinds line inside class $class and extract the comma seperated list of children. 
  # This line is expected to match only after a class has been identified.
  
  elsif ($line =~ m/^\s*typedef\s*boost::mpl::vector\s*<\s*(.*)\s*>\s*ChildrenKinds;$/) {
    # Add the class and its list of children in the hash table.
    add_children($class, $1);
    return $line;
  }
  
  # Extract namespace.
  elsif ($line =~ m/^namespace\s+(.*)\s+{$/) {
    $namespace = $1;
    $line = "#include \"LEESA_VisitorAsIndex.h\"\n\n".$line;
    return $line;
  }  
  
  # Bring the overloaded [] operator for VisitorAsIndex in the scope. This using declaration
  # hides the same operator in the base class, if any.
  elsif ($line =~ m/^\s*.*Accept.+Visitor.*this.*}$/) {
    my $l = $line;
    $l = $l . "\t\tvoid Leave(Visitor &v) { v.Leave_" . $class . "(*this); }\n";
    $l = $l . "\t\tusing LEESA::VisitorAsIndex_CRTP< $class, Visitor >::operator [];\n\n";
    $accept_found = 1;
    return $l;
  }
  
  # Add a Leave function in classes representing abstract kinds.
  # This function is needed because Udm::Object has empty Visit
  # function but does not have any Leave function. 
  elsif ($line =~ m/^\s*static ::Uml::Class meta;$/) {
    if ($accept_found == 0) {
      my $l = "\t\tvoid Leave(Visitor &v) { }\n\n" . $line;
      $accept_found = 0;
      return $l;
    }
  }
  
  # Discard most of the other meta-information in the class.
  elsif ($line =~ m/^\s*class\s.+\s{};$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*boost::mpl::pair.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*\/\/ types and typelist.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*Parents;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*Parents.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*ChildrenSingle;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*ChildrenSingle.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*ChildrenMulti;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*ChildrenMulti.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*AssociationsSingle;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*AssociationsSingle.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*AssociationsMulti;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*AssociationsMulti.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*AssociationsWAClassSingle;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*AssociationsWAClassSingle.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*AssociationsWAClassMulti;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*AssociationsWAClassMulti.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*CrossAssociationsSingle;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*CrossAssciationsSingle.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*CrossAssociationsMulti;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*CrossAssociationsMulti.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*CrossAssociationsWAClassSingle;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*CrossAssociationsWAClassSingle.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*CrossAssociationsWAClassMulti;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*CrossAssociationsWAClassMulti.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*AClassEnds;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*AClassEnds.*$/) {
    return "";
  }
  elsif ($line =~ m/^\s*typedef.*CrossAClassEnds;$/) {
    return "";
  }
  elsif ($line =~ m/^\s*.*boost::function_requires.*CrossAClassEnds.*$/) {
    return "";
  }

  # If $line machtes nothing then save it as it is.
  return $line;
}

my $argc = @ARGV;
if ($argc != 1) {
  print "Usage: gen-pairs <PARADIGM-NAME> \n";
  exit 1;
}

my $header = $ARGV[0] . ".h";
my $cpp = $ARGV[0] . ".cpp";

unless (-e $header) {
  print "Error: $header file does not exist.\n";
  exit 1;
}
unless (-e $cpp) {
  print "Error: $cpp file does not exist.\n";
  exit 1;
}

my $header_bak = $header.".bak";
my $cpp_bak = $cpp.".bak";
rename ($header,$header_bak);
rename ($cpp,$cpp_bak);

open HEADER_BAK_FILE, "<", $header_bak or die("Could not open " . $header_bak . " file for reading");
open HEADER_FILE, ">", $header or die("Could not open " . $header . "  file for writing");

print HEADER_FILE "// This header file is modified by gen-pairs.pl program of LEESA, which generates IsDescendant<T,U>\n";
print HEADER_FILE "// pairs at the end of the header file. Command: perl gen-pairs.pl <PARADIGM-NAME>\n";
print HEADER_FILE "// More information about LEESA can be found at http://www.dre.vanderbilt.edu/~sutambe/files/LEESA/LEESA.pdf \n\n";

foreach my $line (<HEADER_BAK_FILE>)
{
  $line = prune ($line);
  if ($line =~ m/^#endif \/\/ MOBIES_/) {
    last;
  }
  print HEADER_FILE $line;
}

sub push_descendants {
  my $class = shift(@_);
  my $dest_array_ref = shift(@_);
  my $visited = shift (@_);
  my $source_array_ref = $children{$class};

  push (@$visited, $class);
  
  if ($source_array_ref && (@$source_array_ref != 0)) {
    push (@$dest_array_ref, @$source_array_ref);
    foreach my $c (@$source_array_ref) {
      if (not grep (/^$c$/, @$visited)) {
        push_descendants($c, $dest_array_ref, $visited);
      }
    }
  }
}

my $heredoc = <<HEADER;
// The following is generated by gen-pairs.pl program of LEESA. For more information
// please visit: http://www.dre.vanderbilt.edu/~sutambe/files/LEESA/LEESA.pdf

#ifndef DOMAIN_HAS_DESCENDANT_PAIRS
#define DOMAIN_HAS_DESCENDANT_PAIRS
#endif // DOMAIN_HAS_DESCENDANT_PAIRS

namespace $namespace {

  struct _False_ { enum { value = 0 }; };
  struct _True_  { enum { value = 1 }; };

  template <class T, class U>
  struct IsDescendant : _False_ {};

HEADER
print HEADER_FILE $heredoc;
 
foreach $class (sort keys %children) {
  my @descendants = ();
  my @visited = ();
  push_descendants ($class, \@descendants, \@visited);
  
  # Remove duplicates from the @descendants array.
  my %hash   = map { $_ => 1 } @descendants;
  my @unique = sort keys %hash;
  
  foreach my $desc (@unique) {
    print HEADER_FILE "  template <> struct IsDescendant < $class, $desc > : _True_ {};\n";
  }
  if (@unique != 0) {
    print HEADER_FILE "\n";
  }
}

print HEADER_FILE "\n} // namespace " . $namespace . "\n\n#endif // MOBIES_".$namespace."_H\n\n";

close HEADER_BAK_FILE;
close HEADER_FILE;

open CPP_BAK_FILE, "<", $cpp_bak or die("Could not open " . $cpp_bak . " file for reading");
open CPP_FILE, ">", $cpp or die("Could not open " . $cpp . "  file for writing");

foreach my $line (<CPP_BAK_FILE>) 
{
  $line =~ s/\s*template <> const.*$//;
  print CPP_FILE $line;
}

close CPP_BAK_FILE;
close CPP_FILE;
