class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int z = 0;
        int nz = 0;
        int n = nums.size();

        while(nz<n)
        {
            if(nums[nz] != 0)
            {
                swap(nums[nz++],nums[z++]); 
            }
            else{
                nz++;
            }
        }
    }
};