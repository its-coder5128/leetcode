class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long xors = 0;

        for(auto it:nums)
            xors ^= it;
        
        // int index = 0;

        // while((xors & (1<<index)) == 0 )
        //     index++;
        
        xors = ((xors&(xors-1))^xors);
        int same = 0;
        int diff = 0;

        for(auto it:nums)
        {
            if(it & xors)
                same ^= it;
            else
                diff ^= it;
        }

        return {same,diff};
    }
};