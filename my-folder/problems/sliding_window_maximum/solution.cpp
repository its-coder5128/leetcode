class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int i=0;
        int j=0;

        deque<int> q;

        // q.push_back(i);

        // while(j<k)
        // {
        //     if(nums[q.front()] < nums[j])
        //         q.push_front(j);
        //     else{
        //         while(!q.empty() && nums[q.back()]<nums[j])
        //         {
        //             q.pop_back();
        //         }
        //         q.push_back(j);
        //     }
        //     j++;
        // }

        // i++;
        vector<int> ans;
        //ans.push_back(nums[q.front()]);

        while(j<nums.size())
        {
            while(!q.empty() && q.front() < i)
            {
                q.pop_front();
            }
            if(q.empty() || nums[q.front()] < nums[j])
                q.push_front(j);
            else{
                while(!q.empty() && nums[q.back()]<nums[j])
                {
                    q.pop_back();
                }
                q.push_back(j);
            }
            j++;
            if(j - i == k )
            {
                ans.push_back(nums[q.front()]);
                i++;
            }

        }


        return ans;
        
    }
};