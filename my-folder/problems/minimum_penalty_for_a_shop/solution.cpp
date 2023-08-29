class Solution {
public:
    int bestClosingTime(string customers) {

        int sum = 0;
        int mini = 0;

        int index = customers.size();

        for(int i = index-1;i>=0;i--)
        {
            if(customers[i] == 'N')
                sum = sum - 1;
            else
                sum += 1;
            
            if(mini >= sum)
            {
                mini = sum;
                index = i;
            }

        }

        return index;
        
    }
};