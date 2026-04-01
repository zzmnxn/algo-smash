#include <iostream>
#include <vector>

using namespace std; 

vector<int> solution(vector<int> sequence, int k) {
    int si = 0, ei = 0;
    int total = sequence[0];

    // 배열을 [0, (최대길이)]로 초기화  
    vector<int> answer = { 0, (int)sequence.size() - 1 };

    while (ei < (int)sequence.size()) {
        if (total < k) {
            ei++;
            if (ei < (int)sequence.size()) total += sequence[ei];
        }
        else if (total > k) {
            total -= sequence[si];
            si++;
        }
        else {  // total == k
            // 더 짧은 배열이면 갱신
            if ((ei - si) < (answer[1] - answer[0])) {
                answer = { si, ei };
            }
            // 같은 합을 가진 더 짧은 수열이 있을 수 있으니 계속 탐색
            total -= sequence[si];
            si++;
        }
    }

    return answer;
}