#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> money) {
    vector<int> dp(n + 1, 0);

    dp[0] = 1;

    for (int coin : money) {
        for (int sum = coin; sum <= n; sum++) {
            dp[sum] = (dp[sum] + dp[sum - coin]) % 1000000007;
        }
    }

    return dp[n];
}