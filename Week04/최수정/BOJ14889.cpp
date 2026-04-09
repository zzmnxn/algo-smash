#include <iostream>
#include <vector>
using namespace std; 
 
int n;
int arr[20][20];
vector<int> start_team, link_team; 
bool visited[20];
int minimum = 100000000; 

// 각 팀의 능력치 계산 후 비교해서 최솟값 리턴 
int calculate_min() {
	int start_sum = 0; 
	int link_sum = 0; 

	for (int i : start_team) {
		for (int j : start_team) {
			if (i != j) start_sum += arr[i][j]; 
		}
	}

	for (int i : link_team) {
		for (int j : link_team) {
			if (i != j) link_sum += arr[i][j]; 
		}
	}

	if (start_sum > link_sum) { return start_sum - link_sum; }
	else { return link_sum - start_sum; }

}


// 팀 구성하는 함수 
void dfs(int start, int depth) {
	// start팀 구성이 완려되면 visited 여부로 link팀 구성 후 계산
	if (depth == n / 2) {
		link_team.clear();
		for (int i = 0; i < n; i++) {
			if (!visited[i]) link_team.push_back(i);
		}
		int tmp = calculate_min();
		if (tmp < minimum) minimum = tmp;
		return;
	}

	// 백트래킹으로 start팀 구성 연산
	for (int i = start; i < n; i++) {
		visited[i] = true;
		start_team.push_back(i);
		dfs(i + 1, depth + 1);
		start_team.pop_back(); 
		visited[i] = false;
	}
}

int main() {
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
		}
	}

	dfs(0, 0); 

	cout << minimum << endl; 

	return 0; 
}