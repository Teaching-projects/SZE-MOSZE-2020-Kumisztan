#!/bin/bash

touch output.txt 
> output.txt

./a.out Petyero.json Vargussen.json >> output.txt
./a.out Petyero.json Umbg.json >> output.txt
./a.out Vargussen.json Petyero.json >> output.txt
./a.out Vargussen.json Umbg.json >> output.txt
./a.out Umbg.json Petyero.json >> output.txt
./a.out Umbg.json Vargussen.json >> output.txt