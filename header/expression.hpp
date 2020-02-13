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
			argList = new const char*[5];
			for (unsigned i = 0; i < 5; ++i) {
				argList[i] = input[i];
			}
		 }

		virtual bool execute() { };
		void display() {
			int j = 0;
        		while (argList[j] != '\0') {
                		cout << argList[j] << endl;
				++j;
        		}
        		return;
		}

};

#endif
