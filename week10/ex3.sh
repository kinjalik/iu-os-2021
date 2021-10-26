echo "Albert" > _ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt
chmod 707 _ex3.txt
ls -l _ex3.txt

rights=$(stat -c '%a' _ex3.txt)
userrights=$(expr $rights % 10)
ownerrights=$(expr $rights / 100)

newrights=$(expr $ownerrights \* 100  + $userrights \* 10 + $userrights)

chmod $newrights _ex3.txt
ls -l _ex3.txt
