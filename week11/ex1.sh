cat /dev/urandom > lofs.img &
sleep 1
kill $(jobs -p)

sudo losetup -f lofs.img

sudo mkfs.ext4 $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)

sudo mount $(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1) ./lofsdisk

sudo chmod 777 -R lofsdisk
