#include <iostream>
#include <vector>
#include <cmath>

using namespace std; 

int main(){

    int n;
    cin>>n;
    vector<long long> arr(n);
    
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //두개의 포인터를 이동하면서 찾는 거는 알겠음
    //근데 만약에 끝과 끝이 정답이라면? 중간 두개가 정답이라면?
    //0이랑 가깝다는 것은 결국 절댓값 비교
    int left=0;
    int right=n-1;
    int max_left=left;
    int max_right=right;
    //최대였던 인덱스를 보관
    //인덱스를 움직이는 기준이 제일 중요
    //투 포인터는 "현재 조합이 정답이든 아니든, 확인이 끝났다면 다음으로 0에 가까울 가능성이 있는 조합을 향해 전진하는 알고리즘"
    while(left<right){
        int tmp = arr[left]+arr[right];
        if(abs(tmp)<abs(arr[max_left]+arr[max_right])){
            max_left=left;
            max_right=right;

        }

        if(tmp>0){
            right--;
        }
        else if(tmp <0){
            left++;
        }
        else if(tmp ==0){
            max_left=left;
            max_right=right;
            break;
        }
    }

    cout<<arr[max_left]<<" "<<arr[max_right];

    return 0;


}
