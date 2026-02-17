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
vector<string> ans;

void path(TreeNode* root,string& helper){
    // base case
    if(root==NULL)
    return;
    int len=helper.size();
    helper+=to_string(root->val);
    
    if(root->left==NULL&& root->right==NULL){
        ans.push_back(helper);
        
    }
  else{
     helper+="->";
     path(root->left,helper);
     path(root->right,helper);
  }
    helper.resize(len);

    
}
    vector<string> binaryTreePaths(TreeNode* root) {
        string helper="";
        path(root,helper);
        return ans;
    }
};