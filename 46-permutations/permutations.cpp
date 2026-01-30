class Solution {
public:
    vector<vector<int>> ans;

    void permutations(vector<int>& arr, int idx){
        if(idx == arr.size()){
            ans.push_back(arr);
            return;
        }

        for(int i = idx; i < arr.size(); i++){
            swap(arr[idx], arr[i]);
            permutations(arr, idx + 1);   // FIXED
            swap(arr[idx], arr[i]);       // backtrack
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        permutations(nums, 0);
        return ans;
    }
};
