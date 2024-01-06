class Solution {
public:
    int missingInteger(vector<int>& nums) {
        
        int maxiCnt = 0;
        int maxiSum = 0;  
        unordered_map<int,int> m;
        
        int i = 0;
        
        while(i<nums.size())
        {
            int sum = nums[i];
            int cnt = 1;
            m[nums[i]]++;
            i++;
            while(i<nums.size() && nums[i] == nums[i-1]+1)
            {
                sum += nums[i];
                cnt++;
                m[nums[i]]++;
                i++;
            }
            
            if(maxiCnt<cnt)
            {
                maxiCnt = cnt;
                maxiSum = sum;
            }
            break;
        }
        
        while(true)
        {
            int flag = 1;
            for(int i = 0;i<nums.size();i++)
            {
                if(nums[i] == maxiSum)
                {
                    flag = 0;
                    maxiSum++;
                }
            }
            if(flag)
                return maxiSum;
        }
        return -1;
        
    }
};