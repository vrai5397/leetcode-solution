class Solution {
public:
bool canWe(vector<int>& weights,int days,int mid){
    int ourdays=1;
    int sum=0;
    for(int i=0;i<weights.size();i++){
         if(sum + weights[i] > mid){
            ourdays++; // day1
            
            sum=weights[i];
         }
         else
          sum+=weights[i];
    }
   
    if(ourdays<=days) return true;
    return false;
}
    int shipWithinDays(vector<int>& weights, int days) {
        // we have to find capacity
        int hi = accumulate(weights.begin(), weights.end(), 0);
        int lo=INT_MIN;
        for(auto x:weights)
        lo=max(lo,x);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canWe(weights,days,mid)){
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return lo;
    }
};