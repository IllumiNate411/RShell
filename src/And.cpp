#include "../header/And.hpp"
#include <iostream>



bool And::execute() {
	if (rhs != 0) {
		if (lhs->execute()) {
			return rhs->execute();
		}
		return false;
	}
	if (!lhs->execute()) {
		cout << "No preceeding argument" << endl;
		return false;
	}
	return false;
}

