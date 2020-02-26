#ifndef __EXEC_HPP__
#define __EXEC_HPP__

#include "executable.hpp"
#include <iostream>

class Exec : public executable {
	protected:
		executable* lhs;
		executable* rhs;
	public:
		Exec(executable* A, executable* B) : executable() {
			lhs = A;
			rhs = B;
		}
		
		bool execute();
};

#endif
