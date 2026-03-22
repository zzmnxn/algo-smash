#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M;

    //N개의 정수 입력받기
    cin>>N>>M;
    vector<int> elec;
    for(int i=0;i<N;i++){
        int tmp;
        cin>>tmp;
        elec.push_back(tmp);
    }

    sort(elec.begin(),elec.end(),greater<>());
    //내림차순으로 정렬
    priority_queue<int, vector<int>, greater<int>> consent;
//min-heap 선언 방법

    for(int i=0;i<M;i++){
        //콘센트 M개 준비하고 모두 0분으로 설정하여 큐에 넣는다.
        consent.push(0);
    }

    for(int i=0;i<N;i++){
        // 기기 목록에서 하나씩 다음을 반복
        int tmp= consent.top();
        //큐에서 가장 빨리 끝나는 시간 확인
        tmp+=elec[i];
        consent.pop();
        //가장 빨리 비는 자리 pop
        consent.push(tmp);
        //가장 빨리 비는 자리에 새 기기 꽂아 종료시간 업데이트 push
    }

    int result=0;
    //모든 기기 꽂은 후 큐에는 M개의 콘센트에 각각 최종적으로 끝나는 시각들이 남는다.

    while(!consent.empty()){
        result=consent.top();
        consent.pop();
    }
    //가장 늦게 끝나는 시간이 전체 작업 종료되는 시간
    cout<<result;
    return 0;
   

    
}