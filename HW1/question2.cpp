#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <assert.h>

using namespace std;

int main() {

    int fd = open("/tmp/file.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRWXU);
    assert(fd > -1);

    pid_t processID = fork();

    if (processID == 0) {
        int bytes = write(fd, "Child is writing to the file\n", 29);
        assert(bytes == 29);

        cout << "Child finished writing." << endl;
    }
    else if (processID > 0) {

        int bytes = write(fd, "Parent is writing to the file\n", 30);
        assert(bytes == 30);

        cout << "Parent finished writing." << endl;

        wait(NULL);
    }
    else {
        cout << "Failure in fork()." << endl;
    }
    close(fd);

    return 0;
}

