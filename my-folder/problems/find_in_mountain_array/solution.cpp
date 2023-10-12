/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binSearch(MountainArray &mountainArr,int tar,int s,int e,bool f)
    {
        while(s<=e)
        {
            int mid = s + (e-s)/2;

            int curr = mountainArr.get(mid);

            if(tar == curr)
                return mid;

            if(tar > curr && f)
                s = mid + 1;
            else if(tar > curr && !f)
                e = mid - 1;
            else if(tar < curr && f)
                e = mid - 1;
            else if(tar < curr && !f)
                s = mid + 1;
            
        }

        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {

        int s = 1;
        int e = mountainArr.length()-2;
        int n = e;

        int index=0;

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            int prev = mountainArr.get(mid-1);
            int curr = mountainArr.get(mid);
            int next = mountainArr.get(mid+1);
        
            if(curr>prev && curr>next)
            {
                index = mid;
                break;
            }
            else if(curr>prev && curr<next)
                s = mid + 1;
            else if( curr < prev && curr > next)
                e = mid - 1;
        }
        
        int left = binSearch(mountainArr,target,0,index,true);

        if(left!= -1)
            return left;

        int right = binSearch(mountainArr,target,index,n+1,false);
        return right;

        
    }
};