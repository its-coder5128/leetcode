class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i=0,j=0,temp;

        while(i<m && j<n)
        {
            if(nums1[i]<nums2[j])
            {
                i++;
            }
            else if(nums1[i]==nums2[j])
            {
                i++;
                temp=m;
                for(temp;temp>i;temp--)
                {
                    nums1[temp]=nums1[temp-1];
                }
                nums1[i]=nums2[j];
                m++;
                i++;
                j++;
            }
            else
            {
                temp=m;
                for(temp;temp>i;temp--)
                {
                    nums1[temp]=nums1[temp-1];
                }
                nums1[i]=nums2[j];
                m++;
                i++;
                j++;
            }
        }
        while(j<n)
        {
            nums1[i]=nums2[j];
            i++;
            j++;
        }
        
    }
};