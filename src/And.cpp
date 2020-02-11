#include "And.hpp"
#include <iostream>

And::And() {}

bool And::execute() {
	if (right != nullptr)
		return Lside->execute() && Rside->execute();
	if (!left->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

