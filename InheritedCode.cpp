#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <cstring>


//HERE
class BadLengthException : public std::exception {
private:
	int m_error;
	string m_strerror;
public:
	BadLengthException(int _error) : m_error(_error) {}

	const char* what() {
		stringstream ss;
		ss << m_error;
		m_strerror = ss.str();
		return ss.str().c_str();
	}
};
using namespace std;

bool checkUsername(string username) {
	bool isValid = true;
	int n = username.length();
	if (n < 5) {
		throw BadLengthException(n);
	}
	for (int i = 0; i < n - 1; i++) {
		if (username[i] == 'w' && username[i + 1] == 'w') {
			isValid = false;
		}
	}
	return isValid;
}

int main() {
	int T; cin >> T;
	while (T--) {
		string username;
		cin >> username;
		try {
			bool isValid = checkUsername(username);
			if (isValid) {
				cout << "Valid" << '\n';
			}
			else {
				cout << "Invalid" << '\n';
			}
		}
		catch (BadLengthException const& e) {
			cout << "Too short: " << e.what() << '\n';
		}
	}
	return 0;
}