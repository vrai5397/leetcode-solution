class Solution {
public:
vector<vector<int>> ans;


void subsequence(vector<int>& arr, vector<int>& helper, int idx, int target){
    // base case
     if(target==0){
        ans.push_back(helper);
        
        return;

     }
    for(int i=idx;i<arr.size();i++){
         
        if(arr[i]>target) break; // array is in the sorted form
        if(i>idx && arr[i]==arr[i-1]) continue;
        helper.push_back(arr[i]);
        subsequence(arr,helper,i+1,target-arr[i]);
        helper.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end()); 
    vector<int> helper;
    subsequence(arr, helper, 0, target);
return ans;
  
    }
};
