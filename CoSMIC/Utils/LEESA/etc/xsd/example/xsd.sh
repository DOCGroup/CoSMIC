#!/bin/sh
/project/xsd/xsd-3.2.0/xsd/xsd cxx-tree --generate-default-ctor --hxx-suffix .hpp --cxx-suffix .cpp --generate-template --generate-ostream $1 $2 $3 $4
