#include "Semicolon.hpp"
#include <iostream>

Semicolon::Semicolon() {}

bool Semicolon::execute() {
	if (right != nullptr)
		return lhs->execute() && rhs->execute();
	if (!left->execute())
		cout << "No preceeding argument" << endl;
		return false;
}

