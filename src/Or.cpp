#include "Or.hpp"
#include <iostream>

Or::Or() {}

bool Or::execute() {

	if (right != nullptr)
		return lhs->execute() && rhs->execute();
	if (!left->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

