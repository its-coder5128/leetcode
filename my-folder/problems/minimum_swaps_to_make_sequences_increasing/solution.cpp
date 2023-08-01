class Solution {
public:
    int solve(vector<int>& nums1, vector<int>& nums2,int index,bool swapped,vector<vector<int>> &dp)
    {
        if(index == nums1.size())
            return 0;
        if(dp[index][swapped] != -1)
            return dp[index][swapped];
        
        int prev1=nums1[index-1];
        int prev2=nums2[index-1];

        if(swapped)
            swap(prev1,prev2);
        
        int noSwap = INT_MAX;
        int Swap = INT_MAX;

        if(nums1[index]>prev2 && nums2[index]>prev1)
            Swap= 1 + solve(nums1,nums2,index+1,1,dp);
        if(prev1 < nums1[index] && prev2 < nums2[index])
            noSwap = 0 + solve(nums1,nums2,index+1,0,dp);
        
        dp[index][swapped] = min(noSwap,Swap);         

        return min(noSwap,Swap);
    }
    int solveTab(vector<int>& nums1, vector<int>& nums2)
    {
       // vector<vector<int>> dp(nums1.size()+1,vector<int>(2,0));
        vector<int> curr(2,0);
        vector<int> next(2,0);


        for(int i=nums1.size()-1;i>=1;i--)
        {
            for(int swapped=0;swapped<2;swapped++)
            {
                int prev1=nums1[i-1];
                int prev2=nums2[i-1];

                if(swapped)
                    swap(prev1,prev2);
                
                int noSwap = 1e9;
                int Swap = 1e9;

                if(nums1[i]>prev2 && nums2[i]>prev1)
                    Swap= 1 + next[1];
                if(prev1 < nums1[i] && prev2 < nums2[i])
                    noSwap = 0 + next[0];
                
                curr[swapped] = min(noSwap,Swap);    
            }

            next=curr;
        }

        return curr[0];
    }
    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(),-1);
        nums2.insert(nums2.begin(),-1);

        //vector<vector<int>> dp(nums1.size(),vector<int>(2,-1));

        //int ans = solve(nums1,nums2,1,false,dp);
        int ans = solveTab(nums1,nums2);

        return ans;
    }
};