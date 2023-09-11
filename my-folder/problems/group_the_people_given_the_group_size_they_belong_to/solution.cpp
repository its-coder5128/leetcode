class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        int greatest = groupSizes[0];
        int least = groupSizes[0];
        for(int i = 1; i < groupSizes.size(); i++){
            if(greatest < groupSizes[i]){
                greatest = groupSizes[i];
            }
            if(least > groupSizes[i]){
                least = groupSizes[i];
            }
        }
        for(int i = least; i <= greatest; i++){
            int j = 0;
            vector<int>ans1;
            int count = 0;
            while(j < groupSizes.size()){
                if(groupSizes[j] == i){
                    ans1.push_back(j);
                    count++;
                }
                if(count == i){
                    ans.push_back(ans1);
                    ans1.clear();
                    count = 0;
                }
                j++;
            }
            
        }
        return ans;
    }
};