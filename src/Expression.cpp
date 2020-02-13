#include "expression.hpp"


void expression(const char** input):exacutable(){

}


bool expression::execute() {
	int i, status;
	pid_t childId, endId;
	time_t when;
	if (strcmp(args[0], "exit") == 0) exit(EXIT_SUCCESS);
	if (strcmp(args[0], "test") == 0 || strcmp(args[0], "[") == 0){
		if (strcmp(args[1], "-e") == 0){
			struct stat comm;
			if ((strcmp(args[3], "]")) || strcmp(args[0], "test") && stat(args[2], &comm)){
				std::cout << "(true)\n";
				return true;
			}
		} else if (strcmp(args[1], "-d") == 0){
			struct stat comm;
			if ((strcmp(args[3], "]")) || strcmp(args[0], "test") && stat(args[2], &comm)){
				if (DIRE(comm.st_mode)){
					std::cout << "(true)\n";
					return true;
				}
			}
		} else if (strcmp(args[1], "-f") == 0){
			struct stat comm;
			if ((strcmp(args[3], "]")) || strcmp(args[0], "test") && stat(args[2], &comm)){
				if (REG(comm.st_mode)){
					std::cout << "(true)\n";
					return true;
				}
			}
		}
		struct stat comm;
		if ((strcmp(args[3], "]")) || strcmp(args[0], "test") && stat(args[2], &comm)){
	
			std::cout << "(true)\n";
			return true;
	
		}
	
		else {std::cout << "(false)\n"; return false;}
	}
	
	else{}
	
	if((childId = fork()) == -1) {
	
		perror("fork() error");
		exit(EXIT_FAILURE);
	
	} else if (childId == 0) {	
		
		time(&when);

		if (execvp(args[0], (char* const*)args) < 0) {
			printf("Error executing command \"%s\", %s\n", this->toString().c_str(), strerror(errno));
			exit(errno);
		}
	} else {
		time(&when);
		endId = waitpid(childId, &status, 0);
		if (endId == -1) {
			perror("waitpid() error");
			exit(EXIT_FAILURE);
		} else if (endId == 0) {
			time(&when);
		} else if (endId == childId) {
			if (WIFEXITED(status)) {
				printf("child ended with %d\n", WEXITSTATUS(status));
			} else if (WIFSIGNALED(status)) {
				printf("child ended because of an uncaught signal\n");
			} else if (WIFSTOPPED(status)) {
				printf("child process has stopped\n");
			}
		kill(childId, SIGKILL);
		}
	}
	return WEXITSTATUS(status) == 0;
}
