#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int n = land.size();

    vector<vector<int>> dp(n, vector<int>(4, 0));

    for(int j=0; j<4; j++) {
        dp[0][j] = land[0][j];
    }

    for(int i=1; i<n; i++) {
        dp[i][0] = land[i][0] + max({dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
        dp[i][1] = land[i][1] + max({dp[i - 1][0], dp[i - 1][2], dp[i - 1][3]});
        dp[i][2] = land[i][2] + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][3]});
        dp[i][3] = land[i][3] + max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2]});
    }

    return max({dp[n-1][0], dp[n-1][1], dp[n-1][2], dp[n-1][3]})
}