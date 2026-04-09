N = int(input())
S = [list(map(int, input().split())) for _ in range(N)]

selected = [False] * N
selected[0] = True # 항상 스타트 팀. 중복 방지
ans = float('inf')

def calc_diff():
    start_team = []
    link_team = []

    for i in range(N):
        if selected[i]:
            start_team.append(i)
        else:
            link_team.append(i)

    start_sum = 0
    link_sum = 0

    for i in range(N//2):
        for j in range(i+1, N//2):
            a = start_team[i]
            b = start_team[j]
            start_sum += S[a][b] + S[b][a]

            c = link_team[i]
            d = link_team[j]
            link_sum += S[c][d] + S[d][c]

    return abs(start_sum - link_sum)

def dfs(idx, cnt):
    global ans

    if cnt == N // 2: # end case
        ans = min(ans, calc_diff())
        return

    for i in range(idx, N): # recursive case
        if not selected[i]:
            selected[i] = True
            dfs(i + 1, cnt + 1)
            selected[i] = False

dfs(1, 1)
print(ans)