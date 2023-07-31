class Solution {
public:
    void solve(vector<int>& skill,long long target,long long chemistry,
    long long &ans,int players,long long index)
    {
        if(target == 0 && players == 0)
        {
            ans += chemistry;
            return;
        }
        else if(target < 0 || players < 0)
        {
            return;
        }
        if(index == skill.size())
        {
            return;
        }

        //exclude
        solve(skill,target,chemistry,ans,players,index + 1);

        //include
        solve(skill,target - skill[index],chemistry * skill[index],ans,players-1,index + 1);

    }

    long long dividePlayers(vector<int>& skill) {
        
        long long sum = 0;

        long long n=skill.size();

        for(int i=0;i<n;i++)
        {
            sum += skill[i];
        }

        // if((sum & 1) && n>2)
        //     return -1;

        long long target = sum/(n/2);

        long long ans = 0;
        long long chemistry = 1;

        sort(skill.begin(),skill.end());

        int i=0,j=n-1;

        while(i<j)
        {
            int first = skill[i];
            int second = skill[j];
            if( first + second == target)
            {
                chemistry = first*second;
                ans += chemistry;
                i++;
                j--;
            }
            else{
                return -1;
            }
        }

        

        return ans;
    }
};