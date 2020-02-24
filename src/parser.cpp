#include <iostream>
#include <string>
#include <vector>

#include "../header/parser.hpp"

using namespace std;

parser::~parser() {
	while(!parsedStrings.empty()) {
		parsedStrings.pop_back();
	}
	while(!connectorOrder.empty()) {
                connectorOrder.pop_back();
        }
	while(!objects.empty()) {
                objects.pop_back();
        }
}

void parser::parseStrings() {

	string input;
	getline(cin, input);
	char curr;
	int sz = input.size();
	int next;
	
	for (unsigned i = 0; i < sz; ++i) {
		char curr = input.at(i);
		//finds quotes to be echoed		
		if (curr == '"') {
			next = input.find('"', i + 1);
			parsedStrings.push_back(input.substr(i + 1, next - i - 1));
			i = next;
		}
		else if (curr == '#') {
			i = sz -1;
		}
		else if (curr != ' ') {
			//takes a substring of current position up until next space
			if (input.find(' ', i) != string::npos) {
				next = input.find(' ', i);
				//accounts for a semicolon case and parses the semicolon seperately
				if (input.at(next - 1) == ';') {
					parsedStrings.push_back(input.substr(i, next - i - 1));
					parsedStrings.push_back(input.substr(next - 1, 1));
					i = next;
				}
				else {
					parsedStrings.push_back(input.substr(i, next - i));
					i = next;
				}
			}
			//in case the last portion to be parsed goes to the end of string
			else {
				//for semicolon at the end
				if (input.find(';', i) != string::npos) {
					parsedStrings.push_back(input.substr(i, sz - 1 - i));
					parsedStrings.push_back(input.substr(sz - 1, 1));
					i = sz - 1;
				}
				else {
					parsedStrings.push_back(input.substr(i, sz - i));
					i = sz - 1;
				}
			}
		}
	}
}

//goes through input and creates expression objects for each command/argument(s)
void parser::makeObjects() {
	int k = 0;
        const char* tempArr[5];

        for (unsigned i = 0; i < parsedStrings.size(); ++i) {
                if(parsedStrings.at(i) == "&&") {
                        tempArr[k] = '\0';
                        objects.push_back(new expression(tempArr));
                        k = 0;
                }
                else if(parsedStrings.at(i) == "||") {
                        tempArr[k] = '\0';
                        objects.push_back(new expression(tempArr));
                        k = 0;
                }
                else if(parsedStrings.at(i) == ";") {
			if (i != parsedStrings.size() - 1) { 
                        	tempArr[k] = '\0';
                        	objects.push_back(new expression(tempArr));
                        	k = 0;
			}
                }
                else {
                        tempArr[k] = StringToCString(parsedStrings.at(i));
                        ++k;
                }
        }

        tempArr[k] = '\0';
        objects.push_back(new expression(tempArr));
}

//goes through input and finds what connectors we need to use and in what order
void parser::findConnectorOrder() {
	string curr;
	for (unsigned i = 0; i < parsedStrings.size(); ++i) {
		curr = parsedStrings.at(i);
		if (curr == "&&") {
			connectorOrder.push_back("&&");
		}
		else if (curr == "||") {
                        connectorOrder.push_back("||");
                }
		else if (curr == ";") {
                        connectorOrder.push_back(";");
                }
	}
}

void parser::executeObjects() {
	if (objects.size() == 1) {
		objects.at(0)->execute();
		return;
	}

	executable* execTree = objects.at(0);

	for (unsigned i = 1; i < objects.size(); ++i) {
		if (connectorOrder.at(i - 1) == "&&") {
			execTree = new And(execTree, objects.at(i));
		}
		else if (connectorOrder.at(i - 1) == "||") {
			execTree = new Or(execTree, objects.at(i));
		}
		else if (connectorOrder.at(i - 1) == ";") {
			execTree = new Semicolon(execTree, objects.at(i));
		}		
	}
	execTree->execute();
	return;
}

const char* parser::StringToCString(string str) {
        const char* cstring;
        cstring = str.c_str();

        return cstring;
}

