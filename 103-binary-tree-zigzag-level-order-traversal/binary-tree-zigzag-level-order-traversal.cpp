/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL)
        return {};
        queue<TreeNode*> q;
        q.push(root);
        bool lefttoright=true;
        vector<vector<int>> ans;
        while(!q.empty()){
            int size=q.size();
            vector<int> helper(size,0);
            for(int i=0;i<size;i++){
                TreeNode* temp=q.front();
                q.pop();
                int index=lefttoright ? i:size-i-1;
                helper[index]=temp->val;
                if(temp->left)
                q.push(temp->left);
                if(temp->right)
                q.push(temp->right);
                
            }
            ans.push_back(helper);
            lefttoright=!lefttoright;
        }
        return ans;
    }
};