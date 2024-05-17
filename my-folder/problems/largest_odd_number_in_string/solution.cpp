class Solution {
public:
    string largestOddNumber(string nums) {

        int i = nums.size() - 1;

        while(i>=0 && (nums[i] - '0') % 2 == 0)
            i--;
        // cout<<i<<endl;
        return nums.substr(0,i+1);
        
    }
};