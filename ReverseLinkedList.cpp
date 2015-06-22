/**
 * This is a recursive solution.
 */
 
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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return head;
        ListNode* reversedList = reverseList(head->next);
        ListNode* tmp = head->next->next;
        head->next->next = head;
        head->next = tmp;
        head = reversedList;
        return head;
    }
};