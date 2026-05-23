#include <vector>

using namespace std;

long long solution(int n) {

    // n이 홀수이면 답을 구할 수 없으므로 0 리턴 
    if (n % 2 != 0) return 0;

    vector<long long> dp(n + 1, 0);
    long long MOD = 1000000007;

    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i += 2) {
        long long tmp = dp[i - 2] * 4 - dp[i - 4];

        dp[i] = (tmp % MOD + MOD) % MOD;
    }

    return dp[n];
}