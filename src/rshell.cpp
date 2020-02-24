#include <iostream>
#include <string>
#include <vector>

#include "../header/parser.hpp"
#include "../header/executable.hpp"
#include "../header/expression.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"

using namespace std;

int main() {

	parser* commands;

        while (true) {
                cout << "$ ";

		commands = new parser();
		
                commands->parseStrings();
                commands->findConnectorOrder();
                commands->makeObjects();
                commands->executeObjects();

		delete commands;
        }

        return 0;
}

