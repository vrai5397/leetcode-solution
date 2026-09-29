
class Solution {
public:
int solve(TreeNode* root){
    if(root==NULL)
    return 0;
   return 1+max(solve(root->left),solve(root->right));
}
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        return true;
        bool ans1=abs(solve(root->left)-solve(root->right))<=1;
        bool ans2=isBalanced(root->left);
        bool ans3=isBalanced(root->right);
        return ans1&&ans2&&ans3;

    }
};