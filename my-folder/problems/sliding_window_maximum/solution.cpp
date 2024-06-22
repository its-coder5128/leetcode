class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;

        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> ans;

        while(j<n)
        {
            while(!dq.empty() && nums[dq.back()] < nums[j])
                dq.pop_back();
            
            dq.push_back(j);

            if(j-i+1 == k)
            {
                while(!dq.empty() && dq.front() < i)
                    dq.pop_front();
                i++;
                ans.push_back(nums[dq.front()]);
            }
            j++;
        }

        return ans;
    }
};