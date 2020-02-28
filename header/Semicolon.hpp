#ifndef __SEMICOLON_HPP__
#define __SEMICOLON_HPP__

#include "executable.hpp"
#include <iostream>

class Semicolon : public executable {
	protected:
		executable* lhs;
		executable* rhs;
        public:
		Semicolon() : executable() {
			lhs = NULL;
			rhs = NULL;
		}

                Semicolon(executable* A, executable* B) : executable() { 
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
                        return ";";
                }

                virtual bool execute();
};

#endif
