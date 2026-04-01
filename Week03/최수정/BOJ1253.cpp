#include <iostream>
#include <algorithm>

using namespace std;

int arr[2000];

bool isGOOD(int targetIdx, int n) {
	int target = arr[targetIdx]; 
	int start = 0; 
	int end = n - 1;

	while (start < end) { 
		// 자기 자신은 포함될 수 없음 
		if (start == targetIdx) {
			start++; 
			continue; 
		}
		if (end == targetIdx) {
			end--; continue; 
		}

		int currentSum = arr[start] + arr[end];

		// 두 수의 합이 타겟과 같은지 확인
		if (currentSum == target) {
			return true; // GOOD이며 바로 true 반환
		}
		else if (currentSum < target) {
			start++;
		}
		else {
			end--;
		}
	}

	return false; // 끝까지 못 찾아내면 false 
}


int main() {
	int n; 
	cin >> n; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 
	
	int result_count = 0;

	for (int i = 0; i < n; i++) {
		if (isGOOD(i, n)) {
			result_count++;
		}
	}

	cout << result_count << endl; 

	return 0;
}