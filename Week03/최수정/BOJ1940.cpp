#include <iostream>
#include <algorithm>

using namespace std; 


int main() {
	int n, m;
	cin >> n>> m; 

	int* arr = new int[n]; 

	for (int i = 0; i < n; i++) {
		cin >> *(arr + i);
	}

	// 배열 정렬하기 
	sort(arr, arr + n); 

	// 정렬한 배열의 가장 앞, 가장 뒤부터 접근하면서 판단
	int start = 0; 
	int end = n - 1; 
	int result = 0; 
	while (start < end) {
		// 두개의 재료 덧셈이 m과 같다면 result++; 
		if (arr[start] + arr[end] == m) {
			result++; 
			start++; 
			end--;
		}
		// m보다 작으니까 start index +1; 
		else if (arr[start] + arr[end] < m) {
			start++; 
		}
		else {
			end--; 
		}
	}

	cout << result << endl;

	return 0; 
}