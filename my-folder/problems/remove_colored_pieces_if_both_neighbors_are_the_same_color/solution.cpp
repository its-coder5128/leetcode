class Solution {
public:
    bool winnerOfGame(string colors) {
        int a=0,b=0;
        int cntA=0,cntB=0;

        for(int i=0;i<colors.size();i++)
        {
            if(colors[i]=='A')
            {
                cntA++;
                b += max(0,cntB-2);
                cntB=0;
            }
            else if(colors[i]=='B')
            {
                cntB++;
                a += max(0,cntA-2);
                cntA=0;
            }   
        }
        b += max(0,cntB-2);
        a += max(0,cntA-2);
        cout<<a<<" "<<b;
        if(a>b)
            return true;
        return false;
        
    }
};