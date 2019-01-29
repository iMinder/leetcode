#  

# [Split Linked List in Parts][title]

## Description

Given a (singly) linked list with head node `root`, write a function to split the linked list into `k` consecutive linked list "parts".

The length of each part should be as equal as possible: no two parts should have a size differing by more than 1. This may lead to some parts being null.

The parts should be in order of occurrence in the input list, and parts occurring earlier should always have a size greater than or equal parts occurring later.

Return a List of ListNode's representing the linked list parts that are formed.

Examples 1->2->3->4, k = 5 // 5 equal parts [ [1], [2], [3], [4], null ]

**Example 1:**

```
Input: 
root = [1, 2, 3], k = 5
Output: [[1],[2],[3],[],[]]
Explanation:
The input and each element of the output are ListNodes, not arrays.
For example, the input root has root.val = 1, root.next.val = 2, \root.next.next.val = 3, and root.next.next.next = null.
The first element output[0] has output[0].val = 1, output[0].next = null.
The last element output[4] is null, but it's string representation as a ListNode is [].
```



**Example 2:**

```
Input: 
root = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10], k = 3
Output: [[1, 2, 3, 4], [5, 6, 7], [8, 9, 10]]
Explanation:
The input has been split into consecutive parts with size difference at most 1, and earlier parts are a larger size than the later parts.
```



**Note:**

The length of `root` will be in the range `[0, 1000]`.

Each value of a node in the input will be an integer in the range `[0, 999]`.

`k` will be an integer in the range `[1, 50]`.

**Tags:** linked list

## 思路 

首先是获取链表长度，从题目可知，无非是针对长度 n对k取余数和除数的问题，有余数时，在划分时，优先前面的分组个数多一个，后面的数组和余数一致。

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    public:
        vector < ListNode * > splitListToParts(ListNode * root, int k) {
            ListNode * currentNode = root;
            std::vector < ListNode * > nodes;
            if (1 == k) {
                nodes.push_back(root);
                return nodes;
            }
            int length = 0;
            while (currentNode) {
                length++;
                currentNode = currentNode - > next;
            }
            int subLength = length / k;
            int left = length > k ? length % k : 0;
            subLength = max(subLength, 1);
            currentNode = root;
            while (k) {
                int count = 0;
                ListNode * tmp = currentNode;
                while (count < subLength - 1) {
                    if (tmp) {
                        tmp = tmp - > next;
                    }
                    count++;
                }
                if (left > 0) {
                    if (tmp) {
                        tmp = tmp - > next;
                    }
                    left--;
                }
                if (currentNode) {
                    nodes.push_back(currentNode);
                } else {
                    nodes.push_back(NULL);
                }
                if (tmp) {
                    currentNode = tmp - > next;
                    tmp - > next = NULL;
                } else {
                    currentNode = NULL;
                }
                k--;
            }
            return nodes;
        }
};
```



## 结语

链表的结题思路大致就是这些了，求长度，划分等。
