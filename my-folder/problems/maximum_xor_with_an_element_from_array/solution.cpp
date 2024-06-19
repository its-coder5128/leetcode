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
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = queries.size();

        vector<int> ans(m,-1);

        Trie t;

        vector<vector<int>> dp(m,vector<int>(3,0));

        for(int i= 0;i<m;i++)
        {
            dp[i][0] = queries[i][1];
            dp[i][1] = queries[i][0];
            dp[i][2] = i;
        }

        sort(dp.begin(),dp.end());
        sort(nums.begin(),nums.end());

        int i = 0;
        int j = 0;

        while(i < n && j < m)
        {
            if(nums[i] <= dp[j][0])
            {
                t.insertNum(nums[i]);
                i++;
            }
            else{
                if(i != 0)
                {
                    int maxi = t.findMaxXOR(dp[j][1]);
                    ans[dp[j][2]] = maxi;
                }
                j++;
            }
        }
        while(j<m)
        {
            if(i != 0)
            {
                int maxi = t.findMaxXOR(dp[j][1]);
                ans[dp[j][2]] = maxi;
            }
            j++;
        }
        return ans;
    }
};