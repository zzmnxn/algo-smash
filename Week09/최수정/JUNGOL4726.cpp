#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	int N; 
	cin >> N; 
	
	vector<long long> arr(N);
	vector<long long> sum(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i]; 
		// 穿利钦 拌魂
		if (i == 0) {
			sum[i] = arr[i]; 
		}
		else {
			sum[i] = sum[i - 1] + arr[i]; 
		}
	}

	long long total = sum[N - 1];
	long long max_honey = 0;

	// 吝埃 
	for (int i = 1; i < N - 1; i++) {
		// case 1: 国(0) - 国(i) - 国烹(N-1)
		long long case1 = (total - arr[0] - arr[i]) + (total - sum[i]); 
		max_honey = max(max_honey, case1); 

		// case 2: 国烹(0) - 国(i) - 国(N-1)
		long long case2 = sum[i - 1] + (total - arr[N - 1] - arr[i]); 
		max_honey = max(max_honey, case2); 

		// case3: 国(0) - 国烹(i) - 国(N-1)
		long long case3 = (sum[i] - arr[0]) + (total - sum[i - 1] - arr[N - 1]); 
		max_honey = max(max_honey, case3); 
	}

	cout << max_honey << "\n"; 
	
	return 0; 
}