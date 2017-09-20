#!/bin/bash
g++ sim2_2.cpp -o a2
for file in ./*.txt
do
./a2 < $file >> output1.txt
done
