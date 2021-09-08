#!/bin/bash

gcc ex2.c -o ex2.o

./ex2.o &
sleep 2
pstree
wait $(jobs -p)

