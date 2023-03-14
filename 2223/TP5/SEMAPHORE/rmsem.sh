#!/bin/bash

PERMS=601

nbTot=`ipcs -s | grep $USER | wc -l`
nb=`ipcs -s | grep $USER | grep $PERMS | wc -l`

if [ $nb -eq 0 ]
then
    echo -n "aucun sémaphore à détruire"
    if [ $nbTot -eq 0 ]
    then
        echo ", et aucun actif"
    else
        plurielTot=""
        if [ $nbTot -gt 1 ]; then plurielTot="s"; fi
        echo ", mais $nbTot actif$plurielTot"
    fi
else
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "vous avez $nb sémaphore$pluriel non détruit$pluriel (sur un total de $nbTot)";

    for id in `ipcs -s | grep $USER | grep $PERMS | awk '{print $2;}'`
    do
        echo "  destruction sémaphore " $id
        ipcrm -s $id
    done

    nb=`ipcs -s | grep $USER | grep $PERMS | wc -l`
    nbTot=`ipcs -s | grep $USER | wc -l`
    pluriel=""
    if [ $nb -gt 1 ]; then pluriel="s"; fi
    echo "il reste $nb sémaphore$pluriel non détruit$pluriel (sur un total de $nbTot)";
fi
