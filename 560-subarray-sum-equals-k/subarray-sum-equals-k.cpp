class Solution {
public:

    int subarraySum(vector<int>& nums, int k) {
        // when ever listen subarray sum equeals k
       unordered_map<int,int> mp;
       mp[0]=1;
       int sum=0;
       int count=0;
       for(int i=0;i<nums.size();i++){
             sum+=nums[i];
             if(mp.find(sum-k)!=mp.end()){
                // found in map
                count+=mp[sum-k];
             }
             mp[sum]++;
       }
       return count;
    }
};