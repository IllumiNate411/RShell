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
                }

                virtual string getType() {
                        return "|";
                }
};
#endif
