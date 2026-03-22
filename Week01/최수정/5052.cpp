#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std; 

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int t, n; 
	bool flag = 1; 
	string input_string ;
	vector<string> numbers = {}; 

	cin >> t; 

	for (int i = 0; i < t; i++) {
		cin >> n; 
		for (int j = 0; j < n; j++) {
			cin >> input_string;
			numbers.push_back(input_string);
		}

		// 정렬 -> 정렬하면 순서대로 + 길이가 낮은 순으로 정렬됨
		// 인전합 2개의 전번들만 비교하면 접두어인지 찾을 수 있음 
		sort(numbers.begin(), numbers.end()); 

		for (int j = 0; j < n - 1; j++) {
			if (numbers[j + 1].find(numbers[j]) == 0) {
				flag = 0; 
				break; 
			}
		}

		// 출력 
		if (flag) cout << "YES" << endl;
		else cout << "NO" << endl;
		flag = 1;

		// 벡터 초기화
		numbers.clear(); 
	}
	
	return 0; 
}