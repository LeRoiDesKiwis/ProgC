#!/bin/bash

for i in `seq 1 $2`
do
    bash -c "time ./genereNombres $1 | ./connexion $1 2> /dev/null >> wins$1.txt" 2>&1 | head -2 >> times$1.txt 
done
