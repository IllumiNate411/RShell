#ifndef __PARSER_HPP__
#define __PARSER_HPP__

#include "executable.hpp"
#include "expression.hpp"
#include "test.hpp"
#include "And.hpp"
#include "Or.hpp"
#include "Semicolon.hpp"
#include "exec.hpp"

using namespace std;

class parser {
	public:
		~parser();
		void parseStrings(string);
		void makeObjects();
		void findConnectorOrder();
		executable* executep2(unsigned& i);
		void executeObjects();
		string stringsAt(int);
		string connectorsAt(int);
	protected:
		vector <string> parsedStrings;
        	vector <string> connectorOrder;
        	vector <executable* > objects;

		const char* StringToCString(string);
};

#endif
