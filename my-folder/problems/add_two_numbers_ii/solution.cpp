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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

       
        l1=rev(l1);
        l2=rev(l2);

        ListNode* head = new ListNode(-1);
        ListNode* tail=head;

        int carry=0;
        while(l1 && l2)
        {
            int x = l1->val;
            int y = l2->val;

            l1 = l1 -> next;
            l2 = l2 -> next;

            int sum = (x+y+carry)%10;
            carry = (x+y+carry)/10;

            ListNode* temp=new ListNode(sum);
            tail -> next =temp;
            tail = tail -> next;  
        }

        while(l1)
        {
            int x = l1->val;
            l1=l1->next;
            int sum = (x+carry)%10;
            carry = (x+carry)/10;

            ListNode* temp=new ListNode(sum);
            tail -> next =temp;
            tail = tail -> next;
        }
        while(l2)
        {
            int x = l2->val;
            l2=l2->next;
            int sum = (x+carry)%10;
            carry = (x+carry)/10;

            ListNode* temp=new ListNode(sum);
            tail -> next =temp;
            tail = tail -> next;
        }

        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            tail -> next = temp;
            tail = tail -> next;
        }

        head=head -> next;

        head=rev(head);

        return head;
        
    }
};