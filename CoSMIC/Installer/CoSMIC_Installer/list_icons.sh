#!/bin/sh
count=1
icon=_icon_
for f in $( ls $2 ); do
  str="<File Id='$1$icon$count'"
  echo $str
  str="      Name='$f'"
  echo $str
  str="      DiskId='1'"
  echo $str
  str="      Source='\$(var.COSMIC_ROOT)\\$2\\$f' />"
  echo $str
  echo " "

  let count=count+1
done

