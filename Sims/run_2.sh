#!/bin/bash
g++ sim3_0.cpp -o a1
for file in ./*.txt
do
./a1 < $file >> output2.txt
done
