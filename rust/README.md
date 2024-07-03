[toc]



## 二叉树

### [236. 二叉树的最近公共祖先](https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/)

> 给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

**思路**:



**代码**:

```rust
use std::cell::RefCell;
use std::rc::Rc;


impl Solution {
    pub fn lowest_common_ancestor(
        root: Option<Rc<RefCell<TreeNode>>>,
        p: Option<Rc<RefCell<TreeNode>>>,
        q: Option<Rc<RefCell<TreeNode>>>,
    ) -> Option<Rc<RefCell<TreeNode>>> {
        if root.is_none() {
            return None;
        }
        if root == p || root == q {
            return root;
        }

        let left = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().left.clone(),
            p.clone(),
            q.clone(),
        );
        let right = Self::lowest_common_ancestor(
            root.as_ref().unwrap().borrow().right.clone(),
            p.clone(),
            q.clone(),
        );

        if left.is_some() && right.is_some() {
            return root;
        }
        if left.is_some() {
            return left;
        } else {
            return right;
        }
    }
}
```

**时间复杂度**: 

**空间复杂度**: 

**follow up**



### [109. 有序链表转换二叉搜索树](https://leetcode.cn/problems/convert-sorted-list-to-binary-search-tree/)

> 给定一个单链表的头节点  head ，其中的元素 按升序排序 ，将其转换为高度平衡的二叉搜索树。
>
> 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差不超过 1。

**思路**:



**代码**:

```rust
impl Solution {
    pub fn sorted_list_to_bst(head: Option<Box<ListNode>>) -> Option<Rc<RefCell<TreeNode>>> {
        let mut v = Vec::new();
        let mut node = &head;
        while let Some(n) = node {
            v.push(n.val);
            node = &n.next
        }

        Self::build_binary_tree(&v)
    }

    fn build_binary_tree(v: &[i32]) -> Option<Rc<RefCell<TreeNode>>> {
        if v.len() == 0 {
            return None;
        }

        let mid = v.len() / 2;
        let mut root = TreeNode::new(v[mid] as i32);
        root.left = Self::build_binary_tree(&v[..mid]);
        root.right = Self::build_binary_tree(&v[mid+1..]);

        Some(Rc::new(RefCell::new(root)))
    }
}
```

**时间复杂度**: 

**空间复杂度**: 

**follow up**



## 排序

### [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

> 给你两个按 **非递减顺序** 排列的整数数组 `nums1` 和 `nums2`，另有两个整数 `m` 和 `n` ，分别表示 `nums1` 和 `nums2` 中的元素数目。
>
> 请你 **合并** `nums2` 到 `nums1` 中，使合并后的数组同样按 **非递减顺序** 排列。

**思路**:

简单归并排序

**代码**:

```rust
impl Solution {
    pub fn merge(nums1: &mut Vec<i32>, m: i32, nums2: &mut Vec<i32>, n: i32) {
        let m = m as usize;
        let n = n as usize;
        let nums3 = nums1[0..m].to_vec();

        let mut i = 0;
        let mut j = 0;
        let mut k = 0;
        while i < m && j < n {
            if nums3[i] < nums2[j] {
                nums1[k] = nums3[i];
                i += 1;
            } else {
                nums1[k] = nums2[j];
                j += 1;
            }

            k += 1;
        }
        while i < m {
            nums1[k] = nums3[i];
            i += 1;
            k += 1;
        }
        while j < n {
            nums1[k] = nums2[j];
            j += 1;
            k += 1;
        }
    }
}
```

**时间复杂度**: 

**空间复杂度**: 

**follow up**



### [27. 移除元素](https://leetcode.cn/problems/remove-element/)

> 给你一个数组 `nums` 和一个值 `val`，你需要 **[原地](https://baike.baidu.com/item/原地算法)** 移除所有数值等于 `val` 的元素。元素的顺序可能发生改变。然后返回 `nums` 中与 `val` 不同的元素的数量。

**思路**:

快排思想

**代码**:

```rust
impl Solution {
    pub fn remove_element(nums: &mut Vec<i32>, val: i32) -> i32 {
        let mut i = 0;
        for j in 0..nums.len() {
            if nums[j] != val {
                nums[i] = nums[j];
                i += 1;
            }
        }
        i as i32
    }
}
```

**时间复杂度**: 

**空间复杂度**: 

**follow up**





## 动态规划

### [139. 单词拆分](https://leetcode.com/problems/word-break/)

> 给你一个字符串 `s` 和一个字符串列表 `wordDict` 作为字典。请你判断是否可以利用字典中出现的单词拼接出 `s` 。

**思路**:



**代码**:

超时

```rust
impl Solution {
    fn help_word_break(s: &str, word_dict: &Vec<String>) -> bool {
        for word in word_dict {
            if s.is_empty() {
                return true;
            }

            if s.starts_with(word) && Solution::help_word_break(&s[word.len()..], word_dict) {
                return true;
            }
        }

        return false;
    }

    pub fn word_break(s: String, word_dict: Vec<String>) -> bool {
        Solution::help_word_break(&s[..], &word_dict)
    }
}
```



**时间复杂度**: O(n<sup>2</sup>)

**空间复杂度**: O(n)

**follow up**
