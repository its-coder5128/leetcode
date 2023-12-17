class FoodRatings {
    struct comp {
    // Operator() overloading
        bool operator()(const pair<int,string>& p1,
                        const pair<int,string>& p2)
        {
            // new definition
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    class cmp{
        public:
        bool operator()(pair<int,string>& p1,
                        pair<int,string>& p2)
        {
            // new definition
            if (p1.first == p2.first) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        }
    };
    unordered_map<string,pair<int,string>> foodTorate;
    unordered_map<string,set<pair<int,string>>> hRated;


public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++)
        {
            foodTorate[foods[i]] = {ratings[i],cuisines[i]};
            hRated[cuisines[i]].insert({(-1)*ratings[i],foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodTorate[food].second; 
        hRated[cuisine].erase({(-1)*foodTorate[food].first,food});
        hRated[cuisine].insert({(-1)*newRating,food});
        foodTorate[food] = {newRating,cuisine};
        return;
    }
    
    string highestRated(string cuisine) {
        return (*hRated[cuisine].begin()).second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */