#ifndef __EXECUTABLE_HPP__
#define __EXECUTABLE_HPP__

using namespace std;

class executable {
        public:
		executable() { };

		virtual bool execute() = 0;
};

#endif
