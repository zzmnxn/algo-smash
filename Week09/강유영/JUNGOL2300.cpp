#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> l(n); // 용액
    for (int i = 0; i < n; i++) {
        cin >> l[i];
    }

    // 투 포인터 초기화
    int left = 0;
    int right = n - 1;

    // 0에 가장 가까운 합을 저장할 변수 (최댓값으로 초기화)
    long long min_sum = 2000000001; // 용액 최대 특성값 2개 + 1
    
    // 정답을 담을 두 용액의 값
    long long ans_left = 0;
    long long ans_right = 0;

    while (left < right) {
        long long current_sum = l[left] + l[right];

        // 현재 두 용액의 합이 0에 더 가깝다면 정답 갱신
        if (abs(current_sum) < min_sum) {
            min_sum = abs(current_sum);
            ans_left = l[left];
            ans_right = l[right];
        }

        // 합이 0보다 작으면 더 큰 숫자가 필요하므로 left를 오른쪽으로
        if (current_sum < 0) {
            left++;
        } 
        // 합이 0보다 크면 더 작은 숫자가 필요하므로 right를 왼쪽으로
        else if (current_sum > 0) {
            right--;
        } 
        // 합이 정확히 0이면 이보다 더 0에 가까울 수 없으므로 종료
        else {
            break;
        }
    }

    cout << ans_left << " " << ans_right << "\n";

    return 0;
}