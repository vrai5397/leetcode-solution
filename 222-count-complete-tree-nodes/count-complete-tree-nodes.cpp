
class Solution {
public:

int count_nodes(TreeNode* root){
    // base case
if(root==NULL)
return 0;
    int left=count_nodes(root->left);
    int right=count_nodes(root->right);

    return 1+left+right;
}
    int countNodes(TreeNode* root) {
        return count_nodes(root);
    }
};