#ifndef __CMDTOKEN_HPP__
#define __CMDTOKEN_HPP__

using namespace std;

class cmdtoken : public base {
        public:
                cmdtoken() : Base() { }
		virtual void evaluate() { }
};

#endif

