class Solution {
public:
    static bool cmp(int a,int b)
    {
        return b<a;
    }
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end(),cmp);

        return nums[k-1];
    }
};