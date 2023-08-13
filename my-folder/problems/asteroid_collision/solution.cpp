class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {

        vector<int> ans;

        int n = asteroids.size();

        ans.push_back(asteroids[0]);

        int i = 1;

        while(i<n)
        {
            if(ans.size() == 0)
            {
                ans.push_back(asteroids[i]);
                i++;
                continue;
            }
            int temp = ans.back();

            if(temp > 0)
            {
                if(asteroids[i] > 0)
                {
                    ans.push_back(asteroids[i]);
                    i++;
                }
                else
                {
                    if(temp < abs(asteroids[i]))
                    {
                        ans.pop_back();
                    }
                    else if(temp == abs(asteroids[i]))
                    {
                        ans.pop_back();
                        i++;
                    }
                    else
                        i++;
                }
            }
            else{

                ans.push_back(asteroids[i]);
                i++;
            }
        }

        return ans;
        
    }
};