#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    int tmp = lost.size();

    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());

    // 1. 먼저, 여벌 체육복을 가져온 학생이 도난당한 경우를 처리한다.
    for (auto it = lost.begin(); it != lost.end();) {
        bool removed = false;

        for (auto r = reserve.begin(); r != reserve.end(); ++r) {
            if (*it == *r) {
                it = lost.erase(it);
                reserve.erase(r);
                tmp--;
                removed = true;
                break;
            }
        }

        if (!removed) ++it;
    }
    // 2. 여벌 체육복을 빌려준다.
    for (int x : lost) {
        for (auto it = reserve.begin(); it != reserve.end(); ++it) {
            if (*it == x - 1) {
                reserve.erase(it);
                tmp--;
                break;
            }
            if (*it == x + 1) {
                reserve.erase(it);
                tmp--;
                break;
            }
        }
    }
    answer = n - tmp;
    
    return answer;
}