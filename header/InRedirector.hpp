#ifndef __INREDIRECTOR_HPP__
#define __INREDIRECTOR_HPP__

#include "executable.hpp"

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
                	cout << "FIXME: EXECUTE INREDIRECTOR" << endl;
		}

                virtual string getType() {
                        return "<";
                }
};
#endif
