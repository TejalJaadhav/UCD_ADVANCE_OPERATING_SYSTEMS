#include <iostream>
#include <unistd.h>
#include <sys/wait.h>

using namespace std;

int main() {

	pid_t processID = fork();


	if (processID == 0) {
	
		cout << "Child process running" << endl;
        	return 0;
	}

	else if (processID > 0) {

		pid_t childProcessID = wait(NULL);
		cout << "Parent finished waiting." << endl;
        	cout << "wait() returned child Process ID: " << childProcessID << endl;

	}

	else {

		cout << "Failure in fork()." << endl;
	}

	return 0;
}



