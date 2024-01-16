class RandomizedSet {
    vector<int> arr;
    unordered_map<int,int> m;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {

        if(m.find(val) != m.end())
            return false;
        
        arr.push_back(val);
        m[val] = arr.size()-1;
        return true;
    }
    
    bool remove(int val) {

        if(m.find(val) == m.end())
            return false;
        
        auto it = m.find(val);
        arr[it->second] = arr.back();
        arr.pop_back();
        m[arr[it->second]] = it->second;
        m.erase(val);
        return true;
        
    }
    
    int getRandom() {
        return arr[rand()%arr.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */