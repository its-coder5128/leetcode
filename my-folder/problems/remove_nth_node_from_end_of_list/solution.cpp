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
    ListNode* removeNthFromE(ListNode* head, int& n)
    {
        if(head == NULL)
            return head;

        head -> next = removeNthFromE(head->next,n);


        if(n == 0)
        {
            ListNode* temp = head-> next;
            head -> next = temp -> next;
            temp -> next = NULL;
            delete temp;
        }
        n--;

        return  head; 
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* temp = new ListNode(-1);
        temp -> next = head;

        temp = removeNthFromE(temp,n);

        return temp -> next;
        
    }
};