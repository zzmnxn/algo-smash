#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n, t;
    vector<string> number;
    string temp;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> t;
        number.clear(); // 초기화 반드시 !
        bool result = false;
        
        for(int i=0; i<t; i++){
            cin >> temp;
            number.push_back(temp);
        }
        // 사전순 정렬
        sort(number.begin(), number.end());
        
        // 사전순 정렬을 했기에 일관성이 없는 전화번호들은 붙어있다. (바로 옆에 있는 것만 비교하면 됨)
        for(int i=0; i<t-1; i++){
            int size = int(number[i].size());
            if(number[i].substr(0, size) == number[i+1].substr(0, size)){
                result = true;
            }
        }
        if(result){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
        
    }
    
    return 0;
}
