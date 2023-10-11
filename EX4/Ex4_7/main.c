#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

void print_usage() {
    printf("Instructions:\n"
           "-h, --help\n"
           "    Display help menu\n\n"
           "-i, --info [name]\n"
           "    Display the value of variable by [name]\n\n"
           "-s, --set [name=value]\n"
           "    Set the variable by [name] to [value]\n\n"
           "-a, --assign [name]\t"
           "-v, --value [value]\n"
           "    Assign [value] to variable by [name]\n"
           "    If only [name] is provided without -v, assign an empty string to [name]\n\n"
           "-d, --del [name]\n"
           "    Delete the variable by [name]\n\n"
           "-c, --clear\n"
           "    Clear all environment variables\n\n");
}

void print_environment() {
    extern char **environ;
    char **env = environ;
    printf("Current environment variables:\n");
    while (*env) {
        printf("%s\n", *env);
        env++;
    }
}

void print_variable_info(char *var_name) {
    char *value = getenv(var_name);
    if (value) {
        printf("%s=%s\n", var_name, value);
    } else {
        printf("Variable %s not found in environment\n", var_name);
    }
}

void set_variable(const char *variable_name, const char *value) {
    setenv(variable_name, value, 1);
    printf("%s=%s\n", variable_name, value);
    print_environment();
}

void assign_variable(const char *variable_name, const char *value) {
    if (value != NULL) {
        setenv(variable_name, value, 1);
        printf("%s=%s\n", variable_name, value);
    } else {
        unsetenv(variable_name);
        printf("Variable %s has been removed from the environment.\n", variable_name);
    }
    print_environment();
}

void delete_variable(char *var_name) {
    unsetenv(var_name);
    print_environment();
}

void clear_environment() {
    extern char **environ;
    environ = NULL;
    print_environment();
}

int main(int argc, char *argv[]) {
    int opt;
    int option_index = 0;
    char *assign_name = NULL;
    char *value_name = NULL;

    static struct option long_options[] = {
            {"help", no_argument, 0, 'h'},
            {"info", required_argument, 0, 'i'},
            {"set", required_argument, 0, 's'},
            {"assign", required_argument, 0, 'a'},
            {"value", required_argument, 0, 'v'},
            {"del", required_argument, 0, 'd'},
            {"clear", no_argument, 0, 'c'},
            {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "hi:s:a:v:d:c", long_options, &option_index)) != -1) {
        switch (opt) {
            case 'h':
                print_usage();
                break;
            case 'i':
                print_variable_info(argv[2]);
                break;
            case 's':
                set_variable(argv[2], argv[3]);
                break;
            case 'a':
                assign_variable(argv[2], argv[4]);
            case 'd':
                delete_variable(argv[2]);
                break;
            case 'c':
                clear_environment();
                break;
            default:
                printf("Option not recognized\n");
                print_usage();
                return EXIT_FAILURE;
        }
    }

    if (argc == 1) {
        print_environment();
    }

    return EXIT_SUCCESS;
}


