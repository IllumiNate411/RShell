#include "../header/Or.hpp"
#include <iostream>


bool Or::execute() {

	if (rhs != 0)
		return lhs->execute() && rhs->execute();
	if (!lhs->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

