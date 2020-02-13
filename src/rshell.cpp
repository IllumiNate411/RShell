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

int main() {

	cout << "$ ";

        vector<string> inputs = parser();

	const char* cstringInputs[inputs.size() + 1];
	/*
	//converts vector of strings into vector of const char* (cstrings)
        for (unsigned i = 0; i < inputs.size(); ++i) {
		cstringInputs[i] = StringToCString(inputs.at(i));
		cout << cstringInputs[i] <<  endl;	
        }
	
        cstringInputs[inputs.size() + 1] = "\0";
        */

	int k = 0;
	const char* tempArr[5];
	vector<expression*  > objectVec;
	vector<string> connectorOrder;
	
	for (unsigned i = 0; i < inputs.size(); ++i) {
		if(inputs.at(i) == "&&") {
			tempArr[k] = '\0';
			objectVec.push_back(new expression(tempArr));
			k = 0;
			connectorOrder.push_back("&&");
		}
		else if(inputs.at(i) == "||") {
			tempArr[k] = '\0';
			objectVec.push_back(new expression(tempArr));
			k = 0;
			connectorOrder.push_back("||");
		}
		else if(inputs.at(i) == ";") {
			tempArr[k] = '\0';
			objectVec.push_back(new expression(tempArr));
			connectorOrder.push_back(";");
			k = 0;
		}
		else {	
			tempArr[k] = StringToCString(inputs.at(i));
			++k;
		}
	}

	tempArr[k] = '\0';
        objectVec.push_back(new expression(tempArr));

	for (unsigned i = 0; i < objectVec.size(); ++i) {
		cout << "Object " << i << endl;
		objectVec.at(i)->display();
	}

	

        return 0;
}
