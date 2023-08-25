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
    ListNode* swapNodes(ListNode* head, int k) {
        unordered_map<int,ListNode*> m;

        ListNode* temp = head;
        int i = 1;
        while( temp )
        {
            m[i++] = temp;
            temp = temp -> next;
        }
        
        swap(m[k] -> val, m[i-k] -> val);

        return head;
        
    }
};