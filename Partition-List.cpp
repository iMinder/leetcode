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
    ListNode* partition(ListNode* head, int x) {
        ListNode *headNode = new ListNode(0);
        ListNode *resultNode = headNode;
        ListNode *tailNode = new ListNode(0);
        ListNode *resultTail = tailNode;
        ListNode *current = head;
        while(current) {
            if (current->val < x) {
                headNode->next = current;
                headNode = current;
            } else {
                tailNode->next = current;
                tailNode = current;
            }
            current = current->next;
        }
        tailNode->next = NULL;
        headNode->next = resultTail->next;
        return resultNode->next;
    }
};
