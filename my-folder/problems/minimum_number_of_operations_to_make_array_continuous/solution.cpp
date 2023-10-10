class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());
        nums.push_back(INT_MAX);

        vector<int> uni;

        for(int i = 0;i<n;i++)
        {
            while(nums[i] == nums[i+1])  i++;
            uni.push_back(nums[i]);
        }

        int ans = INT_MAX;

        for(int i = 0;i<uni.size();i++)
        {
            int s = uni[i];
            int e = s + n - 1;
            int index = upper_bound(uni.begin(),uni.end(),e) - uni.begin();

            cout<<index<<endl;

            ans = min(ans , n - (index - i) ) ;
        }
        

        return ans;
        
    }
};