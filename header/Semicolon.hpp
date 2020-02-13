#include "executable.hpp"

class Semicolon : public executable {
	protected:
		executable* lhs;
		executable* rhs;
        public:
                Semicolon(executable* A, executable* B) : executable() { 
			lhs = A;
			rhs = B;
		}

                bool execute();
};
