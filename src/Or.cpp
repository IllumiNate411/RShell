#include "../header/Or.hpp"
#include <iostream>


bool Or::execute() {

	if (rhs != 0) {
		if (lhs->execute()) {
			return true;
		}
		else {
			return rhs->execute();
		}
	}
	if (!lhs->execute()) {
		cout << "No preceeding argument" << endl;
		return false;
	}
	return false;
}

