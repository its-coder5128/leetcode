class Solution {
public:
    int solve(vector<int>& vec,int index,int end)
    {
        if(end == vec.size() - 1)
            return 0;
        if(index == vec.size())
            return 1e9;
        

        int exclude = solve(vec,index+1,end);

        int include = 1e9;

        if(vec[index]>end)
            include = 1 + solve(vec,index+1,vec[index]);
        
        return min(include,exclude);
    }
    int minTaps(int n, vector<int>& ranges) {

        vector<int> vec(n+1,0);

        for(int i=0;i<n+1;i++)
        {
            int s = max(0,i - ranges[i]);
            int e = min(n,i + ranges[i]);

            vec[s] = max(vec[s],e);
        }

        int i = 0;
        int maxi = INT_MIN;
        int ans = 0;

        while(i<vec.size()-1)
        {
            maxi = max(maxi,vec[i]);
            cout<<maxi<<" "<<i<<endl;

            if(maxi <= i)
                return -1;
            
            ans++;
            int temp =INT_MIN;
            while(i<maxi)
            {
                temp = max(temp,vec[i++]);
            }

            maxi = temp;

        }

       

        return ans;
        
    }
};