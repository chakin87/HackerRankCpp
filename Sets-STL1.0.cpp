
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <algorithm>



/*
"The name of the Lord is a strong tower; 
the righteous run into it and are safe.
	Psalm 18:10
*/

/* <SETS>
s.erase(val); //Erases an integer val from the set s.
//Gives the iterator to the element val if it is found otherwise returns s.end() .
set<int>::iterator itr=s.find(val);
//If 100 is not present then it==s.end().
Ex: set<int>::iterator itr=s.find(100); 
*/


int main(int argc, char** argv[]) {

	size_t a, b, c, d, e;
	std::set<size_t> s;

	std::cin >> a;

	for (b = 0; b < a; ++b) {

		std::cin >> c;
		if (c == 1) {
			std::cin >> d;
			s.insert(d);
		}
		else if (c == 2) {
			std::cin >> d;
			s.erase(d);
		}
		else if (c == 3) {
			std::cin >> d;
			std::set<size_t>::iterator it = s.find(d);
			if (it != s.end()) {
				std::cout << "Yes" << std::endl;
			}
			else {
				std::cout << "No" << std::endl;
			}
		}
		else {
			std::cout << "Error! :(" << std::endl;
		}
	}

	//system("pause");

	return 0;
}