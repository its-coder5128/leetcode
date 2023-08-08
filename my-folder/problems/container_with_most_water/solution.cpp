class Solution {
public:
    int maxArea(vector<int>& height) {

        int i=0;
        int j=height.size() - 1;

        int maxi = INT_MIN;

        while(i<j)
        {
            int area = min(height[i],height[j]) * (j-i);
            maxi = max( maxi ,area );

            if(height[i] > height[j])
                j--;
            else if(height[i] < height[j])
                i++;
            else{
                i++;
                j--;
            }
        }

        return maxi;
        
    }
};