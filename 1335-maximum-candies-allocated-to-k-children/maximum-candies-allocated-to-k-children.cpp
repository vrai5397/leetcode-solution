class Solution {
public:
int cansolve(vector<int>& arr,int mid,long long k){
        long long count=0;
        for(int i=0;i<arr.size();i++){
            count+=arr[i]/mid;
        }
        if(count<k)
        return false;
        return true;
}
    int maximumCandies(vector<int>& candies, long long k) {
        int lo=1;
        int hi=INT_MIN;
        for(auto x:candies){
            hi=max(hi,x);
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(cansolve(candies,mid,k))
            lo=mid+1;
            else
            hi=mid-1;
        }
        return hi;
    }
};