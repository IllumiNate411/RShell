#include <iostream>
#include <string>
#include <vector>

#include "../header/executable.hpp"
#include "../header/expression.hpp"
#include "../header/And.hpp"
#include "../header/Or.hpp"
#include "../header/Semicolon.hpp"

using namespace std;

vector<string> parser() {

	string input;
	vector<string> parsedInput;
	getline(cin, input);
	char curr;
	int sz = input.size();
	int next;
	
	for (unsigned i = 0; i < sz; ++i) {
		char curr = input.at(i);
		//finds quotes to be echoed		
		if (curr == '"') {
			next = input.find('"', i + 1);
			parsedInput.push_back(input.substr(i + 1, next - i - 1));
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
					parsedInput.push_back(input.substr(i, next - i - 1));
					parsedInput.push_back(input.substr(next - 1, 1));
					i = next;
				}
				else {
					parsedInput.push_back(input.substr(i, next - i));
					i = next;
				}
			}
			//in case the last portion to be parsed goes to the end of string
			else {
				//for semicolon at the end
				if (input.find(';', i) != string::npos) {
					parsedInput.push_back(input.substr(i, sz - 1 - i));
					parsedInput.push_back(input.substr(sz - 1, 1));
					i = sz - 1;
				}
				else {
					parsedInput.push_back(input.substr(i, sz - i));
					i = sz - 1;
				}
			}
		}
	}
	return parsedInput;
}

const char* StringToCString(string str) {
	const char* cstring;
	cstring = str.c_str();

	return cstring;
}

//goes through input and creates expression objects for each command/argument(s)
vector<executable* >  makeObjects(vector<string> inputs) {
	int k = 0;
        const char* tempArr[5];
        vector<executable*  > objectVec;
        vector<string> connectorOrder;

        for (unsigned i = 0; i < inputs.size(); ++i) {
                if(inputs.at(i) == "&&") {
                        tempArr[k] = '\0';
                        objectVec.push_back(new expression(tempArr));
                        k = 0;
                }
                else if(inputs.at(i) == "||") {
                        tempArr[k] = '\0';
                        objectVec.push_back(new expression(tempArr));
                        k = 0;
                }
                else if(inputs.at(i) == ";") {
                        tempArr[k] = '\0';
                        objectVec.push_back(new expression(tempArr));
                        k = 0;
                }
                else {
                        tempArr[k] = StringToCString(inputs.at(i));
                        ++k;
                }
        }

        tempArr[k] = '\0';
        objectVec.push_back(new expression(tempArr));

	return objectVec;
}

//goes through input and finds what connectors we need to use and in what order
vector<string> findConnectorOrder(vector<string> inputs) {
	vector<string> order;
	string curr;
	for (unsigned i = 0; i < inputs.size(); ++i) {
		curr = inputs.at(i);
		if (curr == "&&") {
			order.push_back("&&");
		}
		else if (curr == "||") {
                        order.push_back("||");
                }
		else if (curr == ";") {
                        order.push_back(";");
                }
	}
	return order;
}

void executeObjects(vector <executable* > objectList, vector<string> orderList) {
	if (objectList.size() == 1) {
		objectList.at(0)->execute();
		return;
	}

	executable* execTree = objectList.at(0);

	for (unsigned i = 1; i < objectList.size(); ++i) {
		if (orderList.at(i - 1) == "&&") {
			execTree = new And(execTree, objectList.at(i));
		}
		else if (orderList.at(i - 1) == "||") {
			execTree = new Or(execTree, objectList.at(i));
		}
		else if (orderList.at(i - 1) == ";") {
			execTree = new Semicolon(execTree, objectList.at(i));
		}		
	}
	execTree->execute();
	return;
}

int main() {
	vector <string> parsedStrings;
	vector <string> connectorOrder;
	vector <executable* > objects;

	while (true) {
		cout << "$ ";

		parsedStrings = parser();
		connectorOrder = findConnectorOrder(parsedStrings);
		objects = makeObjects(parsedStrings);
		
		for (unsigned i = 0; i < objects.size(); ++i) {
			cout << "Object " << i + 1 << endl;
			objects.at(i)->display();
		}
		
		for (unsigned i = 0; i < connectorOrder.size(); ++i) {
			cout << connectorOrder.at(i) << endl;
		}

		executeObjects(objects, connectorOrder);
			
	}

        return 0;
}
