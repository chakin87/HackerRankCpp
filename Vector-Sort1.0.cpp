#include <vector>
#include <iostream>
#include <algorithm> //std::sort



int main(int argc, char** argv[]) {

	std::vector<size_t> v;

	size_t i = 0; //size_t is %zu for printf and scanf
	size_t k = 0;

	scanf_s("%zu", &i);
	
	//v.resize(i);
	//std::cout << "v.size() = " << v.size() << std::endl;
	for (size_t j = 0; j < i; ++j) {
		std::cin >> k;
		v.push_back(k);
		//std::cout << "v.size() = " << v.size() << std::endl;
	}

	std::sort(v.begin(), v.end());

	for (size_t j = 0; j < v.size(); ++j) {
		if (j == v.size() - 1) {
			printf("%zu", v[j]);
		}
		else {
			printf("%zu ", v[j]);
		}
	}


	//system("pause");

	return 0;
}