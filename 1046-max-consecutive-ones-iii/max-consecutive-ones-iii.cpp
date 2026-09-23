class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int countzeros=0;
        int i=0;
        int j=0;
        int maxlen=0;
        while(j<nums.size()){
            if(nums[j]==0)
            countzeros++;
            while(countzeros>k){
                if(nums[i]==0)
                countzeros--;
                i++;
            }
            maxlen=max(maxlen,j-i+1);
            j++;
        }
        return maxlen;
    }
};