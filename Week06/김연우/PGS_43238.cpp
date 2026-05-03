#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    sort(times.begin(), times.end());

    long long left = 1;
    long long right = (long long)times[0] * n; // least upper bound로 상한을 정한다. 
    long long answer = right;

    while (left <= right) {
        long long mid = (left + right) / 2;

        long long cnt = 0;
        for (int t : times) {
            cnt += mid / t;

            if (cnt >= n) break; // mid시간 동안 cnt명을 처리할 수 있다는 뜻이다.
        }

        if (cnt >= n) {
            answer = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return answer;
}