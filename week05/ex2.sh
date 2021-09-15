#!/bin/bash

i="$(cat file | awk '{print $NF}')"
((i+=1))

echo "$(cat file) $i" > file
