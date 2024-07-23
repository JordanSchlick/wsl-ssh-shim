#define _GNU_SOURCE
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>



int main(int argc, char* argv[], char* envp[]){
	int i = 0;
	
	// add to path
	// char* path = getenv("PATH");
	// char* addition = "/mnt/c/Program Files/Yubico/Yubico PIV Tool/bin";
	// char* newpath = malloc(strlen(path) + strlen(addition) + 20);
	// strcpy(newpath, "PATH=");
	// strcat(newpath, path);
	// strcat(newpath, ":");
	// strcat(newpath, addition);
	// putenv(newpath);
	// fprintf(stderr, "PATH: %s\n", getenv("PATH"));

	if(!isatty(STDOUT_FILENO)){
		// fprintf(stderr, "stderr is not a terminal\n");
		putenv("WSLENV=WT_SESSION:WT_PROFILE_ID:SSH_ASKPASS:SSH_ASKPASS_REQUIRE:ATEST");
		if(getenv("SSH_ASKPASS") == NULL){
			if(access("/mnt/c/Program Files/Git/mingw64/bin/git-askpass.exe", F_OK) == 0){
				putenv("SSH_ASKPASS=C:\\Program Files\\Git\\mingw64\\bin\\git-askpass.exe");
			}else{
				putenv("SSH_ASKPASS=ssh-askpass");
			}
		}
		putenv("SSH_ASKPASS_REQUIRE=force");
		putenv("export ATEST=testvalue");
	}
	
	char* sshPath = "ssh.exe";
	if(access("/mnt/c/Program Files/OpenSSH/ssh.exe", F_OK) == 0){
		sshPath = "/mnt/c/Program Files/OpenSSH/ssh.exe";
	}else if(access("/mnt/c/bin/ssh.exe", F_OK) == 0){
		sshPath = "/mnt/c/bin/ssh.exe";
	}else if(access("/mnt/c/windows/System32/OpenSSH/ssh.exe", F_OK) == 0){
		sshPath = "/mnt/c/windows/System32/OpenSSH/ssh.exe";
	}
	// execute ssh with arguments
	int exitCode = execvp(sshPath, argv);
	// int exitCode = execvp("cmd.exe", argv);
	fprintf(stderr, "Error code: %d\n", exitCode);
}