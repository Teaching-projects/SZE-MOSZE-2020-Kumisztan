#!/bin/bash

IFS=$'\n'

rm output.txt

echo ./main Vargussen Umbg >> $2
echo ./main Umbg Vargussen >> $2
echo ./main Petyero Umbg >> $2
echo ./main Umbg Petyero >> $2
echo ./main Vargussen Petyero >> $2
echo ./main Petyero Vargussen >> $2

diff=$(diff  output.txt good_output.txt)
if [ "$diff" ]
then 
  echo "Wrong output!"
fi