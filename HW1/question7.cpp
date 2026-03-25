#include <iostream> 
#include <unistd.h>     
#include <sys/wait.h>   

using namespace std;

int main() {
    int pipeFD[2]; // pipeFD[0] = read end, pipeFD[1] = write end.
    pipe(pipeFD);                

    pid_t child1 = fork(); 

    if (child1 == 0) {
        // Child process 1: writes to pipe.

        close(pipeFD[0]); // Child process 1 does not read from pipe.

        dup2(pipeFD[1], STDOUT_FILENO); 
        close(pipeFD[1]);

        cout << "Hello from Child process 1" << endl;
        return 0;
    }

    pid_t child2 = fork(); 

    if (child2 == 0) {
        // Child process 2: reads from pipe.

        close(pipeFD[1]); // Child process 2 does not write to pipe.

        dup2(pipeFD[0], STDIN_FILENO); 
        close(pipeFD[0]);

        char buffer[100];
        int bytesRead = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
        buffer[bytesRead] = '\0';

        cout << "Child process 2 received: " << buffer;
        return 0;
    }

    // Parent process
    close(pipeFD[0]); // Here, Parent process closes both ends.
    close(pipeFD[1]);

    wait(NULL);                     
    wait(NULL);

    return 0;
}


