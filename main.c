#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "random.h"

int main() {
    int i = 0;
    int numArray[10];
    printf("Generating random numbers: \n");
    for (i; i < 10; i ++) {
        numArray[i] = randInt(10);
        printf("random %d:%d \n", i, numArray[i]);
    }
    int fdWrite = open("random.txt", O_CREAT |O_RDWR, 0666);

    printf("Writing numbers to file...\n \n");
    write(fdWrite, numArray, sizeof(numArray));
    close(fdWrite);
    if (errno){
        printf("Error: %d \n", errno);
        return -1;
    }

    printf("Reading numbers from file...\n\n");
    int readArray[10];
    int fdRead = open("random.txt", O_RDONLY);
    read(fdRead, readArray, sizeof(readArray));

    printf("Verification that written values were the same: \n");
    for (i =0; i < 10; i ++) {
        printf("random %d:%d \n", i, readArray[i]);
    }
    if (errno){
        printf("Error: %d \n", errno);
        return -1;
    }
    return 0;
}
