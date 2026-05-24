#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<int> prev = triangle[0];

    for (int row = 1; row < triangle.size(); row++) {

        vector<int> next = triangle[row];

        for (int i = 0; i < next.size(); i++) {
            if (i == 0) {
                next[i] += prev[i];
            }
            else if (i == next.size() - 1) {
                next[i] += prev[i - 1];
            }
            else {
                next[i] += max(prev[i - 1], prev[i]);
            }
        }

        prev = next;
    }
    
    return *max_element(prev.begin(), prev.end());
}