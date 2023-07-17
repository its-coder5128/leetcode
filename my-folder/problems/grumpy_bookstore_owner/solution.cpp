class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {

        int sum1=0;
        int sum2=0;
        int maxi=-1;

        int s=0;
        int e=minutes-1;

            for(int i=0;i<customers.size();i++)
            {
                if( !(i>=s && i<=e) )
                {
                    if(grumpy[i] == 0)
                        sum2 += customers[i];
                }
                else{
                    sum1 += customers[i];
                }
            }

            cout<< sum1<<" "<< sum2<<endl;

        while(e<customers.size())
        {
            maxi = max(maxi,sum1+sum2);
            
            e++;
            
            if(e>=customers.size())
            {
                break;
            }

            sum1 = sum1 + customers[e] - customers[s];

            if(grumpy[e] == 0)
                sum2= sum2 - customers[e];
            
            if(grumpy[s] == 0)
                sum2= sum2 + customers[s];
            
            s++;
        }

        return maxi;

        
    }
};