class Solution {
public:
void reverse(vector<int>& nums,int i,int j){
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        int n=nums.size();
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                index=i-1;
                break;
            }
        }
        if(index==-1){
            reverse(nums,0,n-1);
            return;
        }
        int maxi=nums[index];
        int maxiindex=-1;
        for(int i=n-1;i>=index+1;i--){
           if(nums[i]>maxi){
             maxi=nums[i];
             maxiindex=i;
             break;
           }
        }
        swap(nums[index],nums[maxiindex]);
        reverse(nums,index+1,n-1);
    }
};