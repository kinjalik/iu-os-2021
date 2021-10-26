echo "Albert" > ../week01/file.txt
link ../week01/file.txt _ex2.txt

lsi=($(ls -i ../week01/file.txt))

find ../ -inum "${lsi[0]}"

