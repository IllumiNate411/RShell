#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

#include "executable.hpp"

using namespace std;

class expression : public executable {
	protected:
		//gives command and list of arguments for the expression
		//the first element in the array will always be the command
		const char** argList;
	public:
		expression(const char** input) : executable() {
			argList = input;
		 }

		virtual bool execute(){
		
		}
};

#endif
