#ifndef __CONNECTORTOKEN_HPP__
#define __CONNECTORTOKEN_HPP__

using namespace std;

class connectortoken : public base {
        public:
                connectortoken() : base() { }
		virtual void execute() { }
};

#endif

