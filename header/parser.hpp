#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "../header/parser.hpp"
#include "../header/executable.hpp"
#include "../header/expression.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"

using namespace std;

class parser {
	public:
		~parser();
		void parseStrings();
		void makeObjects();
		void findConnectorOrder();
		void executeObjects();
	protected:
		vector <string> parsedStrings;
        	vector <string> connectorOrder;
        	vector <executable* > objects;

		const char* StringToCString(string);
};

#endif
