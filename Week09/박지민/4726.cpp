#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n; //장소의 수
    cin>>n;
    vector<int> honey(n);
    vector<int> hap(n);

    for(int i=0;i<n;i++){
        cin>>honey[i];
    }
    hap[0]=honey[0];
    for(int i=1;i<n;i++){
        hap[i]=honey[i]+hap[i-1];
    }

    //여기서 인덱스 a,b 가 꿀
    //인덱스 j 가 꿀통이라고 할 때
    // j-a 누적합 + j-b 누적합 
    //만약 j<b 라면 hap[b]-hap[j] -honey[j]+honey[b]
    // 언제나 a<b라 가정할때
    //a b j
    // a j b
    // j a b 이렇게 세 가지 경우의 수가 있음
    //근데 1번과 3번의 경우의수는 중간에 벌 자리 빼줘야 함
    // 대신 생각을 해보면 3가지 경우의 수 모두 벌들이 최대한 많은 곳을 훑는 것이 이득이니까 양 끝에 배치하는 것이 좋음

    //case 1 a b j
    int res=0;
    for(int b=1;b<n-1;b++){
        //a=0, b=?, j=n-1
        int a= hap[n-1]-honey[0]-honey[b];
        int bee2= hap[n-1]-hap[b];
        res= max(res, a+ bee2);

    }
    
    //case 2 a j b
    for(int j=1;j<n-1;j++){
        //벌 두마리는 양쪽 끝
        //벌꿀통만 중간에 움직이면서 찾아줌
        int a= hap[j]-honey[0];
        //자기 자리 빼고 꿀통까지 합
        int b= hap[n-1]-hap[j-1]-honey[n-1];
        //자기 자리 빼고 꿀통 까지 합
        res=max(res, a+b);
    }

    //case 3 j b a
    for(int b=1;b<n-1;b++){
        //이제는 오른쪽 끝 벌 고정 꿀통 왼쪽 끝 고정

        int a=hap[n-2]-honey[b];
        //자기 자리 빼고 왼쪽 끝까지 먹음
        int bee2=hap[b-1];
        // 자기 자리 바로 직전부터 왼쪽까지 먹음
        res=max(res,bee2+a);
    }
    cout<<res;
    return 0;



}