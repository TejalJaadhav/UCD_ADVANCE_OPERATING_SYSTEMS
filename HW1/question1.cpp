#include<iostream>
#include<unistd.h>
#include<sys/wait.h>

using namespace std;

int main() {

    int value = 96;

    cout << "Value before calling fork() : " << value << endl;

    pid_t processID = fork();

    if(processID == 0) {

        cout << "This is the intial value of child process: " << value << endl;

        value = 176;

        cout << "In child process value changed to:  " << value << endl;
    }

    else if(processID > 0) {

        wait(NULL);

        cout << "This is the parent process." << endl;

        cout << "Parent sees value after fork(): " << value << endl;

        value = 230;

        cout << "In parent process after fork() value changed to: " << value << endl;
    }

    else {

        cout << "Failure in fork()." << endl;
    }

    return 0;
}
