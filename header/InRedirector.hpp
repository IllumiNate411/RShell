#ifndef __INREDIRECTOR_HPP__
#define __INREDIRECTOR_HPP__

#include <unistd.h>
#include <fcntl.h>
#include "executable.hpp"
#include "expression.hpp"

class InRedirector : public executable {
        protected:
        	executable* lhs;
                executable* rhs;
        public:

                InRedirector() : executable() {
                        lhs = NULL;
                        rhs = NULL;
                }

                InRedirector(executable*  A, executable* B) : executable() {
                        lhs = A;
                        rhs = B;
                }

                void setLHS(executable* A) {
                        lhs = A;
                }
                void setRHS(executable* B) {
                        rhs = B;
                }

                virtual bool execute() {
			const char* fileName = rhs->at(0);
			int inputFD = dup(0);
			int newFD = open(fileName, O_RDONLY);

			if (newFD < 0) {
				cout << "ERROR: FAILED TO OPEN FILE" << endl;
				return false;
			}
			else if (dup2(newFD, 0) != STDIN_FILENO) {
				cout << "ERROR: INVALID COMMAND" << endl;
				close(newFD);
				return false;
			}
			else {
				lhs->execute();
				close(newFD);
				dup2(inputFD, 0);
				return true;
			}

			return false;
		}

                virtual string getType() {
                        return "<";
                }
};
#endif
