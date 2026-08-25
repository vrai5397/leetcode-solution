class MedianFinder {
public:
priority_queue<int> left;
priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       if(left.empty()||num<=left.top()){
         left.push(num);
       }
       else
       right.push(num);
    
    // step 2 size diff must be 1
    if(left.size()>right.size()+1){
        right.push(left.top());
        left.pop();
    }
    

    if(right.size()>left.size()){
        left.push(right.top());
        right.pop();
    }
    }
    double findMedian() {
        if(left.size() == right.size()) {
            return (double(left.top()) + double(right.top())) / 2;
        }
        
        // left has one extra element
        return left.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */