#ifndef __OUTREDIRECTOR_HPP__
#define __OUTREDIRECTOR_HPP__

#include <iostream>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include "executable.hpp"

class OutRedirector : public executable {
        protected:
                executable* lhs;
                executable* rhs;
		string type; //can be > or >>
        public:

                OutRedirector(string input) : executable() {
                        lhs = NULL;
                        rhs = NULL;
			type = input;
                }

                OutRedirector(executable*  A, executable* B, string input) : executable() {
                        lhs = A;
                        rhs = B;
			type = input;	
                }

                void setLHS(executable* A) {
                        lhs = A;
                }
                void setRHS(executable* B) {
                        rhs = B;
                }

                virtual bool execute() {
			const char* fileName = rhs->at(0);
			int outputFD = dup(1);
			int newFD;

			if (getType() == ">") {
				newFD = open(fileName, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			}
			else if (getType() == ">>") {
				newFD = open(fileName, O_WRONLY | O_CREAT | O_APPEND, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
			}
			else {
				cout << "ERROR: INVALID TYPE IN OUTREDIRECTOR" << endl;
			}

			if (newFD < 0) {
				cout << "ERROR: FAILED TO OPEN FILE" << endl;
				return false;
			}
			else if (dup2(newFD, 1) != STDOUT_FILENO) {
				cout << "ERROR: INVALID COMMAND" << endl;
				close(newFD);
				return false;
			}
			else {
				lhs->execute();
				close(newFD);
				dup2(outputFD, 1);
				return true;
			}

			return false;
                }

                virtual string getType() {
                        return type;
                }
};
#endif

