#include "executable.hpp"

class Or : public executable {
	protected:
		char** lhs;
		char** rhs;
        public:
                Or() : executable();

                bool execute();
};
