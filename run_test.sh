#!/bin/bash

IFS = $\'n'

rm output.txt

for i in 'cat Fights.txt'; do
    echo "$i" | $1 >> $2
done