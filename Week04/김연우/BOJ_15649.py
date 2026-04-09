N, M = map(int, input().split())

def bitCount(n): # 1의 개수 세기
    count = 0
    while n > 0:
        n &= (n - 1)
        count += 1
    return count

def backtrack(mask, output):
    if bitCount(mask)==M: # end case
        print(output)
        return
    for i in range(1, N+1): # recursive case
        if (mask&(1<<i)) >0: continue
        backtrack(mask | (1<<i), output+str(i)+' ')

backtrack(0, '')