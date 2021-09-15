#!/bin/bash


while test -f "file.lock" ; do
    sleep 1
done

ln file file.lock

i="$(cat file | awk '{print $NF}')"
((i+=1))

echo "$(cat file) $i" > file

rm file.lock
