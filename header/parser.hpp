#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "executable.hpp"
#include "expression.hpp"
#include "test.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Semicolon.hpp"
#include "Paren.hpp"
#include "InRedirector.hpp"
#include "OutRedirector.hpp"
#include "Pipe.hpp"

using namespace std;

class parser {
	public:
		~parser();
		void parseStrings(string);
		void makeObjects();
		vector <executable* > infixToPostfix(vector <executable* >);
		void infixToPrefix();
		bool executeObjects();
		string stringsAt(int);
		string objectsAt(int);
	protected:
		vector <string> parsedStrings;
        	vector <executable* > objects;

		const char* StringToCString(string);
		bool isOperator(string);
		int getPrecedence(string);
};

#endif
