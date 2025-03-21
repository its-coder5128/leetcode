class Solution {
    unordered_map<int,vector<int>> m;
public:
    Solution(vector<int>& nums) {
        for(int i = 0;i<nums.size();i++)
        {
            m[nums[i]].push_back(i);
        }
        srand(time(0));
    }
    
    int pick(int target) {

        int n = m[target].size();

        int index = rand()%n;

        return m[target][index];
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */