class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        sort(nums.begin(),nums.end());

        set<vector<int>> s;

        int n = nums.size();

        for(int i = 0 ;i<n;i++)
        {
            int one = nums[i];
            for(int j=i+1;j<n;j++)
            {
                int k = j+1;
                int l = n-1;

                int two = nums[j];

                while(k<l)
                {
                    int three = nums[k];
                    int four = nums[l];

                    long long sum = (long long)one +  (long long)two +  (long long)three +  (long long)four;

                    if(sum == target)
                    {
                        s.insert({one,two,three,four});
                        k++;
                        l--;
                    }
                    else if(sum > target)
                        l--;
                    else
                        k++;

                }
            }
        }

        vector<vector<int>> ans;
        for(auto i:s)
        {
            ans.push_back(i);
        }

        return ans;
        
    }
};