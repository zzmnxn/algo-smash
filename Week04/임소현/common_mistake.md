# STL로 인해 자주 발생하는 실수

# 💥 코딩테스트에서 STL 때문에 터지는 실수 TOP 10

> “알고리즘은 맞는데 왜 틀림/시간초과/메모리초과지?”
> 
> 
> → 거의 다 여기서 터짐
> 

---

## 1️⃣ `pop()`이 값을 반환한다고 착각

❌ 잘못된 생각

```cpp
int x = q.pop();// ❌
```

✅ 정답

```cpp
int x = q.front();
q.pop();
```

📌 이유

- `pop()`은 **삭제만**
- stack / queue / priority_queue 전부 동일

👉 **BFS에서 제일 많이 터짐**

---

## 2️⃣ `unordered_map`이 항상 O(1)이라고 믿음

❌ 착각

- 해시 충돌 많으면 **최악 O(N)**

📌 코테에서 문제되는 경우

- 문자열 key 많을 때
- 입력 크기 매우 클 때

✅ 안전한 선택

- 순서 필요 X → `unordered_map`
- 시간 빡빡 + 충돌 의심 → `map`

---

## 3️⃣ `vector` ”중간” 삭제를 아무 생각 없이 사용

❌

```cpp
v.erase(v.begin() + i); // 매번 O(N)
```

📌 결과

- 반복문 안에서 쓰면 **O(N²)**

✅ 대안

- 삭제 대상 표시 → 한 번에 처리
- 순서 상관없으면 swap + pop_back

---

## 4️⃣ `erase` 중 반복자 무효화

❌

```cpp
for (auto it = s.begin(); it != s.end(); it++) {
	if (*it == x)
		s.erase(it); // 💥
}
```

✅

```cpp
it = s.erase(it);
```

📌 이유

- `erase` 후 기존 iterator는 **무효 → 변수에 저장해두기**

👉 set / map에서 특히 자주 터짐

---

## 5️⃣ `unique()`가 중복 제거라고 생각함

❌

```cpp
unique(v.begin(), v.end());
```

📌 실제로는

- 중복을 **뒤로 밀 뿐**
- 크기 안 줄어듦

✅ 올바른 사용

```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end()); // 뒤로 밀린 중복 제거
```

---

## 6️⃣ `priority_queue`가 정렬된 자료구조라고 착각

❌ 착각

- pq 전체가 정렬돼 있을 거라 생각

📌 진실

- **top만 보장**
- 내부 순서 엉망

👉 중간 값 접근 필요 → ❌

👉 계속 최댓값/최솟값만 필요 → ⭕

---

## 7️⃣ `lower_bound`를 정렬 안 하고 사용

❌

```cpp
lower_bound(v.begin(), v.end(), x); // v가 정렬 안 됨
```

📌 결과

- **컴파일 OK, 결과는 쓰레기**

👉 **반드시 `sort()` 후 사용**

---

## 8️⃣ map / set을 너무 쉽게 사용함 (속도 문제)

📌 내부 구조

- Red-Black Tree → `O(log N)`

❌ 실수

- 단순 존재 체크인데 set 사용

✅ 더 빠름

- `unordered_set`

👉 **속도 문제 = 컨테이너 선택 문제**

---

## 9️⃣ 구조적 바인딩 C++17 미지원 환경

❌

```cpp
auto [x, y] = q.front();
```

📌 일부 코테 환경

- C++14 이하 → 컴파일 에러

✅ 안전 버전

```cpp
int x = q.front().first;
int y = q.front().second;
```

👉 BOJ는 괜찮지만 기업 코테는 주의

---

## 🔟 전역 배열 vs 지역 배열 착각

❌

```cpp
int arr[1000][1000]; // 지역
```

📌 결과

- 스택 오버플로우

✅

```cpp
int arr[1000][1000]; // 전역
```

👉 **DP / BFS 2D 배열은 전역이 안전**

---

# 🎯 추가로 진짜 많이 터지는 실수 3개

### 🔥 range-based for + 값 복사

```cpp
for (auto x : v) { } // 복사됨
```

👉 큰 구조체면 느림

✅

```cpp
for (auto& x : v)
```

### `v`

- `vector`, `set`, `map`, `unordered_map`, 배열 등
- **반복 가능한 컨테이너**

### `auto`

- 원소 타입 **자동 추론**

### `&` (참조 ⭐ 중요)

```cpp
auto x// 복사
auto& x// 원본 참조
```

### ✅ 코테에서 거의 항상 `auto&` 쓰는 이유

- **복사 비용 제거**
- **원본 수정 가능**

```cpp
for (auto& x : v) {
    x +=1;// v 자체가 바뀜
}
```

❌ `auto x`면 복사본이라 v 안 바뀜 + 느릴 수 있음

---

### 🔥 map에서 없는 key 접근

```cpp
mp[key]++; // key 없으면 생성됨
```

👉 의도치 않은 메모리 증가

---

### 🔥 `endl` 남발

- 매번 flush → 시간초과 → 정말 즉시 출력이 필요할 때만 사용하기

✅

```cpp
'\n'
```
