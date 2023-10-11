#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("U should use as an example:\n"
               "./make_name [variable_name]\n");
        return 1;
    }

    const char *var_name = argv[1];
    char *var_value = getenv(var_name);

    if (var_value == NULL) {
        printf("%s is not set or does not exist\n", var_name);
    } else {
        printf("%s=%s\n", var_name, var_value);
    }

    return 0;
}
