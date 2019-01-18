# 

# [Flatten a Multilevel Doubly Linked List][title]

## Description

You are given a doubly linked list which in addition to the next and previous pointers, it could have a child pointer, which may or may not point to a separate doubly linked list. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure, as shown in the example below.

Flatten the list so that all the nodes appear in a single-level, doubly linked list. You are given the head of the first level of the list.

Example:**

```
Input:
 1---2---3---4---5---6--NULL
         |
         7---8---9---10--NULL
             |
             11--12--NULL

Output:
1-2-3-7-8-11-12-9-10-4-5-6-NULL
```

**Explanation for the above example:**

Given the following multilevel doubly linked list:

![multilevellinkedlist](multilevellinkedlist.png)

We should return the following flattened doubly linked list:

![multilevellinkedlistflattened](multilevellinkedlistflattened.png)

**Tags:** linked list


## 思路 0

这个题目和swift中常常用到的flattenMap有点像，展开一个二维数组，这里用链表来表示了多维的概念。要注意的是，这里看题目描述中对结果的描述，要把每个结点的pre，next都设置正确，同时结果中child要设置为NULL，开始就是没注意这里导致pre和child没有重新设置。一个思路就是用一个堆栈来保存即将去展开当前结点的child结点的下一个结点。当当前结点的child以及子结点都展开完了。从堆栈中找到上次跳出的结果，从这个结点继续走下去，依次到达结尾。

```cpp
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        std::vector<Node*> stack;
        Node *current = head;
        while(current)
        {
            if (current->child) 
            {
                if (current->next)
                    stack.push_back(current->next);
                current->next = current->child;
                current->child = NULL;
            } 
            else if (current->next == NULL && !stack.empty())
            {
                Node *tmpNode = stack.back();
                if (tmpNode)
                {
                    stack.pop_back();
                    current->next = tmpNode;
                }
            }
            if (current->next) {
                current->next->prev = current;
            }
            current = current->next;
        }
        return head;
    }
};
```

## 思路 1

利用 HashMap 作为存储，键为目标值减去当前元素值，索引为值，比如 `i = 0` 时，此时首先要判断 `nums[0] = 2` 是否在 map 中，如果不存在，那么插入键值对 `key = 9 - 2 = 7, value = 0`，之后当 `i = 1` 时，此时判断 `nums[1] = 7` 已存在于 map 中，那么取出该 `value = 0` 作为第一个返回值，当前 `i` 作为第二个返回值，具体代码如下所示。

```java
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        std::vector<Node*> stack;
        Node *current = head;
        while(current)
        {
            if (current->child) 
            {
                if (current->next)
                    stack.push_back(current->next);
                current->next = current->child;
                current->child = NULL;
            } 
            else if (current->next == NULL && !stack.empty())
            {
                Node *tmpNode = stack.back();
                if (tmpNode)
                {
                    stack.pop_back();
                    current->next = tmpNode;
                }
            }
            if (current->next) {
                current->next->prev = current;
            }
            current = current->next;
        }
        return head;
    }
};
```


## 结语

如果你同我一样热爱数据结构、算法、LeetCode，可以关注我 GitHub 上的 LeetCode 题解：[awesome-java-leetcode][ajl]



[title]: https://leetcode.com/problems/two-sum
[ajl]: https://github.com/Blankj/awesome-java-leetcode