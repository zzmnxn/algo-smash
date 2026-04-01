#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int start = 0, end = 0;
    int min_size = 1e9;
    int now_sum = sequence[0];

    while(start <= end && end < sequence.size()){
        
        if(now_sum < k){
            end++;
            now_sum += sequence[end];
        }
        else if(now_sum > k){
            now_sum -= sequence[start];
            start++;
        }
        else{
            if((end-start) < min_size){
                min_size = end-start;
                answer = {start, end};
            }
            now_sum -= sequence[start];
            start++;
        }
        /*
        if(start > end && start < sequence.size()){ // start가 end를 추월하게 되는 경우
            end = start;
            now_sum = sequence[start];
        } */
        
      
    }
    
    return answer;
}