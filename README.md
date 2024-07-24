# WSL SSH Shim
This is a small shim that allows you to use the windows ssh binary from within WSL just like the linux version. This makes it possible for ssh to interface with host authentication devices such as YubiKeys and smartcards.

For example you can use this to allow virt-manager to log into your server using a YubiKey without having to pass the usb device to WSL2.

In my experience the default windows ssh agent is broken, this also supports using the ssh binary from C:/Program Files/OpenSSH/ssh.exe


## Installation
1. Make sure no ssh client is installed in WSL
2. Clone the repository
3. Install gcc
4. Open a WSL terminal in the repository directory
5. Run `build.sh` to compile the shim and install it to `/usr/local/bin/ssh`

## Askpass
If git for windows is installed and ssh is not being run from a tty, it will use the git askpass helper to prompt for the ssh password. This even works for YubiKey pins. No x11 forwarding is required because it runs a native windows binary.
