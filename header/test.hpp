#ifndef __TEST_HPP__
#define __TEST_HPP__

#include "executable.hpp"
#include <sys/stat.h>
#include <sys/types.h>

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
			struct stat sb;
			if(argList[1] != "-d") {
				//if(S_ISREG(sb.st_mode) != 0) {
					 
				//}
			}
			else {
				cout << "(FALSE)" << endl;
				return false;
			}
		}

		virtual string getType() {
			return "exp";
		}
};
#endif
