#include <stdio.h>
#include <stdlib.h>

void print_env() {
    extern char **environ;
    char **env = environ;

    printf("ENV now:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

int main(int args, char *argv[]) {
    if (args > 2) {
        printf("U should use it like in example:\n"
               "./make_name [name]\n");
        return 1;
    }

    if (args == 1) {
        if (clearenv() != 0) {
            perror("Failed to clear environment");
            return 1;
        }
    } else {
        const char *name = argv[1];
        if (unsetenv(name) != 0) {
            perror("Failed to unset environment variable");
            return 1;
        }
    }
    print_env();
    return 0;
}
