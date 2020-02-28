#ifndef __OR_HPP__
#define __OR_HPP__

#include "executable.hpp"
#include <iostream>

class Or : public executable {
	protected:
		executable* lhs;
		executable* rhs;
        public:
		Or() : executable() {
			lhs = NULL;
			rhs = NULL;
		}

                Or(executable* A, executable* B) : executable() { 
			lhs = A;
			rhs = B;
		}

		void setLHS(executable* A) {
                        lhs = A;
                }
                void setRHS(executable* B) {
                        rhs = B;
                }
                virtual string getType() {
                        return "||";
                }

                bool execute();
};

#endif
