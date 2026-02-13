
class Solution {
public:
int inorder(TreeNode* root){
    // base case
    if(root==NULL)
    return 0;

    int left=1+inorder(root->left);
    int right=1+inorder(root->right);

    return max(left,right);
}
    int maxDepth(TreeNode* root) {
        return inorder(root);
    }
};