class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        deque<int> q;
        vector<int> ans;
        int i=0,j=0;


        while(i<nums.size())
        {
            while(!q.empty() && q.front() <= i-k)
                q.pop_front();
            
            while(!q.empty() && nums[q.back()] <= nums[i])
                q.pop_back();

            q.push_back(i++);

            if(i-j == k)
            {
                ans.push_back(nums[q.front()]);
                j++;
            }

        }

        return ans;
        
    }
};