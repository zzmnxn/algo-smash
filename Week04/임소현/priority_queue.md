# priority_queue

## 1️⃣ priority_queue가 뭐냐?

> “항상 가장 중요한 값이 먼저 나오는 큐”
> 
- 내부적으로 **힙(heap)** 구조
- 기본은 **최대 힙**

```cpp
priority_queue<int> pq;
```

```
push → 가장 큰 값이 top()
```

---

## 2️⃣ 기본 사용법

```cpp
priority_queue<int> pq;

pq.push(3);
pq.push(10);
pq.push(1);

cout << pq.top(); // 10
pq.pop(); // 10 제거
```

⏱ 시간복잡도

- push: `O(log N)`
- pop: `O(log N)`
- top: `O(1)`

---

## 3️⃣ 최소 힙 만들기 (중요 ⭐⭐⭐)

### 방법 1️⃣ `greater<>` (가장 많이 씀)

```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```

```
top() → 가장 작은 값
```

📌 **<functional> 포함 필요**

---

### 방법 2️⃣ 음수로 넣기 (옛날 방식)

```cpp
pq.push(-x);
```

❌ 가독성 안 좋아서 요즘은 거의 안 씀

---

## 4️⃣ pair 넣기 (코테 최빈도)

```cpp
priority_queue<pair<int,int>> pq;
```

### 정렬 기준

1️⃣ first 기준

2️⃣ first 같으면 second 기준

```cpp
pq.push({5,2});
pq.push({5,1});
pq.push({3,10});

top() → {5,2}
```

---

### 최소 힙 pair

```cpp
priority_queue<pair<int,int>,
               vector<pair<int,int>>,
               greater<pair<int,int>>> pq;
```

👉 **다익스트라 필수**

---

## 5️⃣ 직접 정렬 기준 만들기 (고급)

### struct comparator

```cpp
structcmp {
booloperator()(int a,int b) {
return a > b;// 작은 값이 우선
  }
};

priority_queue<int, vector<int>, cmp> pq;
```

📌 **return true면 a가 뒤로 감**

---

## 6️⃣ 언제 쓰냐? (이거 떠올리면 바로 priority_queue)

### ✅ 바로 떠올려야 하는 문제들

| 상황 | 이유 |
| --- | --- |
| 가장 큰 / 작은 값 계속 뽑기 | 힙 |
| 매번 정렬하면 느림 | pq가 log |
| 다익스트라 | 최단 거리 |
| 작업 우선순위 | 시뮬 |
| k번째 큰 수 | 힙 유지 |

---

## 7️⃣ BFS랑 섞일 때 (중요)

### BFS

```
큐 → 순서 보장
```

### priority_queue

```
“가장 좋은 상태부터 처리”
```

👉 **BFS + pq = 다익스트라 / A***

---

## 8️⃣ 코테에서 자주 터지는 실수 ❌

### ❌ pop 전에 empty 체크 안 함

```cpp
pq.top();// 터짐
```

### ❌ comparator 방향 헷갈림

```cpp
return a < b;// 이게 최대힙임
```

### ❌ pair 정렬 기준 모르고 씀

```cpp
{dist, node} vs {node, dist}
```

---

## 9️⃣ 한 줄 요약 🧠

> priority_queue = “정렬된 큐가 아니라, top만 보장되는 힙”
>
