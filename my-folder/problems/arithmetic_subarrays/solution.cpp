class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {

        vector<bool> ans;

        for(int i = 0;i<l.size();i++)
        {
            int left = l[i];
            int right = r[i];

            vector<int> temp;
            for(int j = left;j<=right;j++)
                temp.push_back(nums[j]);
            
            if(temp.size() <= 1)
            {
                ans.push_back(true);
                continue;
            }

            sort(temp.begin(),temp.end());

            int d = temp[1] - temp[0];
            bool flag = true;

            for(int k = 2;k<temp.size();k++)
            {
                if(d != temp[k] - temp[k-1])
                {
                    flag = false;
                    break;
                }
            }

            ans.push_back(flag);

        }
        return ans;
        
    }
};