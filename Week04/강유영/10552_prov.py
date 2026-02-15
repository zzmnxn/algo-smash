import sys

def dfs(start):
    visited[start] = True
    stack = [start]
    count = 0

    while stack :
        curr = stack.pop()
        if not graph[curr] :# dfs 변형
            return count
        
        temp = graph[curr][0]

        if not visited[temp]:
            visited[temp] = True
            stack.append(temp)
            count += 1
    return -1



N, M, P = map(int, sys.stdin.readline().split())

visited = [False] * (M + 1)
graph = [ [] for _ in range(M+1)]

for i in range(N):
    favor, hate = map(int, sys.stdin.readline().split())
    if not graph[hate]:
        graph[hate].append(favor) #i채널을 선호하는 어르신

result = dfs(P)

print(result)