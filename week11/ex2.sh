chr=`pwd`/lofsdisk
ls -lah $chr
mkdir -p $chr/bin $chr/lib $chr/lib64
cp -v /bin/bash $chr/bin
cp -v /bin/ls $chr/bin
cp -v /bin/cat $chr/bin

gcc ex2.c -o ex2.out
cp -v ex2.out $chr/ex2.out

mkdir $chr/usr
mkdir $chr/usr/lib
mkdir $chr/usr/lib64
cp -v /usr/lib/libreadline.so.8 $chr/usr/lib
cp -v /usr/lib/libdl.so.2 $chr/usr/lib
cp -v /usr/lib/libc.so.6 $chr/usr/lib
cp -v /usr/lib/libncursesw.so.6 $chr/usr/lib
cp -v /usr/lib64/ld-linux-x86-64.so.2 $chr/usr/lib64
cp -v /usr/lib/libcap.so.2 $chr/usr/lib

cd $chr
sudo chroot $chr /bin/bash

/ex2.out
exit
./ex2.out
