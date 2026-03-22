#include <iostream>
#include <queue>
#include <algorithm> // sort()

using namespace std; 


int main() {
	int N, M; 
	int arr[10000]; 

	cin >> N >> M; 
	for (int i = 0; i < N; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + N, greater<int>()); 

	/* 콘센트 M개를 0으로 초기화하기 */
	// 루트가 최소값인 우선순위 큐
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < M; i++) pq.push(0); 

	// 각 전자기기를 루트 큐에 누적 
	for (int i = 0; i < N; i++) {
		// 가장 최소값을 tmp에 저장했다가 pop하고 arr[i]와 더해서 다시 push
		int tmp = pq.top();
		pq.pop(); 
		pq.push(arr[i] + tmp);
	}

	// 최댓값 찾기 
	int max_time = 0; 
	while (!pq.empty()) {
		max_time = pq.top(); // 가장 마지막에 나오는 값이 최대값
		pq.pop(); 
	}
	cout << max_time << endl; 

	return 0; 
}