#!/bin/sh
set -e
make bzImage -j8
make modules
sudo make modules_install
sudo cp arch/x86/boot/bzImage /boot/vmlinuz-3.15.0-linux
sudo cp System.map /boot/System.map-3.15.0-linux
sudo update-initramfs -c -k 3.15.0
