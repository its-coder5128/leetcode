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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;

        if(temp1 == temp2)
            return temp1;

        while(temp1 -> next || temp2 -> next)
        {

            if(temp1 -> next)
                temp1 = temp1 -> next;
            else
                temp1 = headB;

            if(temp2 -> next)
                temp2 = temp2 -> next;
            else
                temp2 = headA;
                
            if(temp1 == temp2)
                return temp1;
        }

        return NULL;
        
    }
};