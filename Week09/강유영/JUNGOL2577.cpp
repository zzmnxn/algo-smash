#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 초밥 종류별로 현재 몇 개가 포함되어 있는지 기록할 배열
int sushi_count[3001000]; 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d, k, c; 
    // n: 접시, d: 초밥 종류 수, k: 연속해서 먹는 접시 수, c: 쿠폰 번호
    cin >> n >> d >> k >> c;

    vector<int> belt(n);
    for (int i = 0; i < n; i++) {
        cin >> belt[i];
    }

    // 앞쪽 k-1 항목을 뒤에 추가
    // 배열 맨 마지막 초밥에서부터 연속으로 먹는 경우를 고려
    for (int i = 0; i < k - 1; i++) {
        belt.push_back(belt[i]);
    }

    int current = 0; // 현재 초밥 종류 수
    int result = 0; // 먹을 수 있는 초밥 종류 수 최대값

    // 처음으로 연속으로 먹는 경우 sushi_count 초기화
    for (int i = 0; i < k; i++) {
        if (sushi_count[belt[i]] == 0) {
            current++; // sushi_count에서 값이 0이면 새로운 종류이므로
        }
        sushi_count[belt[i]]++;
    }

    // 첫 연속 상태에서, 쿠폰 고려해서 최댓값 초기화
    if (sushi_count[c] == 0) { // 쿠폰 번호에 해당 초밥이 현재 연속 안에 없으면
        result = current + 1;
    } else {
        result = current;
    }

    // 테이블 연속을 한 칸씩 옆으로 (i는 빠지는 원소의 인덱스)
    for (int i = 0; i < n - 1; i++) {
        // 왼쪽 원소(belt[i]) 제거
        sushi_count[belt[i]]--;
        if (sushi_count[belt[i]] == 0) {
            current--; // 더 이상 이 종류의 초밥이 없으면 종류 감소
        }

        // 오른쪽 원소(belt[i + k]) 추가
        int next_sushi = belt[i + k];
        if (sushi_count[next_sushi] == 0) {
            current++; // 처음 들어오는 종류면 종류 증가
        }
        sushi_count[next_sushi]++;

        // 쿠폰 초밥을 포함한 최종 종류 수 계산
        int total = current;
        if (sushi_count[c] == 0) {
            total++; // 쿠폰 초밥이 윈도우에 없다면 보너스 +1
        }

        // 최댓값 갱신
        result = max(result, total);
    }

    cout << result << endl;

    return 0;
}