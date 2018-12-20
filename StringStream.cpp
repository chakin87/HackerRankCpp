#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

/*
stringstream ss("23,4,56");
char ch;
int a, b, c;
ss >> a >> ch >> b >> ch >> c;  // a = 23, b = 4, c = 56
*/

vector<int> parseInts(string str) {
	// Complete this function
	std::vector<int> v;
	stringstream ss(str);
	char ch;
	int pushme;
	while (ss >> pushme) {
		v.push_back(pushme);
		ss >> ch;
	}

	return v;

}

int main() {
	string str;
	cin >> str;
	vector<int> integers = parseInts(str);
	for (int i = 0; i < integers.size(); i++) {
		cout << integers[i] << "\n";
	}

	return 0;
}

