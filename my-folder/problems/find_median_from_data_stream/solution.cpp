class MedianFinder {
    priority_queue <int, vector<int>, greater<int>> minarr;//minheap
    priority_queue <int> maxarr;//maxheap
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxarr.push(num);

        while(!minarr.empty() && !maxarr.empty() && minarr.top() < maxarr.top())
        {
            minarr.push(maxarr.top());
            maxarr.pop();
        }

        while(minarr.size() < maxarr.size())
        {
            minarr.push(maxarr.top());
            maxarr.pop();
        }
        while(minarr.size() > maxarr.size())
        {
            maxarr.push(minarr.top());
            minarr.pop();
        }

    }

    
    double findMedian() {
        double ans;

        if(minarr.size() > maxarr.size())
        {
            ans = minarr.top();
        }
        else if(minarr.size() < maxarr.size())
        {
            ans = maxarr.top();
        }
        else{
            int x = minarr.top();
            int y = maxarr.top();
            ans = ((double)x + (double)y)/(double)2;
        }

        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */