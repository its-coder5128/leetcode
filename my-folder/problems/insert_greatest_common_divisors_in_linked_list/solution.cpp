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
    int gcd(int x,int y)
    {
        while(x!=y)
        {
            if(x>y)
            {
                x = x - y;
            }
            else
                y = y - x;
        }
        
        return x;
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head -> next;
        
        while(curr != NULL)
        {
            int x=curr->val;
            int y=prev->val;
            
            int g = gcd(x,y);
            
            ListNode* temp = new ListNode(g);
            
            temp -> next = curr;
            prev -> next = temp;
            prev=curr;
            curr = curr -> next;
        }
        
        return head;
        
    }
};