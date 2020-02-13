#include "And.hpp"
#include <iostream>

And() {}
~And() {}

bool And::execute() {
	if (right != nullptr)
		return lhs->execute() && rhs->execute();
	if (!left->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

