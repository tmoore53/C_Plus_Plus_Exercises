#!/bin/bash

gcc driver_cpg.c heap.c -o ./a.out

#gcc driver_cpg.c heap-2.c -o ./b.out

./a.out > output.txt
./a.out
#./b.out > output2.txt
