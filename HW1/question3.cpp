#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

using namespace std;

void run_exec_variant(int variant) {

    pid_t pid = fork();

    if (pid == 0) {

        if (variant == 1) {
            cout << "Executing execl()" << endl;
            execl("/bin/ls", "ls", (char *)NULL);
        }

        else if (variant == 2) {
            cout << "Executing execle()" << endl;
            char *env[] = {NULL};
            execle("/bin/ls", "ls", (char *)NULL, env);
        }

        else if (variant == 3) {
            cout << "Executing execlp()" << endl;
            execlp("ls", "ls", (char *)NULL);
        }

        else if (variant == 4) {
            cout << "Executing execv()" << endl;
            char *args[] = {(char *)"ls", NULL};
            execv("/bin/ls", args);
        }

        else if (variant == 5) {
            cout << "Executing execvp()" << endl;
            char *args[] = {(char *)"ls", NULL};
            execvp("ls", args);
        }

        else if (variant == 6) {
            cout << "Executing execvpe()" << endl;
            char *args[] = {(char *)"ls", NULL};
            char *env[] = {NULL};
            execvpe("ls", args, env);
        }

        cout << "Failure in exec." << endl;

        exit(1);
    }

    else {
        wait(NULL);
    }
}

int main() {

    for (int i = 1; i <= 6; i++) {
        run_exec_variant(i);
    }

    return 0;
}

