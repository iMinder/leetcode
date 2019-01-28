#  

# [ Rotate List][title]

## Description

Given a linked list, rotate the list to the right by *k* places, where *k* is non-negative.

**Example 1:**

```
Input: 1->2->3->4->5->NULL, k = 2
Output: 4->5->1->2->3->NULL
Explanation:
rotate 1 steps to the right: 5->1->2->3->4->NULL
rotate 2 steps to the right: 4->5->1->2->3->NULL
```

**Example 2:**

```
Input: 0->1->2->NULL, k = 4
Output: 2->0->1->NULL
Explanation:
rotate 1 steps to the right: 2->0->1->NULL
rotate 2 steps to the right: 1->2->0->NULL
rotate 3 steps to the right: 0->1->2->NULL
rotate 4 steps to the right: 2->0->1->NULL
```

**Tags:** `linked list`

## 思路 

结题思路是先遍历链表到尾节点，得到链表长度count。当k大于等于count时，循环一遍没什么意义。因此只要找到小于count的那部分移动就可以。我们目的是找到新的头结点，通过简单举例可以得到，从当前头结点移动count - k % count 即是新的头结点。知道了这里，代码就简单了。

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
    ListNode* rotateRight(ListNode* head, int k) {
        if (NULL == head || k == 0) 
            return head;
        ListNode *preTail, *currentNode = head;
        int count = 0;
        while(currentNode) {
            preTail = currentNode;
            currentNode = currentNode->next;
            count++;
        }
        if (k % count == 0)
            return head;
        preTail->next = head;
        int steps = count - k % count;
        currentNode = head;
        while(steps != 1) {
            currentNode = currentNode->next;
            steps--;
        }
        head = currentNode->next;
        currentNode->next = NULL;
        return head;
    }
};
```

## 结语

重点还是考察取模运算的概念。