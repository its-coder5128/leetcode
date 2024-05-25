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
    int nodeCNT(ListNode* head)
    {
        int cnt = 0;
        ListNode* temp = head;
        while(temp)
        {
            cnt++;
            temp = temp -> next;
        }

        return cnt;
    }
    bool isPalindrome(ListNode* head) {

        if(head == nullptr || head -> next == nullptr)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* prev = NULL;
        ListNode* future = head->next;

        while(fast && fast->next)
        {
            fast = fast -> next -> next;
            slow -> next = prev;
            prev = slow;
            slow = future;
            future = future -> next;
        }
        ListNode* curr = slow;

        if(fast)
            curr = slow -> next;

        slow = prev;

            

        while(curr && slow)
        {
            cout<<slow -> val<<" "<<curr -> val<<endl;
            if(slow -> val != curr -> val)
                return false;
            slow = slow -> next;
            curr = curr -> next;
        }

        return true;

    }
};