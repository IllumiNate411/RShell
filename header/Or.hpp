#include "executable.hpp"

class Or : public executable {
	protected:
		const char** lhs;
		const char** rhs;
        public:
                Or(const char** A, const char** B) : executable() { 
			lhs = A;
			rhs = B;
		}

                bool execute();
};
