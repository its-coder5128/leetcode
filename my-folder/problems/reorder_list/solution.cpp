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
    void reorderList(ListNode* head) {

        if(head == NULL || head -> next == NULL)
            return;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;

        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode* curr = slow -> next;
        ListNode* next = slow -> next -> next;

        slow -> next = NULL;
        slow = NULL;

        while(next)
        {
            curr -> next = slow;
            slow = curr;
            curr = next;
            next = next -> next;
        }

        curr -> next = slow;

        next = head -> next;

        while(next && slow)
        {
            temp -> next = curr;
            curr -> next = next;
            temp = next;
            curr = slow;
            next = next -> next;
            slow = slow -> next;
        }
        temp -> next = curr;
        curr -> next = next;


        return ;


    }
};