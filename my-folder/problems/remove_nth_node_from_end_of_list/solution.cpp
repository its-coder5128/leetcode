
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
    ListNode* rev(ListNode* head)
    {
        if( head == NULL)
            return head;
            
        ListNode* prev=NULL;
        ListNode* forward=head -> next;
        
        while(forward != NULL)
        {
            head -> next = prev;
            prev = head;
            head = forward;
            forward = forward -> next;
        }

        head -> next = prev;;

        return head;

    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        if(head == NULL)
            return head;

        head = rev(head);

        ListNode* temp = new ListNode(-1);
        temp -> next = head;
        head = temp;

        int i=1;

        temp = temp -> next;
        ListNode* prev = head;

        while(i<n)
        {
            prev = prev -> next;
            temp = temp -> next;
            i++;
        }

       prev -> next = temp -> next;
       temp -> next = NULL;
       delete(temp);

        head = head -> next;
        head = rev(head);

        return head;

        
    }
};