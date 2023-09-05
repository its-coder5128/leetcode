/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* add(int val)
    {
        Node* temp = new Node(val);
        return temp;
    }
    Node* copyRandomList(Node* head) {

        unordered_map<Node* , int> m1;
        unordered_map<int , Node*> m2;
        int i=0;

        Node* temp = head;
        Node* head1 = new Node(-1);
        Node* tail = head1;

        while(temp)
        {
            m1[temp] = i;
            tail -> next = add(temp->val);
            tail = tail->next;
            m2[i] = tail;

            i++;
            temp = temp -> next;
        }

        temp = head;
        tail = head1 -> next;
        while(temp)
        {
            if(temp -> random)
                tail -> random = m2[m1[temp -> random]] ;

            temp = temp -> next;
            tail = tail -> next;
        }
    
        return head1 -> next;
    }
};