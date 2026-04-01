def solution(sequence, k):
    answer = []

    n = len(sequence)
    left = 0
    right = 0
    curr_sum = sequence[0]
    
    candidates = []

    while(left < n and right < n):
        if(curr_sum < k):
            if(right == n-1): break
            right+=1
            curr_sum+=sequence[right]
        else:            
            if(curr_sum == k):
                candidates.append((left, right, right-left))
            curr_sum-=sequence[left]
            left+=1
        if(left == right):
            if(curr_sum > k): break

    candidates.sort(key=lambda x:(x[2],x[0]))
    x = candidates[0]
    
    # print(candidates)
    
    answer.append(x[0])
    answer.append(x[1])
    
    # print(answer)

    return answer

# sq=list(map(int, input().split()))
# K=int(input())
# solution(sq,K)