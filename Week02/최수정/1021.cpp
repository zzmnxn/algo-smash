#include <iostream>
#include <queue>

using namespace std;

int find_min(int num, queue<int>& q) {
    int left = 0; // 왼쪽으로 회전하는 경우의 count 
    // right로 회전하는 경우는 전체 큐 사이즈에서 왼쪽에서 회전하는 경우를 빼면 됨 
    int size = q.size();

    while (q.front() != num) {
        ++left;
        int tmp = q.front();
        q.pop();
        q.push(tmp);
    }

    q.pop();  // num 뽑기
    return min(left, size - left);
}

int main() {
    int N, M;
    cin >> N >> M;

    // 큐에 int 매핑하기 
    queue<int> q;
    for (int i = 0; i < N; i++) {
        q.push(i + 1);
    }

    // find_min 함수를 통해 찾은 최소값을 sum 더하면서 반복문 돌기 
    int sum = 0;
    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        sum += find_min(num, q);
    }

    cout << sum << endl;
    return 0;
}

