#!/bin/bash
g++ sim2_2.cpp -o a1
for file in ./*.txt
do
./a1 < $file >> output.txt
done
