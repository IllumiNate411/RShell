#include "connector.hpp"

class And : public connector {
	public:
		And();

		bool execute();
		std::string toString();
};

