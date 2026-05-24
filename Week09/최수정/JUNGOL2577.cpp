#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, d, k, c;
    cin >> N >> d >> k >> c;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // 원형 회전 처리하기 위해 뒤에 k-1개만큼 덧붙이기 
    for (int i = 0; i < k - 1; i++) {
        arr.push_back(arr[i]);
    }

    queue<int> q; // 현재 먹은 초밥을 담을 윈도우
    vector<int> count(d + 1, 0); // 각 초밥 번호별 개수 체크 배열

    int current_kinds = 0; // 현재 큐 안의 초밥 가짓수
    int max_kinds = 0; // 최대로 먹을 수 있는 초밥 가짓수

    for (int i = 0; i < arr.size(); i++) {
        int next = arr[i];

        q.push(next);
        if (count[next] == 0) {
            current_kinds++; // 큐에 처음 들어오는 종류라면 가짓수 증가
        }
        count[next]++;

        // 큐의 크기가 k를 초과하면 맨 앞의 초밥을 제거
        if (q.size() > k) {
            int remove = q.front();
            q.pop();

            count[remove]--;
            if (count[remove] == 0) {
                current_kinds--; // 완전히 사라진 종류라면 가짓수 감소
            }
        }

        // 큐에 k개가 있으면 정답 최댓값 갱신
        if (q.size() == k) {
            int total_kinds = current_kinds;

            // 쿠폰 초밥이 현재 큐에 없으면 가짓수 
            if (count[c] == 0) {
                total_kinds++;
            }

            max_kinds = max(max_kinds, total_kinds);
        }
    }

    cout << max_kinds << "\n";

    return 0;
}