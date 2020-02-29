#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "executable.hpp"
#include "expression.hpp"
#include "test.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Semicolon.hpp"
#include "Paren.hpp"

using namespace std;

class parser {
	public:
		~parser();
		void parseStrings(string);
		void makeObjects();
		vector <executable* > infixToPostfix(vector <executable* >);
		void infixToPrefix();
		void executeObjects();
		string stringsAt(int);
		string objectsAt(int);
	protected:
		vector <string> parsedStrings;
        	vector <executable* > objects;

		const char* StringToCString(string);
		bool isOperator(string);
};

#endif
