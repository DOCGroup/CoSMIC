#!/bin/sh

output=`grep WITH_LEESA makefile`

if [ -z "$output" ] ; then
  perl -pi -e 's/WITHOUT_LEESA/WITH_LEESA/g' makefile
  touch compilation_test.cpp
else
  perl -pi -e 's/WITH_LEESA/WITHOUT_LEESA/g' makefile
  touch compilation_test.cpp
fi

