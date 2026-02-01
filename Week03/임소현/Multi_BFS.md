# 동시에 BFS 여러 개를 실행하는 방법

C++에서 **동시에 BFS 여러 개를 실행한다**는 말은 보통 두 가지 의미로 쓰입니다.

1️⃣ **멀티 소스 BFS (Multi-source BFS)**

2️⃣ **여러 BFS를 병렬적으로 관리하는 경우 (독립 BFS 여러 개)**

대부분의 알고리즘 문제에서는 **1️⃣ 멀티 소스 BFS**를 의미하는 경우가 **압도적으로 많습니다**.

---

## 1️⃣ 멀티 소스 BFS (가장 중요 ⭐)

### 개념

여러 개의 시작점에서 **동시에 BFS를 시작**하는 방식입니다.

큐에 **여러 시작 노드를 한 번에 넣고 BFS를 돌리는 것**이 핵심입니다.

👉 실제로는 BFS를 **한 번만 실행**하지만

👉 여러 BFS가 동시에 퍼져 나가는 것처럼 동작합니다.

---

### 언제 쓰나?

- 여러 개의 출발점에서 **최단 거리**
- 전염, 불, 물 퍼짐 문제
- 여러 적/플레이어의 영향 범위 계산
- `0`이 여러 개인 행렬에서 거리 계산

---

### 핵심 아이디어

1. 큐에 **모든 시작점**을 먼저 넣는다
2. 방문 처리도 동시에 한다
3. BFS는 한 번만 실행

---

### 예제 코드 (C++)

```cpp
#include<bits/stdc++.h>
using namespace std;

int n, m;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int dist[100][100];
int board[100][100];

int main() {
    cin >> n >> m;
    queue<pair<int,int>> q;

		for (int i =0; i < n; i++) {
				for (int j =0; j < m; j++) {
            cin >> board[i][j];
            dist[i][j] =-1;

						// 여러 시작점
						if (board[i][j] == 1) {
                q.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

		while (!q.empty()) {
				auto [x, y] = q.front(); q.pop();

				for (int d =0; d <4; d++) {
						int nx = x + dx[d];
						int ny = y + dy[d];

						if (nx <0 || ny <0 || nx >= n || ny >= m) continue;
						if (dist[nx][ny] !=-1) continue;

            dist[nx][ny] = dist[x][y] +1;
            q.push({nx, ny});
        }
    }

// 결과 출력
for (int i =0; i < n; i++) {
for (int j =0; j < m; j++) {
            cout << dist[i][j] <<" ";
        }
        cout <<"\n";
    }
}

```

📌 **중요 포인트**

- `queue`에 시작점을 **여러 개** 넣는 것만 다름
- BFS 로직은 일반 BFS와 동일
- 시간 복잡도는 `O(NM)` 그대로

---

## 2️⃣ BFS를 여러 번 독립적으로 실행하는 경우

### 개념

- 시작점마다 BFS를 **완전히 따로 실행**
- 서로 결과가 영향을 주지 않음

### 예시

```cpp
for (auto start : starts) {
  bfs(start);
}
```

❌ 단점:

- 매우 느림 (O(K × BFS))
- 대부분의 문제에서 비효율적

👉 **멀티 소스 BFS로 바꿀 수 있는지 먼저 고민해야 합니다.**

---

## 3️⃣ 진짜 “병렬 BFS” (스레드)

- `std::thread`, OpenMP 사용
- 알고리즘 문제에서는 거의 안 씀
- 경쟁 프로그래밍에서는 ❌

---

## 정리 ✨

| 방식 | 의미 | 사용 빈도 |
| --- | --- | --- |
| 멀티 소스 BFS | 여러 시작점을 동시에 BFS | ⭐⭐⭐⭐⭐ |
| 독립 BFS 여러 개 | BFS 반복 실행 | ⭐⭐ |
| 병렬 BFS | 스레드 기반 | ⭐ |
