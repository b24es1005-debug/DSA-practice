STL stands for **Standard Template Library**. It is one of the most important parts of C++, especially for DSA and competitive programming.

Think of it like this:

> **STL = A toolbox of ready-made data structures and algorithms.**

Instead of writing everything from scratch, C++ already provides highly optimized implementations.

---

# STL consists of 4 major components

## 1. Containers (Data Structures)

These store data.

| Container        | Purpose                    | Time Complexity                  |
| ---------------- | -------------------------- | -------------------------------- |
| `vector`         | Dynamic array              | O(1) push_back                   |
| `array`          | Fixed-size array           | O(1) access                      |
| `deque`          | Double-ended queue         | O(1) insert at ends              |
| `list`           | Doubly linked list         | O(1) insert/delete with iterator |
| `forward_list`   | Singly linked list         | O(1) insert after                |
| `stack`          | LIFO                       | O(1)                             |
| `queue`          | FIFO                       | O(1)                             |
| `priority_queue` | Heap                       | O(log n)                         |
| `set`            | Ordered unique elements    | O(log n)                         |
| `multiset`       | Ordered duplicates allowed | O(log n)                         |
| `unordered_set`  | Hash set                   | Average O(1)                     |
| `map`            | Ordered key-value pairs    | O(log n)                         |
| `multimap`       | Ordered duplicate keys     | O(log n)                         |
| `unordered_map`  | Hash map                   | Average O(1)                     |

Example:

```cpp
#include <vector>

using namespace std;

int main() {
    vector<int> v;

    v.push_back(5);
    v.push_back(10);

    cout << v[0];
}
```

---

# 2. Algorithms

C++ already provides hundreds of algorithms.

Instead of writing sorting yourself:

```cpp
sort(v.begin(), v.end());
```

Instead of finding an element:

```cpp
find(v.begin(), v.end(), 25);
```

Instead of reversing:

```cpp
reverse(v.begin(), v.end());
```

Instead of getting the maximum:

```cpp
max_element(v.begin(), v.end());
```

Some very useful algorithms:

```cpp
sort()
reverse()
find()
count()
binary_search()
lower_bound()
upper_bound()
min_element()
max_element()
next_permutation()
prev_permutation()
rotate()
unique()
accumulate()
```

---

# 3. Iterators

Iterators are like pointers that move through containers.

Example:

```cpp
vector<int> v = {1,2,3,4};

for(auto it = v.begin(); it != v.end(); it++)
{
    cout << *it << " ";
}
```

Output:

```
1 2 3 4
```

Common iterators:

```
begin()
end()

rbegin()
rend()

cbegin()
cend()
```

---

# 4. Function Objects (Functors)

These are objects that behave like functions.

Example:

```cpp
sort(v.begin(), v.end(), greater<int>());
```

Output:

```
9 7 5 3 1
```

`greater<int>()` is a functor.

---

# Why is STL important?

Without STL:

```cpp
// Write your own merge sort
// Write your own hash table
// Write your own heap
// Write your own linked list
```

With STL:

```cpp
sort(v.begin(), v.end());

priority_queue<int> pq;

unordered_map<int,int> mp;

set<int> s;
```

Everything is already implemented and optimized.

---

# Example: Solving a DSA problem using STL

Suppose the problem is:

> Find the frequency of every number.

Without STL:

```cpp
// Create your own hash table
// Handle collisions
// Rehashing
// Buckets
```

With STL:

```cpp
unordered_map<int,int> freq;

for(int x : nums)
    freq[x]++;
```

Done in two lines!

---

### Phase 1 (Must Know)

* `vector`
* `pair`
* `array`
* `string`
* `Iterators`
* `sort()`
* `reverse()`
* `find()`
* `min()`, `max()`

---

### Phase 2

* `stack`
* `queue`
* `deque`
* `priority_queue`
* `set`
* `map`

---

### Phase 3

* `unordered_map`
* `unordered_set`
* `multiset`
* `multimap`

---

### Phase 4 (Advanced)

* `Custom comparators`
* `Lambda functions`
* `lower_bound()`
* `upper_bound()`
* `next_permutation()`
* `bitset`
* `tuple`
* `accumulate()`
* `partial_sum()`
* `iota()`

---
