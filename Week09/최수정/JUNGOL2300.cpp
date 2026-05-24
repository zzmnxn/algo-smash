#include <iostream>
#include <vector>
#include <cmath> 

using namespace std;


int main() {
	// input 배열 입력 
	int N;
	cin >> N;
	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	// 투포인터 탐색 
	int a = 0, b = 0;
	int min = 2000000000;
	int left = 0;
	int right = N - 1;

	while (left < right) {
		int current = arr[left] + arr[right];

		if (abs(current) < min) {
			min = abs(current);
			a = arr[left];
			b = arr[right];
		}

		// 정확히 0이면 바로 종료
		if (current == 0) {
			break;
		}
		
		// 음수면 start를 한 칸 오른쪽으로
		if (current < 0) {
			left += 1;
		} // 양수면 end를 한 칸 왼쪽으로
		else {
			right -= 1;
		}
	}

	cout << a << " " << b << "\n";
	return 0;
}