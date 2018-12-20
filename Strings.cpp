#include <iostream>
#include <string>
using namespace std;

//--------------------------------------------------------------------------------------
/// turn plus signs into spaces first
int pos;
while ((pos = sSrc.find("+")) != string::npos)
{
	sSrc[pos] = ' ';
}
//--------------------------------------------------------------------------------------

int main() {
	// Complete the program

	std::string a, b, a2, b2, temp;

	std::cin >> a;
	std::cin >> b;

	std::cout << a.size() << " " << b.size() << std::endl;
	
	std::cout << a << b << std::endl;

	for (int i = 0; i < a.size(); ++i) {
		if (i == 0) a2 = b[0];
		else a2 += a[i];
	}
	for (int i = 0; i < b.size(); ++i) {
		if (i == 0) b2 = a[0];
		else b2 += b[i];
	}
	std::cout << a2 << " " << b2 << std::endl;

	//system("pause");

	return 0;
}