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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        
        vector<ListNode*> ans;
        ListNode* temp = head;
        int n = 0;
        while(temp)
        {
            temp = temp -> next;
            n++;
        }

        int perSet = n/k;
        int extra = n - (k*perSet);

        for(int i=0;i<k;i++)
        {
            if(head == NULL)
            {
                ans.push_back(NULL);
                continue;
            }

            ListNode* tail = head;
            temp = tail;
            for(int j=0;j<perSet;j++)
            {
                temp = tail;
                tail = tail -> next;
            }
            if(extra)
            {
                temp = tail;
                tail = tail -> next;
                extra--;
            }
            temp -> next = NULL;

            ans.push_back(head);
            head = tail;
        }
        return ans;
    }
};