#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int randInt(int size) {
    int n;
    int fd = open ("/dev/random", O_RDONLY);
    if (fd < 0) {
        // Could probably put this into one errno conditional; but it works
        printf("Error opening file: %d \n", errno);
        return -1;
    }
    else {
        if (read(fd, &n, sizeof n) < 0) {
            close(fd);
            printf("Error reading file: %d \n", errno);
            return -1;
        }
        else {
            close(fd);
            // printf("%d\n", n);
            return n;
        }
    }
}
