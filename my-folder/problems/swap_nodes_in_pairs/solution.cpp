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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head -> next == NULL)
            return head;
        
        ListNode* curr = head -> next;
        ListNode* prev = head;
        ListNode* next = curr -> next;

        head = curr;

        while(curr)
        {
            prev -> next = next;
            curr -> next = prev;

            if(next && next -> next)
            {
                prev -> next = next -> next;
                prev = next;
                curr = prev -> next;
                if(curr)
                    next = curr -> next;
            }
            else
                break;
        }

        return head;

        
    }
};