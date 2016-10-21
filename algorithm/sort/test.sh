#!/bin/bash

i=0

while [ $i -lt 10 ]
do
    ./a.out
    echo "test$i"
    i=`expr $i + 1`
done
