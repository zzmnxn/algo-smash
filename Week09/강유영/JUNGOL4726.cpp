#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> honey(n);
    vector<long long> psum(n);

    // 입력 & 누적합 갱신
    for (int i = 0; i < n; i++) {
        cin >> honey[i];
        if (i == 0) {
            psum[i] = honey[i]; // 첫 번째 꿀인 경우
        } else {
            psum[i] = psum[i - 1] + honey[i];
        }
    }

    long long max_honey = 0; // 최대 꿀 양

    // 경우 1: [벌1] - [벌2] - [벌통]
    // 벌1은 0번에 고정, 벌통은 n-1번에 고정, 벌2의 위치(i)를 변경
    for (int i = 1; i < n - 1; i++) {
        long long bee1 = psum[n - 1] - honey[0] - honey[i]; // bee1, bee2 제외
        long long bee2 = psum[n - 1] - psum[i]; // bee2 ~ 꿀통 직전까지
        max_honey = max(max_honey, bee1 + bee2);
    }

    // 경우 2: [벌통] - [벌1] - [벌2]
    // 벌통은 0번에 고정, 벌2는 n-1번에 고정, 벌1의 위치(i)를 변경
    for (int i = 1; i < n - 1; i++) {
        long long bee2 = psum[n - 2] - honey[i]; // n-1번 자리 bee2 제외, i번 bee1 제외
        long long bee1 = psum[i - 1]; // 벌통 ~ bee1 직전까지
        max_honey = max(max_honey, bee1 + bee2);
    }

    // 경우 3: [벌1] - [벌통] - [벌2]
    // 벌1은 0번에 고정, 벌2는 n-1번에 고정, 벌통의 위치(i)를 변경
    for (int i = 1; i < n - 1; i++) {
        // 벌1에서 벌통까지 + 벌2에서 벌통까지 (각각 자기 위치 꿀은 제외됨)
        long long bee1 = psum[i] - honey[0];
        long long bee2 = psum[n - 1] - psum[i - 1] - honey[n - 1];
        max_honey = max(max_honey, bee1 + bee2);
    }

    cout << max_honey << endl;

    return 0;
}