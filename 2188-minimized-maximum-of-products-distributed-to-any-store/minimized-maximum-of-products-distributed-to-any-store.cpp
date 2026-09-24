class Solution {
public:
int cansolve(vector<int>& arr,int mid,int n){
    int count=0;
    for(auto x:arr){
        if(x%mid==0)
        count+=x/mid;
        else
        count+=(x/mid)+1;
    }
    if(count<=n)
    return true;
    return false;
}
    int minimizedMaximum(int n, vector<int>& quantities) {
        int lo=1;
        int hi=INT_MIN;
        for(auto x:quantities){
            hi=max(hi,x);
        }
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(cansolve(quantities,mid,n))
            hi=mid-1;
            else
            lo=mid+1;
        }
        return lo;
    }
};