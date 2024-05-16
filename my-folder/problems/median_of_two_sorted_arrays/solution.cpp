class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(),n2 = nums2.size();
        int n = n1 + n2;

        int index2 = n/2;
        int index1 = index2 - 1;
        int index = 0;
        double ele1 = -1,ele2 = -1;

        int i = 0,j = 0;

        while(i<n1 && j<n2)
        {
            if(nums1[i] <= nums2[j])
            {
                if(index == index1) ele1 = nums1[i];
                if(index == index2) ele2 = nums1[i];

                index++;
                i++;
            }
            else{
                if(index == index1) ele1 = nums2[j];
                if(index == index2) ele2 = nums2[j];

                index++;
                j++;
            }
        }
        while(j<n2)
        {
           
                if(index == index1) ele1 = nums2[j];
                if(index == index2) ele2 = nums2[j];

                index++;
                j++;
            
        }
        while(i<n1)
        {
            
                if(index == index1) ele1 = nums1[i];
                if(index == index2) ele2 = nums1[i];

                index++;
                i++;
            
        }

        if(n%2 == 1)
            return ele2;
        else
        {
            return (ele1+ele2)/2.0;
        }

    }
};