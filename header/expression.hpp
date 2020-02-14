#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

#include "executable.hpp"
#include <sys/types.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

class expression : public executable {
	protected:
		//gives command and list of arguments for the expression
		//the first element in the array will always be the command
		const char** argList;
	public:
		expression(const char** input) : executable() {
			argList = new const char*[5];
			for (unsigned i = 0; i < 5; ++i) {
				argList[i] = input[i];
			}
		 }

		virtual bool execute() {
			/*
        		unsigned i = 0;
        		while(argList[i] != '\0') {
                		cout << argList[i] << endl;
                		++i;
        		}
			*/
        		int status;
        		pid_t parentID;

			parentID = fork();
        		if (parentID < 0) {
                		cout << "ERROR: fork to child process has failed" << endl;
                		return false;
        		}
        		else if(parentID == 0) {
                		if (execvp(argList[0],(char**) argList) < 0) {
                        		cout << "Error: execution failed" << endl;
                        		return false;
                		}
        		}
        		else {
                		while (wait(&status) != parentID);
        		}

        		if (status == 256) {
                		cout << "ERROR: Invalid Command" << endl;
                		return false;
        		}
        		return true;

		}
		void display() {
			int j = 0;
        		while (argList[j] != '\0') {
                		cout << argList[j] << endl;
				++j;
        		}
        		return;
		}

};

#endif
