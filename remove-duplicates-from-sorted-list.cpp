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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *tmpNode = head;
        while(tmpNode) {
            ListNode *next = tmpNode->next;
            while(next && next->val == tmpNode->val) {
                next = next->next;
            }
            tmpNode->next = next;
            tmpNode = next;
        } 
        return head;
    }
};