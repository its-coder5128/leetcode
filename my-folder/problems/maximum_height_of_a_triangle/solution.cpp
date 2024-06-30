class Solution {
public:
    int solve(int h,int x,int y)
    {
        int turn = 1;
        while(true)
        {
            if(turn == 1)
            {
                y = y - (h+1);
                turn = 0;
                if(y < 0)
                    break;
            }
            else{
                x = x - (h+1);
                turn = 1;
                if(x < 0)
                    break;   
            }
            h++;
        }
        
        return h;
    }
    int maxHeightOfTriangle(int red, int blue) {
        
        int stBlue = solve(0,blue,red);
        int stRed = solve(0,red,blue);
        
        return max(stBlue,stRed);
    }
};