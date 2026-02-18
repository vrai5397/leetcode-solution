
class Solution {
public:
TreeNode* lca(TreeNode* root,TreeNode* p,TreeNode* q){
    // base case
    if(root==NULL)
    return NULL;
    if(root==p||root==q)
    return root;

    TreeNode* left=lca(root->left,p,q);
    TreeNode* right=lca(root->right,p,q);
    if(left==NULL)
    return right;
    else if(right==NULL)
    return left;
    else
    return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};