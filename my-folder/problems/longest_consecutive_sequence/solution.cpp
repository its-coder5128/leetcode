class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> m;

        int n = nums.size();

        for(int i=n-1;i>=0;i--)
        {
            m.insert(nums[i]);
        }

        int maxi = 0;

        for(int i = 0;i<n;i++)
        {
           int x = nums[i];
           int cnt = 1;

           if(m.find(x-1) == m.end())
           {
                while(m.find(x+1) != m.end())
                {
                    x += 1;
                    cnt += 1;
                }
                maxi = max(maxi,cnt);
           }
        }

        return maxi;
    }
};