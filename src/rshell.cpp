#include <iostream>
#include <string>
#include <vector>

#include "../header/parser.hpp"
#include "../header/executable.hpp"
#include "../header/expression.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"
#include "../header/Paren.hpp"
#include "../header/InRedirector.hpp"
#include "../header/OutRedirector.hpp"
#include "../header/Pipe.hpp"

using namespace std;

int main() {

	parser* commands;

        while (true) {
                cout << "$ ";

		string userStr;
        	getline(cin, userStr);

		commands = new parser();
	
                commands->parseStrings(userStr);
                commands->makeObjects();
		commands->infixToPrefix();
                commands->executeObjects();

		delete commands;
        }

        return 0;
}

