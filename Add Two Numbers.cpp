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
	ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		//°æ±¾1
		//     int carry = 0;
		//     ListNode *head;
		//     ListNode *p = (ListNode*)malloc(sizeof(ListNode));
		//     p->val = 0;
		//     p->next = NULL;
		//     head = p;

		//     while(l1 && l2)
		//     {
		//         ListNode *q = (ListNode*)malloc(sizeof(ListNode));
		//         q->next = NULL;
		//         q -> val = (l1->val + l2->val  + carry) % 10;
		//         carry = (l1->val + l2->val + carry) / 10;
		//         p->next = q;
		//         p  = q;
		//         l1 = l1->next;
		//         l2 = l2->next;
		//     }
		//     while(l1)
		//     {
		//          ListNode *q = (ListNode*)malloc(sizeof(ListNode));
		//          q->next = NULL;
		//          q->val = (l1 ->val + carry) % 10;
		//          carry = (l1 ->val + carry) / 10;
		//          p->next = q;
		//          p = q;
		//          l1 = l1 ->next;
		//     }
		//     while(l2)
		//     {
		//          ListNode *q = (ListNode*)malloc(sizeof(ListNode));
		//          q->next = NULL;
		//          q->val = (l2 ->val + carry) % 10;
		//          carry = (l2 ->val + carry) / 10;
		//          p->next = q;
		//          p = q;
		//          l2 = l2 ->next;
		//     }

		//     if(carry)
		//     {
		//         ListNode *q = (ListNode*)malloc(sizeof(ListNode));
		//         q->next = NULL;
		//         q->val = 1;
		//         p->next = q;
		//     }
		//     return head->next;

		//°æ±¾2
		ListNode head(-1);
		ListNode *p = &head;
		int carry = 0;
		for (; l1 != nullptr || l2 != nullptr;
			l1 = (l1 == nullptr ? nullptr : l1->next),
			l2 = (l2 == nullptr ? nullptr : l2->next))
		{
			const int a1 = l1 == nullptr ? 0 : l1->val;
			const int b1 = l2 == nullptr ? 0 : l2->val;
			const int value = (a1 + b1 + carry) % 10;
			carry = (a1 + b1 + carry) / 10;
			p->next = new ListNode(value);
			p = p->next;
		}
		if (carry)
			p->next = new ListNode(1);
		return head.next;
	}
	//     int x=0, y=0, carry=0, sum=0;
	//         ListNode *h=NULL, **t=&h;

	//         while (l1!=NULL || l2!=NULL){
	//             x = getValueAndMoveNext(l1);
	//             y = getValueAndMoveNext(l2);

	//             sum = carry + x + y;

	//             ListNode *node = new ListNode(sum%10);
	//             *t = node;
	//             t = (&node->next);

	//             carry = sum/10;
	//         }

	//         if (carry > 0) {
	//             ListNode *node = new ListNode(carry%10);
	//             *t = node;
	//         }

	//         return h;
	//     }
	// private:
	//     int getValueAndMoveNext(ListNode* &l){
	//         int x = 0;
	//         if (l != NULL){
	//             x = l->val;
	//             l = l->next;
	//         }
	//         return x;
	//     }
};