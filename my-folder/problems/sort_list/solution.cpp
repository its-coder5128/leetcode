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
    ListNode* merge(ListNode* left,ListNode* right)
    {
        if(left -> val > right -> val)
            return merge(right,left);
        ListNode* prev = NULL;
        ListNode* curr = left;

        while(curr && right)
        {
            if(curr -> val <= right -> val)
            {
                prev = curr;
                curr = curr -> next;
            }
            else {
                if(prev)
                    prev -> next = right;
                prev = right;
                right = right -> next;
                prev -> next = curr;
            }
        }

        if(curr == NULL)
            prev -> next = right;

        return left;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        if(head == NULL || head -> next == NULL)
            return head;

        while(fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = slow->next;
        slow -> next = NULL;

        if(fast == NULL)
            return slow;

        ListNode* left = sortList(head);
        ListNode* right = sortList(fast);


        return head = merge(left,right);        
        
    }
};