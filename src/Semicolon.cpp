#include "../header/Semicolon.hpp"
#include <iostream>

bool Semicolon::execute() {
	if (rhs != 0)
		lhs->execute();
		return rhs->execute();
	if (!lhs->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

