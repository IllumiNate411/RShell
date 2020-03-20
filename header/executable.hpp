#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

#include <iostream>
using namespace std;

class executable {
        public:

		virtual bool execute() = 0;
		virtual string getType() = 0;
		virtual void setType(string) { };
		virtual const char* at(int) { };
		virtual void display() { };
		virtual void setLHS(executable *) { };
		virtual void setRHS(executable *) { };
};

#endif
