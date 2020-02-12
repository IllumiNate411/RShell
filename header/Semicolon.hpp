#include "executable.hpp"

class And : public executable {
	protected:
		char** lhs;
		char** rhs;
        public:
                Semicolon() : executable();

                bool execute();
};

