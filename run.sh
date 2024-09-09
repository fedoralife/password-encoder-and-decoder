#!/bin/bash

make 
if [ $? -eq 0 ] ; then
    echo "Compiled Successfully"
    ./test/HASH
else 
    echo "Error while compiling"
fi
