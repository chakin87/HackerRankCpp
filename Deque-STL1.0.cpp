#include <iostream>
#include <deque> 
#include <vector>


void printKMax(std::vector<int> v, int n, int k, bool isfirstrun) {
	size_t crs = 0;
	size_t max = 0;
	size_t itr = 0;
	std::deque<int> d;
	

	for (size_t s = 0; s < ((n - k) + 1); ++s) {
		if (itr == 0) {
			for (size_t i = itr; i < (k); ++i, ++itr) {
				d.push_back(v[i]);
			}
		}
		else {
			//std::cout << "d.push_back(v[itr])" << std::endl;
			if (itr < v.size()) {
				d.push_back(v[itr]);
				++itr;
			}
		}
	
		//std::cout << "\n"; for (size_t t = 0; t < d.size(); ++t) { std::cout << "d[" << t << "] = " << d[t]<< std::endl; }
	
		for (size_t j = 0; j < (d.size()); ++j) {
			d[j] > max ? max = d[j] : max = max;
		}
		
		d.pop_front();
		std::cout << max << " ";
		max = 0;
	}
	if (isfirstrun && (n > 1)) { std::cout << std::endl; }
}

int main() {

	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int t;
	bool firsttime = true;
	std::vector<int> vecn;
	std::cin >> t;
	while (t > 0) {
		int n, k;
		std::cin >> n >> k;
		vecn.resize(n);
		for (int i = 0; i < vecn.size(); i++)
			std::cin >> vecn[i];
		printKMax(vecn, n, k, firsttime);
		t--;
		firsttime = false;
	}

	system("pause");
	return 0;
}