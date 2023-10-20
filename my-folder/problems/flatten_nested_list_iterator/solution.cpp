/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
    vector<int> flatten(vector<NestedInteger> &nestedList)
    {
        vector<int> res;

        for(auto i : nestedList)
        {
            if(i.isInteger())
            {
                res.push_back(i.getInteger());
            }
            else
            {
                auto subList = flatten(i.getList());
                res.insert(res.end(),subList.begin(),subList.end());
            }
        }

        return res;
    }
public:
    vector<int> flat;
    int index;
    NestedIterator(vector<NestedInteger> &nestedList) {
        flat = flatten(nestedList);
        index = 0;        
    }
    
    int next() {
        return flat[index++];        
    }
    
    bool hasNext() {
        return index < flat.size();   
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */