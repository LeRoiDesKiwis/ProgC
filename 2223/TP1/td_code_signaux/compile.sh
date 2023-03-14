#!/bin/bash

files="eponge_signaux tuer_bob"

for file in $files
do
   gcc -Wall -Wextra -pedantic -std=c99 $file.c -o $file
done
