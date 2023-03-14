#!/bin/bash
gcc -Wall -pedantic -std=c99  connexion.c -o connexion -lm
gcc -Wall -pedantic -std=c99  genereNombres.c -o genereNombres -lm
gcc -Wall -pedantic -std=c99  stat.c -o stat -lm
gcc -Wall -pedantic -std=c99  database.c -o database -lm
