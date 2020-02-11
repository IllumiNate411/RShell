#include "connector.hpp"

connector::connector() {
	Lside;
	Rside;
}

void connector::sLeft(a1) {
	left = a1;
}

void connector::sRight(a2) {
	right = a2;
}

connector::gLeft() {
	return Lside;
}

connector::gRight() {
	return Rside;
}

