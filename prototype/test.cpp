#include <iostream>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

using namespace std;

int main(int argc, char** argv) {
	
	pid_t cPID, wPID;
	int status;

	cPID = fork();

	if (cPID < 0) {
		cout << "Failed to Fork to child correctly" << endl;
	}
	else if (cPID == 0) {
		if (execvp("./main", NULL) < 0) {
			cout << "Execute Failed" << endl;
		}
	}
	else {
		wPID = waitpid(cPID, &status, 0);
		if (wPID == -1) {
			cout << "Wait PID failed" << endl;
		}
		
		else if (WIFSIGNALED(status)) {
			cout << "Error exiting" << endl;
		}
		
		else {
			cout << "Successfully exited" << endl;
		}
	}

	return 0;
}
