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
		//void findConnectorOrder();
		void executeObjects();
		string stringsAt(int);
	protected:
		vector <string> parsedStrings;
        	//vector <string> connectorOrder;
        	vector <executable* > objects;

		const char* StringToCString(string);
};

#endif
