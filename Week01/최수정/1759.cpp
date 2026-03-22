#include <iostream>
#include <algorithm>

using namespace std;

int L, C; // 3 ≤ L ≤ C ≤ 15
char arr[20]; //　입력받는 알파벳들 
char pw[20]; 

bool check() {
	int vowel = 0; 
	int consonant = 0; 
	for (int i = 0; i < L; i++) {
		if (pw[i] == 'a' || pw[i] == 'e' || pw[i] == 'i' || pw[i] == 'o' || pw[i] == 'u') vowel++;
		else consonant++;
	}
	if (vowel >= 1 && consonant >= 2) return 1;
	else return 0; 
}

void dfs(int index, int depth) {
	if (depth == L) {
		if (check()) {
			for (int i = 0; i < L; i++) cout << pw[i];
			cout << endl;
		}
		return;
	}
	for (int i = index; i < C; i++) { 
		// arr에 담긴 알파벳을 하나씩 꺼내와서 암호의 depth에 넣음 -> 오름차순 보장
		pw[depth] = arr[i]; 
		dfs(i + 1, depth + 1); 
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> L >> C; 

	for (int i = 0; i < C; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + C); 

	dfs(0, 0); 
	
	return 0; 
	
}