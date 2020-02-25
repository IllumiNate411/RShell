#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include <string>
#include <iostream>
#include <sstream>

#include "exacutable.hpp"

class Paren : public executable{
	protected:
		executable* objA
	public:
		Paren(sting input):executable(){
			ObjA = input;
		}

		bool execute();
};

#endif
