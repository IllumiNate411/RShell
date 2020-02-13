#include "executable.hpp"

class Or : public executable {
	protected:
		executable* lhs;
		executable* rhs;
        public:
		Or() {}
		~Or() {}

                Or(executable* A, executable* B) : executable() { 
			lhs = A;
			rhs = B;
		}

                bool execute();
};
