#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool help(pair<int,int> a, pair<int,int> b){
    int a_length = a.second -a.first;
    int b_length = b.second - b.first;
    if(a_length!=b_length) return  a_length<b_length;
    return a.first < b.first;
    
}
vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    vector<pair<int,int>> indexes;
    //그러면 맞는 인덱스 리스트를 만들까?
    // vector <pair<int,int>>안에 모든 후보 인덱스들 넣고
    //길이순으로 정렬한 다음에
    // 가장 짧은 것 -> 만약 가장 짧은 게 없다면 같은 길이 중에 제일 처음 시작하는 거?
    int length=sequence.size();
    int left=0, right=0;
    int sum=0;
    while(right < length){
        sum+= sequence[right];
        
        while(sum > k && left < right){
            sum -= sequence[left];
            left++;
        }
        
        if(sum==k){
            indexes.push_back({left, right});
        }
        
        right++;
    }
    
    sort(indexes.begin(), indexes.end(), help);
    answer.push_back(indexes[0].first);
    answer.push_back(indexes[0].second);
    
    
    return answer;
}