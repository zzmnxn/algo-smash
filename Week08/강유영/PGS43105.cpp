#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    // triangle 그대로 재사용(효율성 측면)
    
    // 아래에서 위로 올라가자 (위에서 내려오면 가장자리 비교가 애매해짐)
    // 즉, [현재행 + 1][현재 열] , [현재행 + 1][현재 + 1] 둘 중 하나를 선택해 위로 이동
    
    
    int r_size = triangle.size();
    
    for(int r=r_size-2; r>=0; r--){
        
        int c_size = r+1; // 해당 행의 열 길이
        int c = 0;
        
        while(c < c_size){
            // 아래 행 둘 중에 더 큰 것을 위 방향으로 누적합
            triangle[r][c] += max(triangle[r+1][c], triangle[r+1][c+1]); 
            c++;
        }
    }
    
    // 삼각형의 제일 꼭대기가 최대값
    answer = triangle[0][0];
    
    return answer;
}