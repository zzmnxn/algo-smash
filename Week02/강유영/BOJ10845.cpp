#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;


int main(){
    int n;
    cin >> n;
    
    queue<int> que;
    
    for(int i=0; i<n; i++){
        string temp;
        cin >> temp;
        if(temp == "push"){
            int value;
            cin >> value;
            que.push(value);
        }
        else if(temp == "pop"){
            if(que.empty()) cout << -1 << endl;
            else{
                cout << que.front() << endl;
                que.pop();
            }
        }
        else if(temp == "size"){
            cout << que.size() << endl;
        }
        else if(temp == "empty"){
            cout << que.empty() << endl;
        }
        else if(temp == "front"){
            if(que.empty()) cout << -1 << endl;
            else{
                cout << que.front() << endl;
            }
        }
        else if(temp == "back"){
            if(que.empty()) cout << -1 << endl;
            else{
                cout << que.back() << endl;
            }
        }
        else{
            cout << "error" << endl;
            return 0;
        }
    }
    return 0;
}
