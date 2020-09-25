#!/bin/bash

IFS = $\'n'

rm output.txt

./a.out Petyero Vargussen >> output.txt
./a.out Petyero Umbg >> output.txt
./a.out Vargussen Petyero >> output.txt
./a.out Vargussen Umbg >> output.txt
./a.out Umbg Petyero >> output.txt
./a.out Umbg Vargussen >> output.txt

diff=$(diff  output.txt good_output.txt)
if [ "$diff" ]
then 
  echo "Wrong output!"
fi