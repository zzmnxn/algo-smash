#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int solution(vector<int> stones, int k) {
    deque<int> dq; 
    int answer = 200000000;

    for (int i = 0; i < stones.size(); i++) {
        while (!dq.empty() && dq.front() <= i - k) {
            dq.pop_front();
        }

        while (!dq.empty() && stones[dq.back()] <= stones[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        if (i >= k - 1) {
            int windowMax = stones[dq.front()];
            answer = min(answer, windowMax);
        }
    }

    return answer;
}