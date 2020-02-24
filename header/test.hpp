#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "executable.hpp"

class test : public executable {
	protected:
		const char** argList;
	public:
		test(const char** input) : executable() {
			argList = new const char*[5];
			for (unsigned i = 0; i < 5; ++i) {
				argList[i] = input[i];
		
			}
		 }

		virtual bool execute() {
			if (true) {
				cout << "(TRUE)" << endl;
				return true;
			}
			else {
				cout << "(FALSE)" << endl;
				return false;
			}
		}
};
#endif
