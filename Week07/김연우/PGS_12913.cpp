#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> land)
{
    int n = land.size();

    int a = land[0][0];
    int b = land[0][1];
    int c = land[0][2];
    int d = land[0][3];

    for (int i = 1; i < n; i++) {
        int na = land[i][0] + max(max(b, c), d);
        int nb = land[i][1] + max(max(a, c), d);
        int nc = land[i][2] + max(max(a, b), d);
        int nd = land[i][3] + max(max(a, b), c);

        a = na;
        b = nb;
        c = nc;
        d = nd;
    }

    return max(max(a, b), max(c, d));
}
