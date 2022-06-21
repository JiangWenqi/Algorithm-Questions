# LEETCODE TEMPLATES

## Sorting

### Quick Sort

```cpp
void quick_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int i = l - 1, j = r + 1, x = q[l + r >> 1];
    while (i < j)
    {
        do i ++ ; while (q[i] < x);
        do j -- ; while (q[j] > x);
        if (i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j), quick_sort(q, j + 1, r);
}
```

```java
private void quickSort(int[] nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int i = l - 1, j = r + 1, x = nums[l + r >> 1];
    while (i < j) {
        do {
            i++;
        } while (nums[i] < x);
        do {
            j--;
        } while (nums[j] > x);
        if (i < j) {
            swap(nums, i, j);
        }
    }
    quickSort(nums, l, j);
    quickSort(nums, j + 1, r);

}

private void swap(int[] nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

// quickSort(nums, 0, nums.length - 1);
```

### Merge Sort

```cpp
void merge_sort(int q[], int l, int r)
{
    if (l >= r) return;

    int mid = l + r >> 1;
    merge_sort(q, l, mid);
    merge_sort(q, mid + 1, r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (q[i] <= q[j]) tmp[k ++ ] = q[i ++ ];
        else tmp[k ++ ] = q[j ++ ];

    while (i <= mid) tmp[k ++ ] = q[i ++ ];
    while (j <= r) tmp[k ++ ] = q[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) q[i] = tmp[j];
}
```

```java
private int[] temp = new int[5_0000];
private void mergeSort(int[] nums, int l, int r) {
    if (l >= r) {
        return;
    }
    int mid = l + r >> 1;
    mergeSort(nums, l, mid);
    mergeSort(nums, mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (nums[i] < nums[j]) {
            temp[k++] = nums[i++];
        } else {
            temp[k++] = nums[j++];
        }
    }
    while (i <= mid) {
        temp[k++] = nums[i++];
    }
    while (j <= r) {
        temp[k++] = nums[j++];
    }
    for (i = l, j = 0; i <= r; i++, j++) {
        nums[i] = temp[j];
    }
}
```

## Binary Search

```cpp
bool check(int x) {/* ... */} // 检查x是否满足某种性质

// 区间[l, r]被划分成[l, mid]和[mid + 1, r]时使用：
// find the first number bigger than target
int bsearch_1(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;    // check()判断mid是否满足性质
        else l = mid + 1;
    }
    return l;
}
// 区间[l, r]被划分成[l, mid - 1]和[mid, r]时使用：
// find the last number smaller than target
int bsearch_2(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    return l;
}
```

## Backtracking

```cpp
class Solution {
 private:
  vector<int> path;
  vector<bool> visited;
  vector<vector<int>> res;
  void dfs(int idx, vector<int> &nums) {
    if (idx == nums.size()) {
      res.push_back(path);
      return;
    }

    for (int i = 0; i < nums.size(); i++) {
      if (!visited[i]) {
        path[idx] = nums[i];
        visited[i] = true;
        dfs(idx + 1, nums);
        visited[i] = false;
      }
    }
  }

 public:
  vector<vector<int>> permute(vector<int> &nums) {
    int n = nums.size();
    path.resize(n);
    visited.resize(n);
    dfs(0, nums);
    return res;
  }
};
```

## Union Find
### General
```cpp
int p[N]; //存储每个点的祖宗节点

// 返回x的祖宗节点
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i ++ ) p[i] = i;

// 合并a和b所在的两个集合：
p[find(a)] = find(b);

```

### Size
```cpp
int p[N], size[N];
//p[]存储每个点的祖宗节点, size[]只有祖宗节点的有意义，表示祖宗节点所在集合中的点的数量

// 返回x的祖宗节点
int find(int x)
{
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i ++ )
{
    p[i] = i;
    size[i] = 1;
}

// 合并a和b所在的两个集合：
size[find(b)] += size[find(a)];
p[find(a)] = find(b);
```

### Distance
```cpp
int p[N], d[N];
//p[]存储每个点的祖宗节点, d[x]存储x到p[x]的距离

// 返回x的祖宗节点
int find(int x)
{
    if (p[x] != x)
    {
        int u = find(p[x]);
        d[x] += d[p[x]];
        p[x] = u;
    }
    return p[x];
}

// 初始化，假定节点编号是1~n
for (int i = 1; i <= n; i ++ )
{
    p[i] = i;
    d[i] = 0;
}

// 合并a和b所在的两个集合：
p[find(a)] = find(b);
d[find(a)] = distance; // 根据具体问题，初始化find(a)的偏移量

```

## KMP
```cpp
int strStr(string text, string pattern) {
int m = text.size(), n = pattern.size();
text = ' ' + text, pattern = ' ' + pattern;
vector<int> next(n + 1);
for (int i = 2, j = 0; i <= n; i++) {
    while (j && pattern[j + 1] != pattern[i]) j = next[j];
    if (pattern[i] == pattern[j + 1]) j++;
    next[i] = j;
}
for (int i = 1, j = 0; i <= m; i++) {
    while (j && text[i] != pattern[j + 1]) j = next[j];
    if (text[i] == pattern[j + 1]) j++;
    if (j == n) return i - n;
}
return -1;
}

```