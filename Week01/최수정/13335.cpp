#include <iostream>
#include <queue>

using namespace std; 

int main() {
	int n, w, L; // w=다리 길이, L=최대 하중
	int truck[1000];

	cin >> n >> w >> L;
	for (int i = 0; i < n; i++) cin >> truck[i];

	queue<int> que;
	
	int count = 0; // 최단 시간
	int current_weight = 0; // 현재 다리에 있는 트럭 무게의 합
	int ti = 0; // truck array 접근하는 index 

	// 일단 que의 원소들을 다 0으로 초기화
	for (int i = 0; i < w; i++) que.push(0); 

	while (ti < n) {
		count++; 

		// 다리의 앞에서 원소 하나씩 빠지기 
		current_weight -= que.front(); 
		que.pop(); 

		// 다음 트럭 진입하기
		if (current_weight + truck[ti] <= L) {
			que.push(truck[ti]); 
			current_weight += truck[ti];
			ti++;
		}
		else { // 최대하중 이상으로 다음 트럭 진입할 수 없는 경우 
			que.push(0); 
		}
	}

	// 마지막 트럭이 다리를 다 빠져나오는 시간
	count += w; // 다리 길이 만큼 더하기 

	cout << count << endl; 
	return 0; 
}