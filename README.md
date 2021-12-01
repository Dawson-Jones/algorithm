# 题目详解

[toc]

## 排序

### 快排

#### 模版1

核心思想是

比第一位大的, 移到最后

比第一位小的, pass

```c
void my_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void my_qsort(int *nums, int l, int r) {
    if (l = r)
        return;

    int i = l + 1;
    int j = r;
    for (; i <= j; ++i) {
        if (nums[i] nums[l])
          	// 这里之所以需要i--, 是不知道交换的 j 是不是比 l 大
          	// 所以让 i 停在原地
            my_swap(&nums[i--], &nums[j--]);
    }
    my_swap(&nums[l], &nums[i - 1]);

    my_qsort(nums, l, i - 2);
    my_qsort(nums, i, r);
}

int *sortArray(int *nums, int numsSize) {
    my_qsort(nums, 0, numsSize - 1);
    return nums;
}
```



#### 模版2

![qsort](./img/qsort1.png)

核心思想是

固定第一个

t+1 ~ i 之间都是比固定位大的

l +1 ~ t 之间都是比固定位小的

i 用来遍历所有

注意: 在 t 和 i 没有分开之前, t 和 i 一直在做自身的交换, 不影响

```c
void my_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void my_qsort(int nums[], int l, int r) {
    if (l = r)
        return;
    int i = l + 1;
    int t = l;
    for (; i <= r; ++i) {
        if (nums[i] < nums[l])
            my_swap(&nums[++t], &nums[i]);
    }
    my_swap(&nums[l], &nums[t]);
    my_qsort(nums, l, t - 1);
    my_qsort(nums, t + 1, r);
}
```



### 归并排序

#### 模版

递归向下的过程中二分数组, 直到每个元素都是1个

在递归向上的过程中, 两两合并每个元素, 那么每个数组都是有序的

排序两个有序数组到辅助数组中

然后把辅助数组的元素复制到原数组的对应位置即可

```c
void merge(int *nums, int left, int right) {
    if (left >= right)
        return;

    int st1, ed1, st2, ed2;
    st1 = left;
    ed1 = left + (right - left) / 2;
    st2 = ed1 + 1;
    ed2 = right;
    merge(nums, st1, ed1);
    merge(nums, st2, ed2);

    int temp[right - left + 1];
    int t = 0;
    while (st1 <= ed1 && st2 <= ed2)
        temp[t++] = nums[st1] < nums[st2] ? nums[st1++] : nums[st2++];
    while (st1 <= ed1)
        temp[t++] = nums[st1++];
    while (st2 <= ed2)
        temp[t++] = nums[st2++];

    t = 0;
    for (int i = left; i <= right; ++i)
        nums[i] = temp[t++];
}

void merge_sort(int *nums, size_t len) {
    merge(nums, 0, len - 1);
}
```





### 215 数组中的第K个最大元素

>
> 给定整数数组 `nums` 和整数 `k`，请返回数组中第 `**k**` 个最大的元素。
>
> 请注意，你需要找的是数组排序后的第 `k` 个最大的元素，而不是第 `k` 个不同的元素。
>
>  
>
> **示例 1:**
>
> ```
> 输入: [3,2,1,5,6,4] 和 k = 2
> 输出: 5
> ```
>
> **示例 2:**
>
> ```
> 输入: [3,2,3,1,2,4,5,5,6] 和 k = 4
> 输出: 4
> ```



**思路**:

[快排](#快排)

当左右节点的分割的标准 index 为指定的numSize-k 时

此时的index为所求

当index大的时候, 递归左边

当index小的时候, 递归右边

**代码**

```c
void my_swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int findKthLargest(int* nums, int numsSize, int k){
    int l = 0, r = numsSize-1;

    while (1) {
        int i = l + 1;
        int t = l;
        for (; i <= r; ++i) {
            if (nums[i] < nums[l])
                my_swap(&nums[++t], &nums[i]);
        }
        my_swap(&nums[l], &nums[t]);
        if (t == numsSize - k)
            return nums[t];
        else if (t < numsSize - k)
            l = t + 1;
        else {
            r = t - 1;
        }
    }
    return 0;
}
```

**follow up**



### 剑指 Offer 40. 最小的k个数

> 输入整数数组 `arr` ，找出其中最小的 `k` 个数。例如，输入4、5、1、6、2、7、3、8这8个数字，则最小的4个数字是1、2、3、4。
>

**思路**:

和[215 数组中的第K个最大元素](#215 数组中的第K个最大元素)一样

使用堆的思想也可以实现

**代码**:

```cpp
class Solution {
public:
    vector<intgetLeastNumbers(vector<int& arr, int k) {
        vector <intvec(k, 0);
        if (k == 0)
            return vec;
        priority_queue<intQ;
        for (int i = 0; i < k; ++i) {
            Q.push(arr[i]);
        }

        for (int i = k; i < arr.size(); ++i) {
            if (Q.top() arr[i]) {
                Q.pop();
                Q.push(arr[i]);
            }
        }
        for (int i = 0; i < k; ++i) {
            vec[i] = Q.top();
            Q.pop();
        }
        return vec;
    }
};
```



### 剑指 Offer 21. 调整数组顺序使奇数位于偶数前面

> 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
>
> 示例：
>
> 输入：nums = [1,2,3,4]
> 输出：[1,3,2,4] 
> 注：[3,1,2,4] 也是正确的答案之一。

**思路**:

模版2, 让奇数在前即可

**代码**:

```c
int* exchange(int* nums, int numsSize, int* returnSize){
    int even_st, even_ed, tmp;
    *returnSize = numsSize;
    even_st = even_ed = 0;
    
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] % 2) {
          tmp = nums[even_st];
          nums[even_st] = nums[i];
          nums[i] = tmp;
          even_st++;
        }
        even_ed++;
    }
    
    return nums;
}
```

**follow up**



### 剑指 Offer 45. 把数组排成最小的数

> 输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。
>

**示例 1:**

```
输入: [10,2]
输出: "102"
```

**示例 2:**

```
输入: [3,30,34,5,9]
输出: "3033459"
```

**思路**:



**代码**:

```cpp
class Solution {
public:
    string minNumber(vector<int& nums) {
        string x_str, y_str;
        sort(nums.begin(), nums.end(), [&](int &x, int &y){
            x_str = to_string(x);
            y_str = to_string(y);
            return x_str + y_str < y_str + x_str;
        });
        
        string res;
        for (auto num : nums) {
            res += to_string(num);
        }
        return res;
    }
};
```



### 剑指 Offer 51. 数组中的逆序

> 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

**思路**:

[归并排序](#归并排序)

在归并的过程中因两个要归并的数组都是有序的

如果此刻要归并的元素是数组2的元素

意味着此元素比数组1的任何一个剩余的元素都要小

所以数组1剩下多少个元素, 就意味着, 这一层有多少逆序对

**代码**:

```cpp
class Solution {
public:
    int merge(vector<int> &nums, int left, int right) {
        if (left >= right)
            return 0;

        int st1, ed1, st2, ed2;
        st1 = left;
        ed1 = left + (right - left) / 2;
        st2 = ed1 + 1;
        ed2 = right;
        int count  = merge(nums, st1, ed1) + merge(nums, st2, ed2);

        vector<int> temp(right - left + 1);
        int t = 0;
        while (st1 <= ed1 && st2 <= ed2)
            temp[t++] = nums[st2] < nums[st1] ? ({
                count += ed1 - st1 + 1;
                nums[st2++];
            }) : nums[st1++];
        while (st1 <= ed1)
            temp[t++] = nums[st1++];
        while (st2 <= ed2)
            temp[t++] = nums[st2++];

        t = 0;
        for (int i = left; i <= right; ++i)
            nums[i] = temp[t++];
        
        return count;
    }

    int reversePairs(vector<int> &nums) {
        return merge(nums, 0, nums.size() - 1);
    }
};
```

**follow up**



## 优先队列

### 剑指 offer 41. 数据流中的中位数

> 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
>
> 例如，
>
> [2,3,4] 的中位数是 3
>
> [2,3] 的中位数是 (2 + 3) / 2 = 2.5
>
> 设计一个支持以下两种操作的数据结构：
>
> void addNum(int num) - 从数据流中添加一个整数到数据结构中。
> double findMedian() - 返回目前所有元素的中位数。

**思路**:

建立一个大根堆, 一个小根堆

**代码**:

```cpp
class MedianFinder {
public:
    priority_queue<int, vector<int, less<intque_min;		// 小根堆
    priority_queue<int, vector<int, greater<intque_max;	// 大根堆
    MedianFinder() { }

    void addNum(int num) {
        if (que_min.empty() || num <= que_min.top()) {
            que_min.push(num);
            if (que_max.size() + 1 < que_min.size()) {
                que_max.push(que_min.top());
                que_min.pop();
            }
        } else {
            que_max.push(num);
            if (que_max.size() que_min.size()) {
                que_min.push(que_max.top());
                que_max.pop();
            }
        }
    }

    double findMedian() {
        if (que_min.size() que_max.size())
            return que_min.top();
        else
            return (que_min.top() + que_max.top()) / 2.;
    }
};
```

**follow up**



## 二分查找

### 153. 寻找旋转排序数组中的最小值

> 已知一个长度为 n 的数组，预先按照升序排列，经由 1 到 n 次 旋转 后，得到输入数组。例如，原数组 nums = [0,1,2,4,5,6,7] 在变化后可能得到：
> 若旋转 4 次，则可以得到 [4,5,6,7,0,1,2]
> 若旋转 7 次，则可以得到 [0,1,2,4,5,6,7]
> 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
>
> 给你一个元素值 互不相同 的数组 nums ，它原来是一个升序排列的数组，并按上述情形进行了多次旋转。请你找出并返回数组中的 最小元素 。
>
> 
>
> 示例 1：
>
> 输入：nums = [3,4,5,1,2]
> 输出：1
> 解释：原数组为 [1,2,3,4,5] ，旋转 3 次得到输入数组。
> 示例 2：
>
> 输入：nums = [4,5,6,7,0,1,2]
> 输出：0
> 解释：原数组为 [0,1,2,4,5,6,7] ，旋转 4 次得到输入数组。

**思路**

因为是旋转数组, 二分后

一部分单调递增, 另一部分非单调

最小值在非单调部分

若**旋转之后全部单调**则属于要去前一部分找(最小值在第一个), 见代码注释

**代码**

```c
int findMin(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {	// 兼顾两者, 所以和大的比较
            high = pivot;
        } else {
            low = pivot + 1;
        }
    }
    return nums[low];
}
```

**follow up**

[154. 寻找旋转排序数组中的最小值 II](#154. 寻找旋转排序数组中的最小值 II)



### 154. 寻找旋转排序数组中的最小值 II

> 本题相比[153. 寻找旋转排序数组中的最小值](#153. 寻找旋转排序数组中的最小值)多了可重复元素
>

**思路**:

当中点值和右边相同时

由于它们的值相同，所以无论右边是不是最小值，都有一个它的「替代品」

因此我们可以忽略二分查找区间的右端点。

**代码**: 

```c
int findMin(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {
            high = pivot;
        } else if (nums[pivot] nums[high]) {
            low = pivot + 1;
        } else {	// 相等
            high -= 1;
        }
    }
    return nums[low];
}
```

**follow up**



### 剑指 offer 11. 旋转数组的最小数字

> 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如，数组 [3,4,5,1,2] 为 [1,2,3,4,5] 的一个旋转，该数组的最小值为1。  
>
> 示例 1：
>
> 输入：[3,4,5,1,2]
> 输出：1
> 示例 2：
>
> 输入：[2,2,2,0,1]
> 输出：0

**思路**:

见[154. 寻找旋转排序数组中的最小值 II](#154. 寻找旋转排序数组中的最小值 II)

**代码**:

```
int findMin(int* nums, int numsSize) {
    int low = 0;
    int high = numsSize - 1;
    while (low < high) {
        int pivot = low + (high - low) / 2;
        if (nums[pivot] < nums[high]) {
            high = pivot;
        } else if (nums[pivot] nums[high]) {
            low = pivot + 1;
        } else {	// 相等
            high -= 1;
        }
    }
    return nums[low];
}
```

**follow up**



## 哈希表

### 01. 两数之和

> 两数之和
>

**思路**:

**代码**:

```

```

**follow up**

[15. 三数之和](#15. 三数之和)



### 剑指 Offer 50. 第一个只出现一次的字符

> 在字符串 s 中找出第一个只出现一次的字符。如果没有，返回一个单空格。 s 只包含小写字母。
>
> 示例 1:
>
> 输入：s = "abaccdeff"
> 输出：'b'
> 示例 2:
>
> 输入：s = "" 
> 输出：' '

**思路**:

两次遍历,

第一次把每个字母出现的次数存入 hash 表中

第二次按照字符串遍历, 当出现次数为 1 当时候返回

**代码**:

```c
char firstUniqChar(char* s){
    int len=strlen(s);
    if(len==0)
        return ' ';
    if(len==1)
        return s[0];
    int map[26];
    memset(map, 0, sizeof(map));

    for(int i=0;i<len;i++)
        map[s[i]-'a']++;
    for(int i=0;i<len;i++)
        if(map[s[i]-'a']==1)
            return s[i];
    return ' ';
}
```

**follow up**



## 二叉树

TODO: morris 遍历

### 前序遍历

#### 递归模版

```c
void recur(struct TreeNode *cur, int *res, int *returnSize) {
    if (!cur) 
        return;
    
    res[(*returnSize)++] = cur-val;
    recur(cur-left, res, returnSize);
    recur(cur-right, res, returnSize);
}

int *preorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = (int *) malloc(sizeof(int) * 100);
    *returnSize = 0;
    recur(root, res, returnSize);
    return res;
}
```

#### 迭代模版

```cpp
class Solution {
public:
    vector<intpreorderTraversal(TreeNode* root) {
        vector<intres;
        stack<TreeNode *stk;

        while (root || !stk.empty()) {
            while (root) {
                res.push_back(root-val);
                stk.push(root);
                root = root-left;
            }
            
            root = stk.top(); stk.pop();
            root = root-right;
        }

        return res;
    }
};
```



### 中序遍历

#### 递归模版

```c
void inorder(struct TreeNode* root, int* res, int* resSize) {
    if (!root) {
        return;
    }
    inorder(root-left, res, resSize);
    res[(*resSize)++] = root-val;
    inorder(root-right, res, resSize);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* res = malloc(sizeof(int) * 501);
    *returnSize = 0;
    inorder(root, res, returnSize);
    return res;
}
```

#### 迭代模版

```cpp
class Solution {
public:
    vector<intinorderTraversal(TreeNode* root) {
        vector<intres;
        stack<TreeNode *stk;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root-left;
            }
            
            root = stk.top(); stk.pop();
            res.push_back(root-val);
            root = root-right;
        }

        return res;
    }
};
```

[剑指 Offer 36. 二叉搜索树与双向链表](#剑指 Offer 36. 二叉搜索树与双向链表)



### 后序遍历

#### 递归模版

```c
void postorder(struct TreeNode *root, int *res, int *resSize) {
    if (root == NULL) {
        return;
    }
    postorder(root-left, res, resSize);
    postorder(root-right, res, resSize);
    res[(*resSize)++] = root-val;
}

int *postorderTraversal(struct TreeNode *root, int *returnSize) {
    int *res = malloc(sizeof(int) * 2001);
    *returnSize = 0;
    postorder(root, res, returnSize);
    return res;
}
```



#### 迭代模版

```cpp
class Solution {
public:
    vector<intpostorderTraversal(TreeNode* root) {
        vector<intres;
        stack<TreeNode *stk;
        TreeNode *prev = nullptr;

        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root-left;
            }

            root = stk.top();
            if (root-right && root-right != prev) {
                root = root-right;
                continue;
            }

            stk.pop();
            res.push_back(root-val);
            prev = root;
            root = nullptr;
        }
        return res;
    }
};
```



### 层序遍历

#### 迭代模版

```cpp
class Solution {
public:
    vector<vector<intlevelOrder(TreeNode* root) {
        vector<vector<intres;
        if (!root)
            return res;

        queue<TreeNode *q({root});
        TreeNode *cur_node;
        while (!q.empty()) {
            int cur_level_size = q.size();
            res.push_back(vector<int());
            for (int i = 0; i < cur_level_size; ++i) {
                cur_node = q.front(); q.pop();
                res.back().push_back(cur_node-val);
                if (cur_node-left)
                    q.push(cur_node-left);
                if (cur_node-right)
                    q.push(cur_node-right);
            }
        }
        
        return res;
    }
};
```

[剑指 Offer 32 - I. 从上到下打印二叉树](#剑指 Offer 32 - I. 从上到下打印二叉树)

[剑指 Offer 32 - II. 从上到下打印二叉树 II](#剑指 Offer 32 - II. 从上到下打印二叉树 II)

[剑指 Offer 32 - III. 从上到下打印二叉树 III](#剑指 Offer 32 - III. 从上到下打印二叉树 III)



### 剑指 Offer 32 - I. 从上到下打印二叉树

> 从上到下打印出二叉树的每个节点，同一层的节点按照从左到右的顺序打印。
>
> 
>
> 例如:
> 给定二叉树: [3,9,20,null,null,15,7]
>
>  3
>  / \
> 9  20
>     /  \
>  15   7
>
> 返回：
>
> [3,9,20,15,7]

**思路**:

层序遍历

**代码**:

```cpp
class Solution {
public:
    vector<intlevelOrder(TreeNode* root) {
        vector<intres;
        if (!root)
            return res;
        queue<TreeNode *q({root});
        TreeNode *cur;
        while (!q.empty()) {
            cur = q.front(); q.pop();
            res.push_back(cur-val);
            if (cur-left)
                q.push(cur-left);
            if (cur-right)
                q.push(cur-right);
        }

        return res;
    }
};
```

**follow up**

[剑指 Offer 32 - II. 从上到下打印二叉树 II](#剑指 Offer 32 - II. 从上到下打印二叉树 II)



### 102. 二叉树的层序遍历

### 剑指 Offer 32 - II. 从上到下打印二叉树 II

> 打印出每层的结构
>
> 如:
>
> ```
> [
>   [3],
>  [9,20],
>   [15,7]
> ]
> ```
>



**思路**:

循环中再套一个循环专门在队列中遍历这么多次, 见注释

**代码**:

```cpp
class Solution {
public:
    vector<vector<intlevelOrder(TreeNode* root) {
        vector<vector<intres;
        if (!root)
            return res;

        queue<TreeNode *q({root});
        TreeNode *cur_node;
        while (!q.empty()) {
            int cur_level_size = q.size();
            res.push_back(vector<int());
            for (int i = 0; i < cur_level_size; ++i) {	// 遍历当前层的 size
                cur_node = q.front(); q.pop();
                res.back().push_back(cur_node-val);
                if (cur_node-left)
                    q.push(cur_node-left);
                if (cur_node-right)
                    q.push(cur_node-right);
            }
        }
        
        return res;
    }
};
```

**follow up**

[剑指 Offer 32 - III. 从上到下打印二叉树 III](#剑指 Offer 32 - III. 从上到下打印二叉树 III)



### 剑指 Offer 32 - III. 从上到下打印二叉树 III

> 之字形打印
>
> 如:
>
> ```
> [
>   [3],
>   [20,9],
>   [15,7]
> ]
> ```
>



**思路**:

见代码

**代码**:

```go
func levelOrder(root *TreeNode) [][]int {
    res := [][]int{}
    if root == nil {
        return res
    }
    queue := []*TreeNode{root}
    var Level int = 0
    for len(queue) != 0 {
        //利用临时队列，暂存每个节点的左右子树
        temp := []*TreeNode{}
        //只需考虑在同一层上追加元素
        res = append(res, []int{})
        for _, v := range queue {
            res[Level] = append(res[Level], v.Val)
            if v.Left != nil {
                temp = append(temp, v.Left)
            }
            if v.Right != nil {
                temp = append(temp, v.Right)
            }
        }
        if Level % 2 != 0 {
            Reverse(res[Level])
        }
        //层级加1，队列重新复制为队列的左右子树集
        Level++
        queue = temp
    }
    return res
}


//数组倒序函数
func Reverse(arr []int) {
	length := len(arr)
	for i := 0; i < length/2; i++ {
		arr[i], arr[length-1-i] = arr[length-1-i], arr[i]
	}
}
```

**follow up**



### 剑指 Offer 26. 树的子结构

> 输入两棵二叉树A和B，判断B是不是A的子结构。(约定空树不是任意一个树的子结构)
>
> B是A的子结构， 即 A中有出现和B相同的结构和节点值。
>
> 例如:
> 给定的树 A:
>
>       3
>      / \
>     4   5
>    / \
>  1   2
> 给定的树 B：
>
>    4 
>   /
>  1
> 返回 true，因为 B 与 A 的一个子树拥有相同的结构和节点值。
>
> 示例 1：
>
> 输入：A = [1,2,3], B = [3,1]
> 输出：false
> 示例 2：
>
> 输入：A = [3,4,5,1,2], B = [4,1]
> 输出：true


**思路**:

深度优先搜索

**代码**:

```c
bool same(struct TreeNode *a, struct TreeNode *b) {
    if (b == NULL)		// b 为空可以
        return true;
    if (a == NULL)		// a 为空, b不为空不可以
        return false;

    if (a-val != b-val)
        return false;

    return same(a-left, b-left) && same(a-right, b-right);
}



bool isSubStructure(struct TreeNode* A, struct TreeNode* B){
    if (A == NULL || B == NULL)
        return false;
    if (same(A, B))
        return true;
    
    return isSubStructure(A-left, B) || isSubStructure(A-right, B);
}
```

**follow up**



### 剑指 Offer 27. 二叉树的镜像

### 226. 翻转二叉树

> 请完成一个函数，输入一个二叉树，该函数输出它的镜像。
>
> 例如输入：
>
>    ​      4
>    ​    /   \
>      2     7
>      / \   / \
> 1   3 6   9
>
> 
>
> 镜像输出：
>
>    ​      4
>    ​    /   \
>      7     2
>   / \   / \
> 9   6 3   1

**思路**:

**代码**:

```c
struct TreeNode* mirrorTree(struct TreeNode* root){
    if (!root)
        return NULL;
    
    struct TreeNode *tmp = root-right;	// root-right 及其下面的子节点被存下来了
    root-right = mirrorTree(root-left);	// root-right 改变了
    root-left = mirrorTree(tmp);
    
    return root;
}
```

下面的代码似乎更好理解一点

```c
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode* left = invertTree(root-left);
    struct TreeNode* right = invertTree(root-right);
    root-left = right;
    root-right = left;
    return root;
}
```

**follow up**



### 剑指 Offer 28. 对称的二叉树

> 实现一个函数，用来判断一棵二叉树是不是对称的。如果一棵二叉树和它的镜像一样，那么它是对称的。
>

**思路**:

**代码**:

```c
bool *same(struct TreeNode *a, struct TreeNode *b) {
    if (a == NULL && b == NULL)
        return true;
    if (a == NULL || b == NULL)
        return false;
    if (a-val != b-val)
        return false;
    
    return same(a-left, b-right) && same(a-right, b-left);
}

bool isSymmetric(struct TreeNode* root){
    if (!root)
        return true;

    return same(root-left, root-right);
}
```

**follow up**



### 剑指 Offer 36. 二叉搜索树与双向链表

> 输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的循环双向链表。要求不能创建任何新的节点，只能调整树中节点指针的指向。
>

**思路**:

[中序遍历](#中序遍历)二叉搜索树

然后用双向链表连接即可

**代码**:

```cpp
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root) 
            return nullptr;
        
        dfs(root);
        head-left = pre;
        pre-right = head;
        
        return head;
    }

private:
    Node *pre, *head;

    void dfs(Node *cur) {
        if (!cur) 
            return;
        
        dfs(cur-left);
        if (pre) 
            pre-right = cur;
        else 
            head = cur;
        
        cur-left = pre;
        pre = cur;
        
        dfs(cur-right);
    }
};
```

```cpp
class Solution {
public:
    Node *treeToDoublyList(Node *root) {
        if (!root)
            return nullptr;
        stack<Node *stk;
        vector<Node *arr;
        
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root-left;
            }
            root = stk.top(); stk.pop();
            arr.push_back(root);
            root = root-right;
        }
        
        // 迭代是需要把结果存入数组, 不然遍历会出现问题
        int p, n;
        for (int i = 0; i < arr.size(); ++i) {
            n = (i + 1) % arr.size();
            p = (i + arr.size() - 1) % arr.size();
            arr[i]-left = arr[p];
            arr[i]-right = arr[n];
        }
        return arr[0];
    }
};
```

**follow up**:
### 剑指 Offer 54. 二叉搜索树的第k大节点

> 给定一棵二叉搜索树，请找出其中第k大的节点。
>

**思路**:

[中序遍历](#中序遍历)

因为找第K大的, 所以倒过来中序遍历

**代码**:

```cpp
class Solution {
public:
    int kthLargest(TreeNode* root, int k) {
        return helper(root, k)-val;
    }
    TreeNode *helper(TreeNode *root, int &k) {
        if (!root)
            return nullptr;
        
        TreeNode *tmp;
        tmp = helper(root-right, k);
        if (tmp)
            return tmp;
        
        if (!--k)
            return root;
        
        tmp = helper(root-left, k);
        if (tmp)
            return tmp;
        
        return nullptr;
    }
};
```

**follow up**:



### 剑指 Offer 55 - I. 二叉树的深度

### 104. 二叉树的最大深度

> 输入一棵二叉树的根节点，求该树的深度。从根节点到叶节点依次经过的节点（含根、叶节点）形成树的一条路径，最长路径的长度为树的深度。
>

**思路**:

递归, 从底到顶

**代码**:

```c
int maxDepth(struct TreeNode* root){
    if (!root)
        return 0;
    
    int l = maxDepth(root-left);
    int r = maxDepth(root-right);
    return 1 + (l r ? l : r);
}
```

**follow up**

[剑指 Offer 55 - II. 平衡二叉树](#剑指 Offer 55 - II. 平衡二叉树)

[110. 平衡二叉树](#110. 平衡二叉树)



### 110. 平衡二叉树

### 剑指 Offer 55 - II. 平衡二叉树

> 输入一棵二叉树的根节点，判断该树是不是平衡二叉树。如果某二叉树中任意节点的左右子树的深度相差不超过1，那么它就是一棵平衡二叉树。
>

**思路**:

见[104. 二叉树的最大深度](#104. 二叉树的最大深度)

**代码**:

```c
int max_depth(struct TreeNode *root) {
    if (!root)
        return 0;

    int l = max_depth(root->left);
    int r = max_depth(root->right);
    if (l == -1 || r == -1 || abs(l - r) > 1)
        return -1;

    return (l > r ? l : r) + 1;
}

bool isBalanced(struct TreeNode* root){
   return max_depth(root) >= 0;
}
```

**follow up**



### 剑指 Offer 68 - I. 二叉搜索树的最近公共祖先

### 235. 二叉搜索树的最近公共祖先

> 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。

**思路**:

题为二叉搜索树

当根节点比两个指定节点都要大的时候, 那么公共祖先一定在根节点左面

同理

当根节点比两个指定节点都要小的时候, 那么公共祖先一定在根节点右面



当根节点比一个节点大, 比另一个节点小的时候, 此时根节点即为所求

**代码**:

```c
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    while (root) {
        if (root->val > p->val && root->val > q->val){
            root = root->left;
            continue;
        }
        if (root->val < p->val && root->val < q->val){
            root = root->right;
            continue;
        }
        
        return root;
    }
    return root;
}
```

**follow up**

[236. 二叉树的最近公共祖先](#236. 二叉树的最近公共祖先)



### 236. 二叉树的最近公共祖先

### 剑指 Offer 68 - II. 二叉树的最近公共祖先

> 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

**思路**:



**代码**:

```c
struct TreeNode *lowestCommonAncestor(struct TreeNode *root, struct TreeNode *p, struct TreeNode *q) {
    if (!root || root == p || root == q)
        return root;
    
    struct TreeNode *l = lowestCommonAncestor(root->left, p, q);
    struct TreeNode *r = lowestCommonAncestor(root->right, p, q);
    if (l && r)
        return root;
    
    return l ? l : r;
}
```

**follow up**



## 动态规划

### 剑指 Offer 63. 股票的最大利润

### 121. 买卖股票的最佳时机

> 假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖该股票一次可能获得的最大利润是多少？
>
>  
>
> 示例 1:
>
> 输入: [7,1,5,3,6,4]
> 输出: 5
> 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
>      注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
> 示例 2:
>
> 输入: [7,6,4,3,1]
> 输出: 0
> 解释: 在这种情况下, 没有交易完成, 所以最大利润为 0


**思路**:

当前价格更低时, 更新持有价格

遍历更新最大收益

**代码**:
```c
int maxProfit(int* prices, int pricesSize){
    if (pricesSize == 0)
        return 0;
    int hold = prices[0];
    int cur_max_benefit = 0;
    int cur_benefit;

    for (int i = 1; i < pricesSize; ++i) {
        if ((cur_benefit = prices[i] - hold) 0)
            cur_max_benefit = cur_benefit cur_max_benefit ? cur_benefit : cur_max_benefit;
        else
            hold = prices[i];
    }
    return cur_max_benefit;
}
```

```go
func maxProfit(prices []int) int {
	hold := prices[0];
	profit := 0
	for _, price := range prices {
		if price - hold 0 {
			profit = int(math.Max(float64(price-hold), float64(profit)))
		} else {
			hold = price
		}
	}
	return profit
}
```

**follow up**



### 53. 最大子序和

### 剑指 Offer 42. 连续子数组的最大和

> 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
>
>  
>
> 示例 1：
>
> 输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
> 输出：6
> 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
> 示例 2：
>
> 输入：nums = [1]
> 输出：1

**思路**:

当前的单个值是不是比之前的加当前的值大

如果是, 之前的值只会拖累当前值, 舍弃之前的值

每次遍历都更新最大值

**代码**:

```cpp
class Solution {
public:
    int maxSubArray(vector<int&nums) {
        int res = INT32_MIN;
        int cur_max = 0;
        for (auto &num: nums) {
            cur_max = cur_max + num num ? cur_max + num : num;
            res = res cur_max ? res : cur_max;
        }
        return res;
    }
};
```

```c
int maxSubArray(int* nums, int numsSize){
    if (numsSize == 0)
        return 0;
    
    int cur_max = nums[0];
    int pre_sum = nums[0];
    for (int i = 1; i < numsSize; ++i) {
        pre_sum += nums[i];
        if (nums[i] pre_sum) {
            pre_sum = nums[i];
        }
        cur_max = cur_max pre_sum ? cur_max : pre_sum;
    }
    
    return cur_max;
}
```

**follow up**



### 剑指 Offer 47. 礼物的最大价值

> 在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
>
> 
>
> 输入: 
> [
>   [1,3,1],
>  [1,5,1],
>   [4,2,1]
> ]
> 输出: 12
> 解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

**思路**:

简单dp

**代码**:

```c
int my_max(int a, int b) {
    return a b ? a : b;
}

int maxValue(int **grid, int gridSize, int *gridColSize) {
    if (gridSize == 0)
        return 0;
    for (int i = 1; i < gridSize; ++i)
        grid[i][0] += grid[i-1][0];
 
    for (int i = 1; i < gridColSize[0]; ++i)
        grid[0][i] += grid[0][i-1];

    for (int i = 1; i < gridSize; ++i) {
        for (int j = 1; j < gridColSize[i]; ++j) {
            grid[i][j] = my_max(grid[i][j] + grid[i - 1][j], grid[i][j] + grid[i][j - 1]);
        }
    }
    
    return grid[gridSize-1][gridColSize[0]-1];
}
```

**follow up**



### 剑指 Offer 46. 把数字翻译成字符串

> 给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个数字有多少种不同的翻译方法。
>
>  
>
> 示例 1:
>
> 输入: 12258
> 输出: 5
> 解释: 12258有5种不同的翻译，分别是"bccfi", "bwfi", "bczi", "mcfi"和"mzi"

**思路**:

如果当前的数字加上一个数字在10~25之前

那么当前的数字和前一个组合, 有前面两位和之前所有的组合

加

当前数字自己组合, 有前面一位和之前所有的组合

**代码**:

```python
class Solution:
    def translateNum(self, num: int) -int:
        nums_str = str(num)
        
        pre = int(nums_str[0])
        ppre_sum = 1
        pre_sum = 1
        for num_str in nums_str[1:]:
            cur = int(num_str)
            if 10 <= pre * 10 + cur < 26:
                pre_sum, ppre_sum = ppre_sum + pre_sum, pre_sum
            else:
                ppre_sum = pre_sum
            pre = cur
                
        return pre_sum
```

**follow up**



### 剑指 Offer 48. 最长不含重复字符的子字符串

> 请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
>
>  
>
> 示例 1:
>
> 输入: "abcabcbb"
> 输出: 3 
> 解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
> 示例 2:
>
> 输入: "bbbbb"
> 输出: 1
> 解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

**思路**:

记录所有字符串的index

和出现重复的字符串的时候

重复的index下一位即为开始的index

**代码**:

```c
int lengthOfLongestSubstring(char *s) {
    int st = -1, ed = 0, res = 0;
    char c;
    int map[128];
    memset(map, -1, sizeof(map));
    for (;(c = s[ed]); ++ed) {
        if (map[c] != -1 && map[c] st) {
            st = map[c];
        }
        map[c] = ed;
        res = ed - st res ? ed - st : res;
    }
    return res;
}
```

**follow up**



## 链表

### 剑指 Offer 18. 删除链表的节点

> 给定单向链表的头指针和一个要删除的节点的值，定义一个函数删除该节点。
>
> 返回删除后的链表的头节点。
>
> 注意：此题对比原题有改动
>
> 示例 1:
>
> 输入: head = [4,5,1,9], val = 5
> 输出: [4,1,9]
> 解释: 给定你链表中值为 5 的第二个节点，那么在调用了你的函数之后，该链表应变为 4 -1 -9.
> 示例 2:
>
> 输入: head = [4,5,1,9], val = 1
> 输出: [4,5,9]
> 解释: 给定你链表中值为 1 的第三个节点，那么在调用了你的函数之后，该链表应变为 4 -5 -9.

**思路**:

两个游标

cur 和 pre

当 cur 的值是要删除的值时, 让pre的next指向cur的next即可

**代码**:

```c
struct ListNode* deleteNode(struct ListNode* head, int val){
    struct ListNode node;
    struct ListNode *dummy = &node;
    dummy-next = head;
    struct ListNode *pre = dummy;
    while (head) {
        if (head-val == val) {
            pre-next = head-next;
        }
        pre = head;
        head = head-next;
    }
    return dummy-next;
}
```

**follow up**



### 剑指 Offer 22. 链表中倒数第k个节点

> 输入一个链表，输出该链表中倒数第k个节点。为了符合大多数人的习惯，本题从1开始计数，即链表的尾节点是倒数第1个节点。
>
> 例如，一个链表有 6 个节点，从头节点开始，它们的值依次是 1、2、3、4、5、6。这个链表的倒数第 3 个节点是值为 4 的节点。
>
>  
>
> 示例：
>
> 给定一个链表: 1-2-3-4-5, 和 k = 2.
>
> 返回链表 4-5.
>


**思路**:

快指针走k步, 慢指针开始走

快指针结束, 慢指针指向倒数第k个

**代码**:

```c
struct ListNode* getKthFromEnd(struct ListNode* head, int k){
    struct ListNode *slow;
    struct ListNode *fast = head;
    for (int i = 0; i < k; ++i) {
        fast = fast-next;
    }
    slow = head;
    while (fast) {
        slow = slow-next;
        fast = fast-next;
    }
    return slow;
}
```

**follow up**



### 21. 合并两个有序链表

### 剑指 Offer 25. 合并两个排序的链表

> 输入两个递增排序的链表，合并这两个链表并使新链表中的节点仍然是递增排序的。
>

示例1：

输入：1-2-4, 1-3-4
输出：1-1-2-3-4-4

**思路**:

这不就是归并排序的子问题

**代码**:

```
struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    struct ListNode node;
    struct ListNode *dummy = &node;
    struct ListNode *cursor = dummy;
    while (l1 && l2) {
        if (l1-val < l2-val) {
            cursor-next = l1;
            l1 = l1-next;
        } else {
            cursor-next = l2;
            l2 = l2-next;
        }
        cursor = cursor-next;
    }
    cursor-next = l1 ? l1 : l2;
    return dummy-next;
}
```

**follow up**



### 160. 相交链表

> 给你两个单链表的头节点 `headA` 和 `headB` ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 `null` 。
>

**思路**:

各自遍历

为空时, 指向对方

则此次遍历必相遇

**代码**:

```c
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *fixA = headA;
    struct ListNode *fixB = headB;
    int flag = 0;
    while (headA != headB) {
        headA = headA ? headA-next : ({flag++; fixB;});
        headB = headB ? headB-next : ({flag++; fixA;});
        if (flag 2)
            return NULL;
    }
    return headA;
}
```

**follow up**



## 回溯

### 剑指 Offer 12. 矩阵中的路径

### 79. 单词搜索

> 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
>
> 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
>


**思路**:

一个 visited 辅助矩阵用来记录每个字符是否被访问过

遍历矩阵中的每个字符作为开始点

看当前字符是否是word的第一个字符

如果是, 把当前的坐标 visited 置为True

并递归遍历四周, word的index+1

**代码**:

```cpp
class Solution {
public:
    bool check(vector<vector<char&board, vector<vector<int&visited, int i, int j, string &s, int k) {
        if (board[i][j] != s[k])
            return false;

        // s[k] equals current board[i][j]
        if (k == s.length() - 1)
            return true;
        visited[i][j] = true;
        vector<pair<int, intdirections{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (auto &dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi = 0 && newi < board.size() && newj = 0 && newj < board[0].size()) {
                if (visited[newi][newj])
                    continue;
                if ((result = check(board, visited, newi, newj, s, k+1)))
                    break;
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char&board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<intvisited(h, vector<int(w));
        for (int i = 0; i < h; ++i) {
            for (int j = 0; j < w; ++j) {
                if (check(board, visited, i, j, word, 0))
                    return true;
            }
        }
        return false;
    }
};
```

**follow up**:



### 剑指 Offer 34. 二叉树中和为某一值的路径

### 113. 路径总和 II

> 给你二叉树的根节点 root 和一个整数目标和 targetSum ，找出所有从根节点到叶子节点路径总和等于给定目标和的路径。
>
> 叶子节点 是指没有子节点的节点。
>


**思路**:

dfs加回溯

dfs递归遍历

从根节点到叶子结点

路径中的元素加入一个 array 中

sum(array)

当等于目标值时, 把此array加入到 result 中

当不等或者递归返回时, 把array 当前值再回溯到上一次的状态

**代码**

```c++
class Solution {
public:
    vector<vector<intres;
    vector<vector<intpathSum(TreeNode* root, int target) {
        vector<inttmp;
        if (!root)
            return res;
        
        helper(root, tmp, target);
        return res;
    }
private:
    int sum_of_eles(vector<int&arr) {
        int res = 0;
        for (int x: arr) {
            res += x;
        }
        return res;
    }
    void helper(TreeNode *root, vector<int&cur_arr, int target) {
        cur_arr.push_back(root-val);
        if (!root-left && !root-right) {
            if (sum_of_eles(cur_arr) == target) {
                res.push_back(cur_arr);
            }
            cur_arr.pop_back();
            return;
        }
        if (root-left)
            helper(root-left, cur_arr, target);
        if (root-right)
            helper(root-right, cur_arr, target);
        cur_arr.pop_back();
    }
};
```

**follow up**





### 46. 全排列

> 给定一个不含重复数字的数组 `nums` ，返回其 **所有可能的全排列** 。你可以 **按任意顺序** 返回答案。
>

**思路**:

[剑指 Offer 38. 字符串的排列](#剑指 Offer 38. 字符串的排列)

**代码**:

```
class Solution {
private:
    vector<vector<intres;

    void backtrace(vector<int&nums, int st) {
        if (st == nums.size() - 1)
            res.push_back(nums);

        for (int i = st; i < nums.size(); ++i) {
            swap(nums[st], nums[i]);
            backtrace(nums, st + 1);
            swap(nums[i], nums[st]);
        }
    }
public:
    vector<vector<intpermute(vector<int& nums) {
        backtrace(nums, 0);
        return res;
    }
};
```

**follow up**

[47. 全排列 II](#47. 全排列 II)



### 剑指 Offer 38. 字符串的排列

> 输入一个字符串，打印出该字符串中字符的所有排列。
>
> 你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
>

**思路**:

dfs + 回溯

在 for 循环中递归

for循环为了交换从当前到n-1

递归为了固定当前位

![](./img/permutation.png)

**代码**:

```cpp
class Solution {
private:
    vector<stringres;

    void backtrack(string &s, int x) {
        if (x == s.size() - 1) {
            res.push_back(s);
            return;
        }

        set<int> st;
        for (int i = x; i < s.size(); ++i) {
            if (st.find(s[i]) != st.end())
                continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            backtrack(s, x + 1);
            swap(s[i], s[x]);
        }
    }

public:
    vector<stringpermutation(string s) {
        backtrack(s, 0);
        return res;
    }
};
```

**follow up**



### 47. 全排列 II

> 给定一个可包含重复数字的序列 `nums` ，**按任意顺序** 返回所有不重复的全排列。

**思路**:

1. 见[剑指 Offer 38. 字符串的排列](#剑指 Offer 38. 字符串的排列)
2. [31. 下一个排列](#31. 下一个排列)

**代码**:

```cpp
class Solution {
private:
    vector<vector<int>> res;

    bool nextPermutation(vector<int> &nums) {
        int i, j;

        for (i = nums.size() - 2; i >= 0 && nums[i] >= nums[i + 1]; --i);
        if (i < 0)
            return false;

        for (j = nums.size() - 1; j >= 0 && nums[i] >= nums[j]; --j);

        swap(nums[i], nums[j]);
        reverse(nums.begin() + i + 1, nums.end());
        return true;
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        do
            res.push_back(nums);
        while (nextPermutation(nums));

        return res;
    }
};
```

**follow up**



## bfs

### 剑指 Offer 13. 机器人的运动范围

> 地上有一个m行n列的方格，从坐标 [0,0] 到坐标 [m-1,n-1] 。一个机器人从坐标 [0, 0] 的格子开始移动，它每次可以向左、右、上、下移动一格（不能移动到方格外），也不能进入行坐标和列坐标的数位之和大于k的格子。例如，当k为18时，机器人能够进入方格 [35, 37] ，因为3+5+3+7=18。但它不能进入方格 [35, 38]，因为3+5+3+8=19。请问该机器人能够到达多少个格子？
>
>  
>
> 示例 1：
>
> 输入：m = 2, n = 3, k = 1
> 输出：3
> 示例 2：
>
> 输入：m = 3, n = 1, k = 0
> 输出：1

**思路**:

唯一的要求就是坐标每位之和不能大于K,并可向四周运动

用一个 seen 记录走过的路程

用 bfs 数组来记录能够移动的地方

**代码**:

```swift
class Solution {
    func movingCount(_ m: Int, _ n: Int, _ k: Int) -Int {
        var res = 1;
        var seen: Set<[Int]= [[0,0]]
        var bfs = [[0, 0]]
        while !(bfs.isEmpty) {
            let ele = bfs.remove(at: 0)
            let top = ele[0] - 1
            let btm = ele[0] + 1
            let lft = ele[1] - 1
            let rgt = ele[1] + 1
            if top = 0 && !seen.contains([top, ele[1]]) && (self.everyPlaceSum(top) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([top, ele[1]])
                seen.insert([top, ele[1]])
                res += 1
            }
            if btm < m  && !seen.contains([btm, ele[1]])  && (self.everyPlaceSum(btm) + self.everyPlaceSum(ele[1])) <= k {
                bfs.append([btm, ele[1]])
                seen.insert([btm, ele[1]])
                res += 1
            }
            if lft = 0 && !seen.contains([ele[0], lft])  && (self.everyPlaceSum(lft) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], lft])
                seen.insert([ele[0], lft])
                res += 1
            }
            if rgt < n  && !seen.contains([ele[0], rgt])  && (self.everyPlaceSum(rgt) + self.everyPlaceSum(ele[0])) <= k {
                bfs.append([ele[0], rgt])
                seen.insert([ele[0], rgt])
                res += 1
            }
        }
        return res
    }
    
    func everyPlaceSum(_ x: Int) -Int {
        if x == 0 {
            return 0
        }
        return x % 10 + self.everyPlaceSum(x / 10)
    }
}
```

**follow up**





## dfs

### 剑指 offer 41 数据流中的中位数

> 如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，那么中位数就是所有数值排序之后中间两个数的平均值。
>
> 例如，
>
> [2,3,4] 的中位数是 3
>
> [2,3] 的中位数是 (2 + 3) / 2 = 2.5
>
> 设计一个支持以下两种操作的数据结构：
>
> void addNum(int num) - 从数据流中添加一个整数到数据结构中。
> double findMedian() - 返回目前所有元素的中位数。

**思路**:

建立一个大根堆, 一个小根堆

**代码**:

```

```

**follow up**









## 其他

### 15. 三数之和

> 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
>
> 注意：答案中不可以包含重复的三元组。
>


**思路**:

和[两数之和](#两数之和)思路基本相同

假设 first 是 x, 那么

second + third == target - x *(两数之和)*

**代码**:

```cpp
class Solution {
public:
    vector<vector<intthreeSum(vector<int& nums) {
        int first, second, third, target;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        vector<vector<intans;
        for (first = 0; first < n; ++first) {
            if (first 0 && nums[first] == nums[first - 1])
                continue;
            
            third = n - 1;
            target = -nums[first];
            for (second = first + 1; second < n; ++second) {
                if (second first + 1 && nums[second] == nums[second - 1])
                    continue;

                while (second < third && nums[second] + nums[third] target)
                    --third;
                
                if (second == third)
                    break;
                
                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        
        return ans;
    }
};
```

**follow up**



### 剑指 Offer 61. 扑克牌中的顺子

> 从若干副扑克牌中随机抽 5 张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为 0 ，可以看成任意数字。A 不能视为 14。
>

**思路**:

记录这5张牌的最大值,最小值

0忽略

重复牌直接false

最后最大值最小值相差不超过5即可

**代码**:

```
bool isStraight(int* nums, int numsSize){
    int set[14];
    int m_min = INT32_MAX, m_max = INT32_MIN;
    memset(set, 0, sizeof(set));
    for (int i = 0; i < numsSize; ++i) {
        if (nums[i] == 0)
            continue;
        
        if (set[nums[i]]++)
            return false;
        
        m_min = m_min < nums[i] ? m_min : nums[i];
        m_max = m_max nums[i] ? m_max : nums[i];
    }
    return m_max - m_min < 5;
}
```

**follow up**



### 28. 实现 strStr()

> 实现 strStr() 函数。
>
> 给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串出现的第一个位置（下标从 0 开始）。如果不存在，则返回  -1 。
>


**思路**:

构造状态机: 前缀和后缀相同的部分用来跳表

**代码**:

```c
int *construct_state_machine(char *word, size_t word_len) {
    if (word_len == 0)
        return NULL;
    int *pi = (int *) malloc(sizeof(int) * word_len);
    pi[0] = 0;
    int j = 0;
    for (int i = 1; i < word_len; ++i) {
        while (j 0 && word[i] != word[j]) {
            j = pi[j - 1];
        }
        if (word[i] == word[j]) {
            j++;
        }
        pi[i] = j;
    }

    return pi;
}

int strStr(char *word, char *pattern) {
    int n = strlen(word);
    int m = strlen(pattern);
    int *pi = construct_state_machine(pattern, m);
    if (!pi)
        return 0;
    for (int i = 0, j = 0; i < n; ++i) {
        while (j 0 && word[i] != pattern[j])
            j = pi[j - 1];

        if (word[i] == pattern[j])
            j++;
        if (j == m) {
            free(pi);
            return i - m + 1;
        }
    }
    
    free(pi);
    return -1;
}
```

**follow up**



### 31. 下一个排列

> 实现获取 下一个排列 的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列（即，组合出下一个更大的整数）。
>
> 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
>

**思路**:

从右向左遍历, 直到不是递增, 记录此值

再重新从右向左遍历, 找到比此值大的那一个数

交换

reverse 此数之后的数组(由递增变为递减)

**代码**:

```cpp
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i, j;

        for (i = nums.size()-2; i >= 0 && nums[i] >= nums[i + 1]; --i);
        if (i >= 0) {
            for (j = nums.size() - 1; j >= 0 && nums[i] >= nums[j]; --j);
            
            swap(nums[i], nums[j]);
        }

        reverse(nums.begin() + i + 1, nums.end());
    }
};
```

**follow up**

[46. 全排列](#46. 全排列)



## 分类

### 题目

> 问题

**思路**:



**代码**:

```

```

**follow up**





