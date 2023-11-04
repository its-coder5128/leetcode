class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {


        int L = INT_MIN,R = INT_MAX;
        for(int i = 0;i<left.size();i++)
            L = max(L,left[i]);
        for(int i = 0;i<right.size();i++)
            R = min(R,right[i]);

        int maxi = max(L,n - R);
        return maxi;

    }
};