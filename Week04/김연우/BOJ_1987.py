R, C = map(int, input().split())
alphabets = [list(input()) for _ in range(R)]

dir=[(-1,0),(1,0),(0,-1),(0,1)]
mask=[0]*26
ans=1

def dfs(r, c, depth):
    global ans
    ans = max(ans, depth) # 갱신

    for i in range(4):
        nr=r+dir[i][0]
        nc=c+dir[i][1]

        if nr<0 or nr>=R or nc<0 or nc>=C: continue # 범위 확인
        
        alphabet=alphabets[nr][nc]
        alphabet=ord(alphabet)-ord('A')
        if mask[alphabet]==1: continue # 알파벳 사용 여부 확인

        mask[alphabet]=1
        dfs(nr, nc, depth+1) # 다음 칸 이동
        mask[alphabet]=0

start=ord(alphabets[0][0])-ord('A')
mask[start]=1
dfs(0, 0, 1)

print(ans)