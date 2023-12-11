class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int a=0,b=0,c=0;
        int cnt1=0;
        int cnt2=0;
        int cnt3=0;

        for(auto num:arr)
        {
           
            if(a==num)
            {
                cnt1++;
            }
            else if(b==num)
            {
                cnt2++;
            }
            else if(c==num)
            {
                cnt3++;
            }
            else if(cnt1 == 0)
            {
                a = num;
                cnt1 = 1;
            }
            else if(cnt2 == 0)
            {
                b = num;
                cnt2 = 1;
            }
            else if(cnt3 == 0)
            {
                c = num;
                cnt3 = 1;
            }
            else
            {
                cnt1--;
                cnt2--;
                cnt3--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        cnt3 = 0;
        for(auto num:arr)
        {
            if(num == a)    
                cnt1++;
            else if(num == b)    
                cnt2++;
            else if(num == c)    
                cnt3++;

        }
        int n = arr.size()/4;
        if(cnt1>n)
            return a;
        else if(cnt2 > n)
            return b;
        else if(cnt3>n)
            return c;
        
        return -1;
    }
};