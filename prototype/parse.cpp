#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

int main() {

	string example;
	vector<string> parsedInput;

	cout << "Enter any input: " << endl;
	getline(cin, example);

	tokenizer<> tok(example);

	//Iterates through string and stores each parsed string into a vetcor

	for(tokenizer<>::iterator i = (tok.begin()); i != tok.end(); ++i) {
		string temp(*i);
		trim(temp);
		parsedInput.push_back(lexical_cast<string>(temp));
	}

	//prints content of vector
	
	for (unsigned i = 0; i < parsedInput.size(); ++i) {
		cout << "String #" << i + 1 << ": " <<  parsedInput.at(i) << endl;
	}

	return 0;
}
