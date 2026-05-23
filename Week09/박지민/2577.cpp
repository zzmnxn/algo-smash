#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; //접시의 수
    int d; //초밥의 가짓수
    int k; //연속해서 먹는 접시의 수
    int c;// 쿠폰 번호
    cin>>n>>d>>k>>c;
    vector<int> plates(n+k);
    for(int i=0;i<n;i++){
        cin>>plates[i];
    }
    //기본으로는 k 개를 먹을 수 있음
    //근데 쿠폰에 있는 c 가 사이에 k 개의 접시가 있으면 +1 할 수 있음
    //알고보니 초밥 갯수가 아니라 가짓수였음 -> 일일이 그 윈도우 안에 몇가지인지 세야 함
    // 자료구조를 활용하면 되지 않을까?
    //저번에도 비슷한 문제가 있었던 거 같은데 set 을 활용해서 매번 삽입하고 삭제하면 시간 복잡도가 너무 오래 걸림
    // 배열 하나 선언 해서 1,0으로만 표시자하!

    for(int i=0;i<k;i++){
        plates[n+i]=plates[i];
    } //원형임을 처리하기 위해서 그냥 뒤에 k 개 더 붙임

    vector<int> check(d+1,0);
    //초밥의 가짓수 빈도 체크 배열 
    //1- based index

    int unique_cnt= 0;//현재 윈도우 안 초밥 종류
    int max_sushi=0; //최대 초밥 종류 수

    for(int i=0;i<k;i++){
        //첫번째 윈도우 먹기
        int sushi = plates[i];
        if(check[sushi]==0){
            unique_cnt++;
        }
        check[sushi]++;
    }
    
    if(check[c]==0){
        //처음 다 먹고 쿠폰 안 썼으면
        max_sushi= unique_cnt+1;
    }else{
        max_sushi=unique_cnt;
    }

    //슬라이딩 윈도우 시작
    for(int i=0;i<n-1;i++){
        //0번~k-1번까지는 이미 계산
        // 다음 윈도우 : 1번 ~k번 -> 0번 빼고 k 번 넣기
        //마지막 윈도운 n-2번 빼기 -> n-1~ n-1+k-1
        //왼쪽 시작을 기준으로 0부터 n-1까지
        //맨 왼쪽꺼 제외
        int out= plates[i];
        check[out]--;
        if(check[out]==0){
            unique_cnt--;
        }

        //새로 초밥 하나 추가
        int ins=plates[i+k];
        if(check[ins]==0){
            unique_cnt++;
        }
        check[ins]++;
        //현재 상황 쿠폰 쓸말 결정
        int cur= unique_cnt;
        if(check[c]==0){
            cur++;
        }

        max_sushi=max(max_sushi,cur);
    }

    cout<<max_sushi;

    return 0;


}