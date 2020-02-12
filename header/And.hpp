#include "executable.hpp"

class And : public executable {
	protected
		char** lhs;
		char** rhs;
	public:
		And(char** ) : executable();

		bool execute();
};

