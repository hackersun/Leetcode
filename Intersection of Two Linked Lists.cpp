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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL || headB == NULL) return NULL;
		int lengthA = 1, lengthB = 1;
		ListNode* pa = headA;
		ListNode* pb = headB;
		while(pa->next) {lengthA++; pa = pa->next;}
		while(pb->next) {lengthB++; pb = pb->next;}
		if(pa != pb) return NULL;
		int diff = lengthA - lengthB;
		pa = headA; pb = headB;
		if(diff > 0){
			while(diff-- > 0) pa = pa->next;
		}else{
			while(diff++ < 0) pb = pb->next;
		}
		while(pa != pb){
			pa = pa->next;
			pb = pb->next;
		}
		return pa;
    }
};