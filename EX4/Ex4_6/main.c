#include <stdio.h>
#include <unistd.h>
#include <sys/utsname.h>

int main() {
    char hostname[10000];
    struct utsname uts;

    if(gethostname(hostname, sizeof(hostname)) == -1) {
        perror("gethostname");
        return 1;
    }
    printf("Hostname: %s\n", hostname);
    if(uname(&uts) == -1) {
        perror("uname");
        return 1;
    }
    printf("System name: %s\n", uts.sysname);
    printf("Node name: %s\n", uts.nodename);
    printf("Release: %s\n", uts.release);
    printf("Version: %s\n", uts.version);
    printf("Machine: %s\n", uts.machine);

    return 0;
}

