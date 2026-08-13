class Solution {
public:
    int totalFruit(vector<int>& nums) {
        // maxlen of subarray with two character
        if(nums.size()==1) return 1;
        int i=0;
        int j=0;
        unordered_map<int,int> mp;
        int maxcount=0;
        while(j<nums.size()){
           mp[nums[j]]++;
           while(mp.size()>2){
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                mp.erase(nums[i]);
                i++;
           }
           maxcount=max(maxcount,j-i+1);
           j++;
        }
        return maxcount;
    }
};