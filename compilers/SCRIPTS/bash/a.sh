#!/bin/bash

if [ $1 = 1 -o  $1 = "read" ]; then
    echo "do_read"
elif [ $1 = 2 -o $1 = "write" ]; then
    echo "do_write"
else
    echo "do_other"
fi
