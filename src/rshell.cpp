#include <iostream>
#include <string>
#include <vector>

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

int main() {

        vector<string> inputs = parser();

	for (unsigned i = 0; i < inputs.size(); ++i) {
		cout << inputs.at(i) << endl;
	}

        return 0;
}
