#include <iostream>
#include <exception>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>
using namespace std;

/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
try {
	//code that may result in exceptions being thrown
}
catch (type of exception to be caught) {
	//action to take when this exception is caught
}
catch (alternative type of exception to be caught) {
	//action to take when this alternative exception is caught
}*/
//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ +
class Server {
private:
	static int load;
public:
	static int compute(long long A, long long B) {
		load += 1;
		if (A < 0) {
			throw std::invalid_argument("A is negative");
		}
		vector<int> v(A, 0);
		int real = -1, cmplx = sqrt(-1);
		if (B == 0) throw 0;
		real = (A / B)*real;
		int ans = v.at(B);
		return real + A - B * ans;
	}
	static int getLoad() {
		return load;
	}
};
int Server::load = 0;

int main() {
	int T; cin >> T;
	while (T--) {
		long long A, B;
		cin >> A >> B;
	//>>>>>>>>>>>>HERE<<<<<<<<<<<<<<<
		try {
			std::cout << Server::compute(A, B) << std::endl;
		}
		catch (std::bad_alloc& e) {
			std::cout << "Not enough memory" << std::endl;
		}
		catch (std::exception& e) {
			std::cout << "Exception: " << e.what() << std::endl;
		}
		catch (...) {
			std::cout << "Other Exception" << std::endl;
		}

	}
	cout << Server::getLoad() << endl;
	return 0;
}