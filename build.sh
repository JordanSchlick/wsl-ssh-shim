gcc -o ssh-shim ssh-shim.c
# sudo ln -s /mnt/c/windows/System32/OpenSSH/ssh.exe /usr/local/bin/ssh
# ./ssh-shim user@192.168.11.4
sudo rm /usr/local/bin/ssh
sudo cp ssh-shim /usr/local/bin/ssh