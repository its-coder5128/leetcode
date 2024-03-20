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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* curr = list1;
        ListNode* prev = NULL;

        for(int i = 0;i<a;i++ )
        {
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = list2;

        while(prev->next)
        {
            prev = prev -> next;
        }

        for(int i = 0;i<=(b-a);i++)
        {
            curr = curr -> next;
        }

        prev -> next = curr;

        return list1;


    }
};