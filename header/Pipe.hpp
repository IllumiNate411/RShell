#ifndef __PIPE_HPP__
#define __PIPE_HPP__

#include "executable.hpp"

class Pipe : public executable {
        protected:
                executable* lhs;
                executable* rhs;
        public:

                Pipe() : executable() {
                        lhs = NULL;
                        rhs = NULL;
                }

                Pipe(executable*  A, executable* B) : executable() {
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
                        cout << "FIXME: EXECUTE PIPE" << endl;

			const char* fileName = rhs->at(0);
			int inputFD = dup(0);
			int newFD = open(fileName, O_RDONLY);

			if (newFD < 0) {
				cout << "ERROR: FAILED TO OPEN FILE" << endl;
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
                        return "|";
                }
};
#endif
