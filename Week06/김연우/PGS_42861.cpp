#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool union(int a, int b);


int solution(int n, vector<vector<int>> costs) {
    int answer = 0;

    // 1. 비용이 작은 순으로 정렬한다.
    sort(costs.begin(), costs.end(), [](vector<int>& a, vector<int>& b) {
        return a[2] < b[2];
    });

    // 2. 간선 즉, 다리를 선택한다.
    for (auto& edge : costs) {
        int u = edge[0];
        int v = edge[1];
        int cost = edge[2];

        if (unite(u, v)) {
            answer += cost;
        }
    }

    return answer;
}

bool union(int a, int b) {

};