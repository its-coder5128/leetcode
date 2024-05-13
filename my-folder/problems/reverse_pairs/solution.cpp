class Solution {
public:
    int merge(vector<int>& nums,int low,int mid,int high)
    {
        vector<int> temp(high-low+1,0);

        int left = mid;
        int right = high;
        int index = high - low ;
        int cnt = 0;

        while(left >=low && right > mid)
        {
            if(nums[left] <= nums[right])
            {
                temp[index--] = nums[right--];
            }
            else{
                temp[index--] = nums[left--];
            }
            
        }
        while(left>=low)
        {
            temp[index--] = nums[left--];
        }
        while(right>mid)
        {
            temp[index--] = nums[right--];
        }

        for(int i = 0;i<temp.size();i++)
        {
            nums[low++] = temp[i];
        }
        

        return cnt;
    }
    int cntPair(vector<int>& nums,int low,int mid,int high)
    {
        int right = mid+1;
        int cnt = 0;

        for(int i = low;i<=mid;i++)
        {
            while (right <= high && (long long)nums[i] > 2 * (long long)nums[right]) right++;
            cnt += (right - (mid + 1));
        }
        return cnt;
    }
    int mergeSort(vector<int>& nums,int low,int high)
    {
        int cnt = 0;
        if(low>=high)
            return cnt;
        int mid = (low + high)/2;

        cnt += mergeSort(nums,low,mid);
        cnt += mergeSort(nums,mid+1,high);

        cnt += cntPair(nums,low,mid,high);
        
        merge(nums,low,mid,high);

        return cnt;
    }
    int reversePairs(vector<int>& nums) {
        int ans = mergeSort(nums,0,nums.size()-1);

        for(auto it:nums)
            cout<<it<<" ";
        return ans;
    }
};