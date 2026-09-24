class Solution {
public:
int cansolve(vector<int>& arr,int mid,int days){
    int sum=0;
    int ourdays=1;
    for(int i=0;i<arr.size();i++){
       
        if(sum+arr[i]<=mid){
           sum+=arr[i];
        }
        else{
            sum=arr[i];
            ourdays++;
        }
    }
    if(ourdays<=days)
    return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
           int lo = 0;
        int hi = 0;

        for(auto x : weights) {
            lo = max(lo, x);
            hi += x;
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(cansolve(weights,mid,days))
            hi=mid-1;
            else
            lo=mid+1;
        }
        return lo;
    }
};