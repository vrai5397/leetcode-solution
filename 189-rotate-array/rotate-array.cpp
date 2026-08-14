class Solution {
public:
void reversearr(vector<int>& nums,int i,int j){
    while(i<j){
        swap(nums[i],nums[j]);
        i++;
        j--;
    }
}
    void rotate(vector<int>& nums, int k) {
        //7 6 5 4 3 2 1
        //0 to k-1
        // k to n-1
        
        int n=nums.size();
         k=k%n;
      reversearr(nums,0,n-1);
      reversearr(nums,0,k-1);
      reversearr(nums,k,n-1);
    }
};