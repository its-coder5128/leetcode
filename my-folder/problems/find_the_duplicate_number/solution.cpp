class Solution {
public:
    int findDuplicate(vector<int>& nums) {

        int n=nums.size();

        unordered_map<int,int> m;

            for(int j=0;j<n;j++)
            {
                m[nums[j]]++;

                if(m[nums[j]] == 2 )
                    return nums[j];
            }


        return -1;
        
    }
};