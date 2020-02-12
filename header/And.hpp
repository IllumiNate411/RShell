#include "executable.hpp"

class And : public executable {
	protected:
		const char** lhs;
		const char** rhs;
	public:
		And(const char** A, const char** B) : executable() { 
			lhs = A;
			rhs = B;
		}

		bool execute();
};

