
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL)
        return {};
        // in queue node,hd,level
        queue<pair<TreeNode*,pair<int,int>>> q;
        // in map hd,level,which element
        map<int,map<int,vector<int>>> mp;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* curr=p.first;
            int hd=p.second.first;
            int level=p.second.second;

            mp[hd][level].push_back(curr->val);
            if(curr->left)
            q.push({curr->left,{hd-1,level+1}});
            if(curr->right)
            q.push({curr->right,{hd+1,level+1}});
        }

       // travese in map
      vector<vector<int>> ans;

for(auto &x : mp){  // each column
    vector<int> column;
    
    for(auto &y : x.second){  // each level
        sort(y.second.begin(), y.second.end());  // sort overlapping
        
        for(auto z : y.second){
            column.push_back(z);
        }
    }
    
    ans.push_back(column);
}

return ans;

    }
};