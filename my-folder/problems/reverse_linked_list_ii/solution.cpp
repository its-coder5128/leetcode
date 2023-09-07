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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || left == right)
            return head;
        
        ListNode* dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode* prev = dummy;

        for(int i=0;i<left-1;i++)
        {
            prev = prev -> next;
        }
        ListNode* current = prev->next;

        for(int i = 0;i<right - left;i++)
        {
            ListNode* newNode = current->next;
            current -> next = newNode -> next;
            newNode -> next = prev -> next;
            prev -> next = newNode;
        }

        return dummy -> next;
    }
};