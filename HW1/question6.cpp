#include <iostream>
#include <unistd.h>
#include <sys/wait.h>


using namespace std;

int main() {
	
	pid_t processID = fork();

	if (processID == 0) {
		close(STDOUT_FILENO);
		
		printf("This is not supposed to print after closing stdout");
		
		return 0;
	}	
	else if (processID > 0) {

	        wait(NULL);

        	cout << "Parent process finished" << endl;
	}

   	 else {
        	cout << "Failure in fork()." << endl;
	 }	

   	 return 0;
}

