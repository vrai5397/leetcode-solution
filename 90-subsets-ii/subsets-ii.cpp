class Solution {
public:
vector<vector<int>> ans;
void subset_sum(vector<int>& arr,vector<int>& helper,int idx){
    // base case
    ans.push_back(helper);

    for(int i=idx;i<arr.size();i++){
        if(i>idx&& arr[i]==arr[i-1]) continue;
        helper.push_back(arr[i]);
        subset_sum(arr,helper,i+1);
        helper.pop_back();
    }
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> helper;
         subset_sum(nums,helper,0);
         return ans;
    }
};