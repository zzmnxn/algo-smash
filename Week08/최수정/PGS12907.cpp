#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 0; i < money.size(); i++) {
        int current = money[i];

        for (int j = current; j <= n; j++) {
            dp[j] += dp[j - current];
            dp[j] = dp[j] % 1000000007;
        }
    }

    return dp[n];
}
