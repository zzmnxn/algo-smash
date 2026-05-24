#include <string>
#include <vector>

using namespace std;

// 전역 변수 
int global_n;
vector<int> global_money;
vector<vector<int>> table;

int dp(int idx, int sum);

int solution(int n, vector<int> money) {
    
    int answer =0 ;
    global_n = n;
    global_money = money;

    table.assign(global_money.size(), vector<int>(global_n + 1, -1));
    
    answer = dp(0, 0);

    return answer;
}

int dp(int idx, int sum) {
    
    // Base Case
    if (sum == global_n) return 1;
    if (sum > global_n) return 0;
    if (idx == global_money.size()) return 0;

    // Recursive Case
    int &ret = table[idx][sum];
    
    if (ret != -1) return ret;
    ret = (dp(idx, sum + global_money[idx]) + dp(idx + 1, sum)) % 1000000007;
    
    return ret;
}