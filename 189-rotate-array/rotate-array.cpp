class Solution {
public:
void reverse(vector<int>& nums,int i,int j){
    // swap karte jana hai
    while(i<=j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
    void rotate(vector<int>& nums, int k) {
        // reverse full array
        // reverse 0 to k-1
        // k to n-1
        //7 6 5 4 3 2 1
        // 5 6 7 1 2 3 4
        if(nums.size()==1)
        return;
        k=k%nums.size();
        reverse(nums,0,nums.size()-1);
        reverse(nums,0,k-1);
        reverse(nums,k,nums.size()-1);
    }
};