class Solution {
public:
    int search(vector<int>& nums, int target) {

        int s = 0;
        int e = nums.size() - 1;

        while(s<e)
        {
            int mid = s + (e - s)/2;

            if(nums[mid] >= nums[0])
                s=mid+1;
            else
                e = mid;
        }

        if( target >= nums[0])
        {
            e = s;
            s = 0;

            while(s<=e)
            {
                int mid = s + (e - s)/2;

                if(nums[mid] == target)
                    return mid;

                if( nums[mid] > target)
                    e = mid - 1;
                else 
                    s = mid + 1;
            }

        }
        else{
            e = nums.size() - 1;

            while(s<=e)
            {
                int mid = s + (e - s)/2;

                if(nums[mid] == target)
                    return mid;

                if( nums[mid] > target)
                    e = mid - 1;
                else 
                    s = mid + 1;
            }

        }

        return  -1;
    }
};