class Solution {
public:
    bool search(vector<int>& arr, int target) {
        int s = 0;
        int e = arr.size() - 1;

        while(s<=e)
        {
            int m = s + (e-s)/2;

            if(arr[m] == target)
                return true;
            
            if(arr[m] == arr[s] && arr[m] == arr[e])
            {
                e--;
                s++;
                continue;
            }

            if(arr[s] <= arr[m])
            {
                if(arr[s] <= target && target < arr[m])
                    e = m - 1;
                else 
                    s = m + 1;
            }
            else{
                if(target <= arr[e] && arr[m] < target)
                    s = m + 1;
                else
                    e = m - 1;
            }
        }

        return false;
    }
};