#include <iostream>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main () {
	
	pid_t processID = fork();

	if (processID == 0) {

		cout << "Child process running" << endl;
		sleep(3);
		return 0;

	}
	else if (processID > 0) {

		int exitStatus = 0; //To store child's exit status.
		pid_t res = waitpid(processID, &exitStatus, 0);  // To return Process ID of the child that finished.

		cout << "Parent process finished waiting." << endl;
		cout << "waitpid() returned child process ID: " << res << endl;
	}
	else {
        	cout << "Failure in fork()." << endl;
	 }	
	
	return 0;
}

