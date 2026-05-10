#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long dp(int n);

long long solution(int n) {
    return dp(n) % 1234567;
}

long long dp(int n) {
    if (n == 1) {
        return 1;
    }
    else if (n == 2) {
        return 2;
    }
    else {
        return (dp(n-1)+dp(n-2)) % 1234567;
    }
}