// we have to swap the value
class Solution {
public:
void solve(TreeNode* root){
    //
    if(root==NULL)
    return;
    TreeNode* temp1=root->left;
    root->left=root->right;
    root->right=temp1;
    solve(root->left);
    solve(root->right);
}
    TreeNode* invertTree(TreeNode* root) {
        solve(root);
        return root;
    }
};