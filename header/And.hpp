#ifndef __AND_HPP__
#define __AND_HPP__

#include "executable.hpp"
#include <iostream>

class And : public executable {
	protected:
		executable* lhs;
		executable* rhs;
	public:
		
		And(executable*  A, executable* B) : executable() {
			lhs = A;
			rhs = B;
		}

		bool execute();
};

#endif
