class Solution {
public:
bool cansolve(vector<int>& arr,int speed,int h){
    long long time=0;
    for(auto x:arr){
        if(x%speed==0)
        time+=x/speed;
        else
        time+=(x/speed)+1;
    }
    if(time<=h)
    return true;
    return false;
}
    int minEatingSpeed(vector<int>& piles, int h) {
        // hi=mid-1
        // lo=mid+1;
        int lo=1;
        int hi=INT_MIN;
        for(auto x:piles)
        hi=max(hi,x);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(cansolve(piles,mid,h))
            hi=mid-1;
            else
            lo=mid+1;
        }
        return lo;
    }
};