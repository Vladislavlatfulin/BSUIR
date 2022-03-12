#!/bin/bash
cd child
make
cd ../parent
make
CHILD_PATH=../child/child ./parent "../env.txt"
make clean
cd ../child
make clean
cd ..
