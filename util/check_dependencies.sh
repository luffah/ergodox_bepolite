#!/usr/bin/env bash

DEPENDENCIES="
dfu-programmer
avr-gcc
git
diff
wget
zip
cmp
"
MISSING_DEPS=""
for i in ${DEPENDENCIES}
do
  command -v $i 1> /dev/null 2> /dev/null || MISSING_DEPS="${MISSING_DEPS} ${i}"
done

if [ -n "$MISSING_DEPS" ]
then
  echo "The following dependencies are missing :"
  for i in ${MISSING_DEPS}
  do
    echo " '${i}' "
  done
  echo "***** try to launch 'sudo ./util/install_dependencies.sh' to solve the problem. [Note : this script will update package database and upgrade some package]"
  exit 1
else
  exit 0
fi



