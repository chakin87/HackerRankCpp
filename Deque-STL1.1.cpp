#include <iostream>
//#include <algorithm> 
#include <deque> 
// in high volume use c style prinf scanf
void printKMax(int arr[], int n, int k) {
	std::deque<int> d;
	for (int i = 0; i < n; i++)
	{
		for (; !d.empty() && arr[i] > d.back();)
			d.pop_back();
		d.push_back(arr[i]);
		if (i >= k && d.front() == arr[i - k])
			d.pop_front();
		if (i >= k - 1)
			printf(i < n - 1 ? "%d " : "%d\n", d.front());
	}
}
int main() {
	//the below speeds up cincout soo much it made it pass
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(0);
	int* arr;// non g++ way
	int t;
	std::cin >> t;
	while (t > 0) {
		int n = 0, k = 0;
		std::cin >> n >> k;
		int i;
		arr = new int[n];// non g++ way
		//int arr[n];//swap when g++
		for (i = 0; i < n; i++)
			scanf_s("%d", arr[i]);
		printKMax(arr, n, k);
		t--;
	}

	system("pause");
	return 0;
}