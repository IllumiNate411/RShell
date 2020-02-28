#ifndef __PAREN_HPP__
#define __PAREN_HPP__

#include <string>
#include <iostream>
#include <sstream>

#include "executable.hpp"

class Paren : public executable{
	protected:
		string parenType;
	public:
		Paren(string input):executable(){
			parenType = input;
		}

                virtual string getType() {
                        return parenType;
                }

		bool execute() {
			cout << "ERROR: execute is being called on a parenthesis" << endl;
			return false;
		}
};

#endif
