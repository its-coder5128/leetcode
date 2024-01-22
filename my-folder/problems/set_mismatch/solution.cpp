class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();

        vector<int> arr(n+1,0);

        for(auto num:nums)
        {
            arr[num]++;
        }

        vector<int> ans(2,0);

        for(int i = 1;i<=n;i++)
        {
            if(arr[i] == 0)
                ans[1] = i;
            else if(arr[i] == 2)
                ans[0] = i;

        }

        return ans;
        
    }
};