class Solution {
public:
bool canWe(vector<int>& nums,int k,long long mid){
        int subarr=1;
        long long sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]>mid){
                subarr++;
                sum=nums[i];
            }
            else{
                sum+=nums[i];
            }
        }
        return subarr<=k;
}
    int splitArray(vector<int>& nums, int k) {
        if(k>nums.size())
        return -1;
long long lo = *max_element(nums.begin(), nums.end());
long long hi = accumulate(nums.begin(), nums.end(), 0LL);
 while(lo<=hi){
    long long mid=lo+(hi-lo)/2;
    if(canWe(nums,k,mid)){
        hi=mid-1;
    }
    else
    lo=mid+1;
 }
 return lo;
    }
};