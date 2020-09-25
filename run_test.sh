#!/bin/bash

touch output.txt 
> output.txt

./a.out Petyero Vargussen >> output.txt
./a.out Petyero Umbg >> output.txt
./a.out Vargussen Petyero >> output.txt
./a.out Vargussen Umbg >> output.txt
./a.out Umbg Petyero >> output.txt
./a.out Umbg Vargussen >> output.txt