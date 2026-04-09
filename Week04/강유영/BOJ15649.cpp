#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int n, m;
vector<bool> visited(9); // 방문한 곳 표시
// (N <= 8 이고 원소는 1부터 저장되기 때문에 [0]위치는 비워두려고 크기를 9로 잡음)

void backtracking(vector<int>& cur){
    if(cur.size() == m){ // m 크기 만큼 수열이 완성됐으므로 출력!
        // 출력
        for(int c : cur){ // 주의 : 출력할 때 cur을 비우면 안됨
            cout << c << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 이 백트래킹은 순서대로 뒤로 가는 것이 아니라, 상황에 따라 앞의 원소가 출력되어야 하기 때문에 for 사용
    for(int i=1; i<=n; i++){ // i자체가 원소이다.
        if(visited[i]){ // 이미 방문한 곳이라면
            continue;
        }
        visited[i] = true; // 방문한 곳 처리
        
        cur.push_back(i);
        backtracking(cur); // 백트래킹
        cur.pop_back();
        visited[i] = false; // 해당 i는 이미 for문에서 지나갔기 때문에 다시 false처리를 해줘도 나중에 나오지 않는다.
        // ex. [ 1... ] 로 시작하는 수열을 완성하고 다시 돌아와서
        // [2 ... ] 로 시작하는 수열을 만들 때 visited[1] = false 기에 [2 1 ... ] 이 가능해지는 것
        
    }
}



int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    
    vector<int> cur;

    backtracking(cur);
    
   
    return 0;
}
