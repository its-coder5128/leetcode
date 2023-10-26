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
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* head = new ListNode(-1);
        ListNode* tail = head;

        priority_queue<pair<int,ListNode*>,vector<pair<int,ListNode*>>,greater<pair<int,ListNode*>>> q;

        for(int i = 0 ; i<lists.size();i++)
        {
            if(lists[i])
                q.push({lists[i]->val,lists[i]});
        }

        while(!q.empty())
        {
            auto p = q.top();
            q.pop();

            tail -> next = p.second;
            tail = tail -> next;

            if(p.second->next)
                q.push({p.second->next->val,p.second->next});
        }

        return head->next;
        
    }
};