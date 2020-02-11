#ifndef __EXPRESSION_HPP__
#define __EXPRESSION_HPP__

using namespace std;

class expression : public connector {
	protected:
		//gives command and list of arguments for the expression
		//the first element in the array will always be the command
		char** argList;
	public:
		expression(char** input) : connector();

		virtual bool execute();
};

#endif
