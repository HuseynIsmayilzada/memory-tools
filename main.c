#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void setMem(char* ptr, char value, bool firstFour) {
    if (value > 15) {
        fprintf(stderr, "Value exceeds 4 bits");
        exit(1);
    }
    if (firstFour){
        *ptr |= (value << 4);
        return;
    }
    *ptr |= value;
}

char readMem(char* ptr, bool firstFour) {

    if (firstFour) {
        return (*ptr & 0b11110000) >> 4;
    }
    return *ptr & 0b00001111;
}

int main(int argc, char** argv) {
    char* split = (char*) malloc(sizeof(char));
    if (split==NULL) {
        fprintf(stderr, "Memory Allocation Failed. (malloc)\n");
        exit(1);
    }

    setMem(split, 12, 1);
    setMem(split, 8, 0);

    printf("([####]####): %d\n", readMem(split, 1));
    printf("(####[####]): %d\n", readMem(split, 0));

    free(split);

    return 0;
}
