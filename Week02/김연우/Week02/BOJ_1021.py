from collections import deque

result = 0
N, M = list(map(int, input().split()))
indexes = list(map(int, input().split()))

indexes = deque(indexes)
curr_size = N

while(len(indexes) > 0):
    x = indexes.popleft()
    left_space = x-1
    right_space = (curr_size+1)-x
 
    if left_space < right_space:
        result = result + left_space

        temp = list(indexes)
        for i in range(len(temp)):
            x = temp[i] - left_space - 1
            temp[i] = x % curr_size
        indexes=deque(temp)
    else:
        result = result + right_space

        temp = list(indexes)
        for i in range(len(temp)):
            x = temp[i] + right_space - 1
            temp[i] = x % curr_size
        indexes=deque(temp)
    
    curr_size -= 1

print(result)