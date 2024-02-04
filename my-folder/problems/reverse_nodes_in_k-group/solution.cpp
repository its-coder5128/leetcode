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
    ListNode* solve(ListNode* head, int k,int n)
    {
        if(n < k)
            return head;
        
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* tail = head;
        ListNode* next = curr -> next;

        for(int i = 0;i<k-1;i++)
        {
            curr -> next = prev;
            prev = curr;
            curr = next;
            next = next -> next;
        }
        curr -> next = prev;

        tail -> next = solve(next,k,n-k);

        return curr;


    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        
        int n = 0;
        ListNode* temp = head;

        while(temp)
        {
            n++;
            temp = temp -> next;
        }
        
        return solve(head,k,n);
    }
};