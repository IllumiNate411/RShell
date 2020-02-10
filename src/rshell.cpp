#include <iostream>
#include <string>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace boost;

vector<string> parser() {
	string example;
        vector<string> parsedInput;

        cout << "Enter any input: " << endl;
        getline(cin, example);

        tokenizer<> tok(example);

        for(tokenizer<>::iterator i = (tok.begin()); i != tok.end(); ++i) {
                string temp(*i);
                trim(temp);
                parsedInput.push_back(lexical_cast<string>(temp));
        }

        for (unsigned i = 0; i < parsedInput.size(); ++i) {
                cout << "String #" << i + 1 << ": " <<  parsedInput.at(i) << endl;
        }

	return parsedInput;
}

int main() {

        vector<string> inputs = parser();
        return 0;
}
