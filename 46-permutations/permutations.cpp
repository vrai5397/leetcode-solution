class Solution {
public: 
// we use the extra space method
vector<vector<int>> ans;
void permutations(vector<int>& arr,vector<int>& helper,vector<int>& map,int idx){
    // base case
    if(helper.size()==arr.size()){
        ans.push_back(helper);
        return;
    }

    for(int i=0;i<arr.size();i++){
        if(map[i]!=1){
          helper.push_back(arr[i]);
           map[i]=1;
           permutations(arr,helper,map,i+1);
           helper.pop_back();
           map[i]=0;
        }
       
    }
}

    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> helper;
        vector<int> map(nums.size(),0);
        permutations(nums,helper,map,0);
        return ans;
    }
};