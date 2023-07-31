class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        // int smallest = nums[0];
        // int largest = nums[nums.size()-1];

        int i=0;
        int j=nums.size() - 1;

        int count = 0;

        while(i<j)
        {
            int first = nums[i];
            int second = nums[j];

            if( first + second == k)
            {
                i++;
                j--;
                count++;
            }
            else if(first + second < k)
            {
                i++;
            }
            else{
                j--;
            }


        }

        return count;
    }
};