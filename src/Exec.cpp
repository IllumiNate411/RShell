#include "../header/exec.hpp"
#include <iostream>



bool Exec::execute() {
	rhs->execute();
	return lhs->execute();
}

