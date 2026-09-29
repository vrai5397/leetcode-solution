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
int solve(TreeNode* root){
    if(root==NULL)
    return 0;
    int ans1=solve(root->left);
    int ans2=solve(root->right);
    return 1+max(ans1,ans2);
}
    int maxDepth(TreeNode* root) {
      return solve(root);
    }
};