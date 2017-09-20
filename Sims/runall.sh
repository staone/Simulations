#!/bin/bash
g++ sim3_0.cpp -o a2
for file in ./*.txt
do
./a2 < $file >> output.txt
done
