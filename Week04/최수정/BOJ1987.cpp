#include <iostream>

using namespace std; 

int r, c;
char arr[21][21];
int alphabet[26]; 
int max_result  = 0; 

// 좌표 이동을 위한 방향 
int move_x[4] = { -1, 1, 0, 0 };
int move_y[4] = { 0, 0, -1, 1 };

void dfs(int x, int y, int count) {
	// 모든 경로 중 갈 수 있는 최댓값을 찾으면 되기 때문에 
	// 파라미터로 들어오느 count와 max값을 비교 
	max_result = max(max_result, count); 


	for (int i = 0; i < 4; i++) {
		int next_x = x + move_x[i]; 
		int next_y = y + move_y[i]; 

		if (next_x < 0 || next_x >= r || next_y < 0 || next_y >= c) continue; 

		int tmp_alpha = arr[next_x][next_y] - 'A'; 

		if (!alphabet[tmp_alpha]) { // 해당 알파벳을 한번도 가본 적 없다면 실행
			alphabet[tmp_alpha] = true; 
			dfs(next_x, next_y, count + 1); 
			alphabet[tmp_alpha] = false; 
		}
	}
}


int main() { 
	cin >> r >> c; 
 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j];
		}
	}

	alphabet[arr[0][0] - 'A'] = true; 
	dfs(0, 0, 1); 
	
	cout << max_result << endl; 
	return 0;
}