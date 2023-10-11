#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>
#include <unistd.h>

void print_user_info(struct passwd *pwd) {
    if (!pwd) {
        printf("Failed to get user information\n");
        return;
    }

    printf("User name: %s\n", pwd->pw_name);
    printf("User ID: %d\n", pwd->pw_uid);
    printf("Group ID: %d\n", pwd->pw_gid);
    printf("Home directory: %s\n", pwd->pw_dir);
    printf("User information: %s\n", pwd->pw_gecos);
    printf("Shell: %s\n", pwd->pw_shell);
}

int main() {
    uid_t uid = getuid();

    printf("Information for current user:\n");
    print_user_info(getpwuid(uid));

    printf("\nInformation for root user:\n");
    print_user_info(getpwnam("root"));

    return 0;
}
