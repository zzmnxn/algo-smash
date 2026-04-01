#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, c=0;
    if(!(cin>>n))return -1;
    vector<int> a(n);
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());
    
    // 합이 a[i]인 것을 찾자
    for(int i=0; i<n; i++){
        
        bool flag = false;
        int start = 0, end = n-1; // 투포인터
        while(start < end){
            if(start == i){
                start++;
                continue;
            }
            if(end == i){
                end--;
                continue;
            }
            
            
            if( (a[start] + a[end]) < a[i] ) start++;
            else if ( (a[start] + a[end]) > a[i] ) end--;
            else{
                flag = true;
                break;
            }
        }
        
        if(flag) c++;
    }

    cout << c << endl;
    
    return 0;
}
