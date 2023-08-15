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
    ListNode* partition(ListNode* head, int x) {

        ListNode* temp = head;
        ListNode* small = new ListNode(-1);
        ListNode* sn = small;
        ListNode* large = new ListNode(-1);
        ListNode* ln = large;

        while(temp != NULL)
        {
            if(temp -> val < x)
            {
                sn -> next = temp;
                sn = temp;
            }
            else{
                ln -> next = temp;
                ln = temp;
            }
            temp = temp -> next;
        }

        ln -> next = NULL;

        sn -> next = large -> next;

        return small -> next;
    }
};