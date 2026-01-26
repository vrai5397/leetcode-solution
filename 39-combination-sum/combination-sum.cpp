class Solution {
public:

vector<vector<int>> ans;

void subsequence(vector<int>& arr, vector<int>& helper, int i, int sum){
    if(sum<0) return;
    if(i >= arr.size()){
        if(sum == 0)
            ans.push_back(helper);
        return;
    }

 
        subsequence(arr, helper, i+1, sum); // not pick
            helper.push_back(arr[i]);
     subsequence(arr, helper, i, sum - arr[i]); // pick
     helper.pop_back(); 
   
}

    vector<vector<int>> combinationSum(vector<int>& arr, int target) {
        vector<int> helper;
     subsequence(arr,helper,0,target);
     return ans;
    }
};