#include "executable.hpp"

class Semicolon : public executable {
	protected:
		const char** lhs;
		const char** rhs;
        public:
                Semicolon(const char** A, const char** B) : executable() { 
			lhs = A;
			rhs = B;
		}

                bool execute();
};

