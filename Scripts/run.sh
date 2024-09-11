#!/bin/bash

cd ..
make 
if [ $? -eq 0 ] ; then
    echo "Compiled Successfully"
    ./Build/HASH
else
    echo "Error while compiling"
fi
