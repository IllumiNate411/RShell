#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <string.h>
#include <bits/stdc++.h>
#include "../header/parser.hpp"

using namespace std;

parser::~parser() {
	while(!parsedStrings.empty()) {
		parsedStrings.pop_back();
	}
	while(!objects.empty()) {
                objects.pop_back();
        }
}

void parser::parseStrings(string input) {

	char curr;
	int sz = input.size();
	int next = 0;
	int parenIter = 0;
	unsigned j = 0;
	
	for (unsigned i = 0; i < sz; ++i) {
		char curr = input.at(i);
		//finds quotes to be echoed		
		if (curr == '"') {
			next = input.find('"', i + 1);
			parsedStrings.push_back(input.substr(i + 1, next - i - 1));
			i = next;
		}
		//looks for brackets that signify test
		else if (curr == '[') {
			if (input.find(']',i) != string::npos) {
				parsedStrings.push_back("test");
			}
		}
		//parses parentheses seperately
		else if (curr == '(') {
			parsedStrings.push_back(input.substr(i, 1));
		} 
		//ignores comments
		else if (curr == '#') {
			i = sz - 1;
		}
		//want to ignore spaces and close brackets
		else if (curr != ' ' && curr != ']') {
			//checks if we need to add -e after test
			if (parsedStrings.size() >= 1) {
				if (parsedStrings.back() == "test" && curr != '-') {
					parsedStrings.push_back("-e");
				}
			}
			//takes a substring of current position up until next space
			if (input.find(' ', i) != string::npos) {
				next = input.find(' ', i);
				parenIter = next;
				//accounts for closed parentheses case and parses them seperately
				while (input.at(parenIter - 1) == ')') {
					--parenIter;
				}
				//accounts for semicolon case and parses the semicolon seperately
				if (input.at(next - 1) == ';') {
					//finds out how many closed parentheses we have
					--parenIter;
					while (input.at(parenIter - 1) == ')') {
                                        	--parenIter;
                                	}	
					++parenIter;

					parsedStrings.push_back(input.substr(i, parenIter - i - 1));

					for (j = 0; j < next - parenIter; ++j) {
                                        	parsedStrings.push_back(")");
                                	}

					parsedStrings.push_back(";");
					i = next;
				}
				else {
					parsedStrings.push_back(input.substr(i, parenIter - i));
					
					for (j = 0; j < next - parenIter; ++j) {
                                        	parsedStrings.push_back(")");
                                	}
					i = next;
				}
			}
			//in case the last portion to be parsed goes to the end of string
			else {
				parenIter = sz - 1;
				//accounts for parentheses at the end of the input	
				while (input.at(parenIter) == ')') {
                                        --parenIter;
                                }
				//for semicolon at the end
				if (input.find(';', i) != string::npos) {
					--parenIter;
                                        while (input.at(parenIter) == ')') {
                                                --parenIter;
                                        }
					++parenIter;

					parsedStrings.push_back(input.substr(i, parenIter - i));

					for (j = 0; j < sz - 1 - parenIter; ++j) {
                                        	parsedStrings.push_back(")");
                                	}
					i = sz - 1;
				}
				else {
					parsedStrings.push_back(input.substr(i, parenIter + 1 - i));

					for (j = 0; j < sz - 1 - parenIter; ++j) {
                                        	parsedStrings.push_back(")");
                                	}
					i = sz - 1;
				}
			}
		}
	}
	return;
}

//goes through input and creates expression objects for each expression, connector, and parenthesis
void parser::makeObjects() {
	//cout << "This is the beginning of makeObjects" << endl;
	int k = 0;
        const char* tempArr[5];

        for (unsigned i = 0; i < parsedStrings.size(); ++i) {
      if(isOperator(parsedStrings.at(i))) {
			if (i != parsedStrings.size()) {
				tempArr[k] = '\0';
				k = 0;
				if (strcmp(tempArr[0], "test") == 0) {
					objects.push_back(new test(tempArr));
				}
				else {
                        		objects.push_back(new expression(tempArr));
                		}

				if (parsedStrings.at(i) == "&&") {
					objects.push_back(new And());
				}
				else if (parsedStrings.at(i) == "||") {
                                        objects.push_back(new Or());
                                }
				else if (parsedStrings.at(i) == ";") {
                                        objects.push_back(new Semicolon());
                                }
			}
		}
		else if (parsedStrings.at(i) == ")" || parsedStrings.at(i) == "(") {
			objects.push_back(new Paren(parsedStrings.at(i)));
		}
                else {
                        tempArr[k] = StringToCString(parsedStrings.at(i));
                        ++k;
                }
        }

        tempArr[k] = '\0';
	if (strcmp(tempArr[0], "test") == 0) {
		objects.push_back(new test(tempArr));
	}
	else {
		objects.push_back(new expression(tempArr));
	} 

	return;
}

vector<executable* > parser::infixToPostfix(vector <executable* > infix) {
	infix.insert(infix.begin(), new Paren("("));
	infix.push_back(new Paren(")"));

	int sz = infix.size();
	stack<executable* > stack;
	vector <executable* > postfix;

	for (int i = 0; i < sz; ++i) {
		if (infix.at(i)->getType() == "exp") {
			cout << "HI" << endl;
			postfix.push_back(infix.at(i));
		}
		else if (infix.at(i)->getType() == "(") {
			stack.push(infix.at(i));
		}
		else if (infix.at(i)->getType() == ")") {
			while (stack.top()->getType() != "(") {
				postfix.push_back(stack.top());
				stack.pop();
			}
			stack.pop();
		}
		else {
			while (isOperator(stack.top()->getType()) ) {
				postfix.push_back(stack.top());
				stack.pop();
			}
			stack.push(objects.at(i));
		}
	}

	return postfix;
}

void parser::infixToPrefix() {
	int sz = objects.size();
	vector <executable* > temp;
	vector <executable* > temp2;
	for (int i = sz - 1; i > -1; --i) {
		temp.push_back(objects.at(i));
	}
	//reverse(objects.begin(), objects.end());

	for (unsigned i = 0; i < sz; ++i) {
		if (temp.at(i)->getType() == "(") {
			temp.at(i)->setType(")");
			++i;
		}
		else if (temp.at(i)->getType() == ")") {
			temp.at(i)->setType("(");
			++i;
		}
	}

	temp = infixToPostfix(temp);
	for (int i = sz - 1; i > -1; --i) {
                temp2.push_back(temp.at(i));
        }

	objects = temp2;
	//reverse(objects.begin(), objects.end());
}


void parser::executeObjects() {
	if (objects.size() == 1) {
		objects.at(0)->execute();
		return;
	}
	executable* execTree = objects.at(0);

	for (unsigned i = 1; i < objects.size(); ++i) {
		if (isOperator(objects.at(i)->getType())) {
			objects.at(i)->setLHS(execTree);
			objects.at(i)->setRHS(objects.at(i + 1));
			execTree = objects.at(i);
			++i;
		}	
	}	

	execTree->execute();
	return;
}

string parser::stringsAt(int index) {
	return parsedStrings.at(index);
}

string parser::objectsAt(int index) {
	return objects.at(index)->getType();
}

const char* parser::StringToCString(string str) {
        const char* cstring;
        cstring = str.c_str();

        return cstring;
}

bool parser::isOperator(string c) {

	if (c == "&&" || c == "||" || c == ";") {
		return true;
	}
	return false;
}
