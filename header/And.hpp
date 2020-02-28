#ifndef __AND_HPP__
#define __AND_HPP__

#include "executable.hpp"
#include <iostream>

class And : public executable {
	protected:
		executable* lhs;
		executable* rhs;
	public:
		
		And() : executable() {
			lhs = NULL;
			rhs = NULL;
		}

		And(executable*  A, executable* B) : executable() {
			lhs = A;
			rhs = B;
		}

		void setLHS(executable* A) {
			lhs = A;
		}
		void setRHS(executable* B) {
			rhs = B;
		}
		string getType() {
			return "&&";
		}
		bool execute();
};

#endif
