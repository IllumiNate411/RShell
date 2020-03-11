#ifndef __OUTREDIRECTOR_HPP__
#define __OUTREDIRECTOR_HPP__

#include <iostream>
#include "executable.hpp"

class InRedirector : public executable {
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
                        cout << "FIXME: EXECUTE OUTREDIRECTOR" << endl;
                }

                virtual string getType() {
                        return type;
                }
};
#endif

