#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

/*
"In your strength I can crush an army; with my god I can scale any wall."
	Psalm 18:29
*/


int main(int argc, char** argv[]) {

	size_t i, j, k, l, n, q;

	std::vector<int> v;

	//scanf 'n' is number of ints in vec
	scanf_s("%zu", &n);

	for (i = 0; i < n; ++i) {
		//fill vec with sorted int list
		std::cin >> j;
		v.push_back(j);

	}
	//k is number of queries that are going to be performed
	scanf_s("%zu", &k);

	for (l = 0; l < k; ++l) {
		//scanf q is taking query q and now perform
		//algorithm to produce the desired output
		scanf_s("%zu", &q);
		
		// query and ouptut follows
		std::vector<int>::iterator it = std::lower_bound(v.begin(), v.end(), q);
		
		if (v[it - v.begin()] == q) {
			std::cout << "Yes " << (it - v.begin() + 1) << std::endl;
		}
		else {
			std::cout << "No " << (it - v.begin() + 1) << std::endl;
		}
	
 
	}


	//system("pause");

	return 0;
}
