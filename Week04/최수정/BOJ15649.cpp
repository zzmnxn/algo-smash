#include <iostream>
 
using namespace std; 

int arr[10]; 
bool visited[10]; 
int n, m; 

void dfs(int depth) {
	// 깊이 탐색 끝나면 출력하고 return
	if(depth == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << " "; 
		}
		cout << "\n";
		return; 
	}
	// 1부터 n까지 숫자를 하나씩 시도 
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = true;  
			arr[depth] = i; // 수열에 추가 

			dfs(depth + 1); // 재귀
			
			visited[i] = false; // 재귀 끝났으니 다시 미사용 처리
		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m; // 자연수 1~n 중 중복 없이 m개를 고른 수열

	dfs(0);

	return 0; 
}