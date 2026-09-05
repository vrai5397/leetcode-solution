class Solution {
public:
bool canWe(vector<int>& nums,int threshold,int mid){
    int sum=0;
    for(int i=0;i<nums.size();i++){
        if(nums[i]%mid==0)
        sum+=nums[i]/mid;
        else{
            sum+=nums[i]/mid;
            sum++;// to make ceil
        }

    }
    if(sum<=threshold)
    return true;

    return false;
}
    int smallestDivisor(vector<int>& nums, int threshold) {
        int lo=1;
        int hi=INT_MIN;
        for(auto x:nums)
        hi=max(hi,x);
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(canWe(nums,threshold,mid)){
                hi=mid-1;
            }
            else 
            lo=mid+1;

        }
        return lo;
    }
};