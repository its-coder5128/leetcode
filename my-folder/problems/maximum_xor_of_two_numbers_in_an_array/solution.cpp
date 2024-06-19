class Node{
public:
    bool flag = false;
    Node* link[2];

    bool isContain(int x)
    {
        return (link[x] != NULL);
    }

    void createLink(int x)
    {
        link[x] = new Node();
        return;
    }

    Node* goTo(int x)
    {
        return link[x];
    }

    void ended()
    {
        flag = true;
        return;
    }
};
class Trie{
private:
    Node* root;
public:
    Trie(){
        root = new Node();
    }

    void insertNum(int num)
    {
        Node* temp = root;

        for(int i = 31;i>=0;i--)
        {
            int x = (num & (1<<i)) ? 1 : 0;

            if(!(temp -> isContain(x)))
                temp -> createLink(x);
            
            temp = temp -> goTo(x);
        }
        temp -> ended();
        return;
    }

    int findMaxXOR(int num)
    {
        Node* temp = root;
        int ans = 0;
        for(int i = 31;i>=0;i--)
        {
            int x = (num & (1<<i)) ? 1 : 0;

            if(temp -> isContain(!x))
            {
                ans  = (ans | (1<<i));
                temp = temp -> goTo(!x);
            }
            else
                temp = temp -> goTo(x);
        }

        return ans;

    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int maxi = 0;
        int n = nums.size();

        Trie t;

        for(int i = 0;i<n;i++)
        {
            t.insertNum(nums[i]);
        }

        for(int i = 0;i<n;i++)
        {
            maxi = max(maxi,t.findMaxXOR(nums[i]));
        }

        return maxi;
    }
};