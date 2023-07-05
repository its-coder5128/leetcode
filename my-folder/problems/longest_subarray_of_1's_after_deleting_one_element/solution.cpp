class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int c1=0,c2=0,aux=0,maxi=0;
        

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == 1)
            {
                c1++;
            }
            else{
                c2=aux+c1;
                aux=c1;
                c1=0;
                maxi=max(maxi,c2);
            }
        }
        c2=aux+c1;
        maxi=max(maxi,c2);
        
        if(maxi==nums.size())
            return maxi - 1;
        return maxi;
    }
};