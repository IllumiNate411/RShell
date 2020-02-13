#include "executable.hpp"

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

