#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("U should use like in example:\n"
               "./make_name [name] [value]\n");
        return 1;
    }

    const char *name = argv[1];
    const char *value = argv[2];

    if (setenv(name, value, 1) != 0) {
        perror("Failed to set environment variable");
        return 1;
    }
    char *retrieved_value = getenv(name);
    if (retrieved_value == NULL) {
        printf("Failed to retrieve environment variable %s\n", name);
        return 1;
    }

    printf("%s=%s\n", name, retrieved_value);
    return 0;
}
