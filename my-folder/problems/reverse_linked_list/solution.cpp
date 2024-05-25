/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseLinkedList(ListNode* head) {
    
    if(head == NULL || head -> next == NULL)
        return head;
    
    ListNode* newHead = reverseLinkedList(head -> next);

    ListNode* next = head -> next;

    next -> next =  head;

    head -> next = NULL;

    return newHead;
}
    ListNode* reverseList(ListNode* head) {
        return reverseLinkedList(head);
    }
};