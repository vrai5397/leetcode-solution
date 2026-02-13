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
int height_tree(TreeNode* root){
    // base case
    if(root==NULL)
    return 0;

    int left=height_tree(root->left);
    int right=height_tree(root->right);
    return 1+max(left,right);
}

int diameter(TreeNode* root){
    // base case
if(root==NULL)
return 0;
    int root_diameter=height_tree(root->left)+height_tree(root->right);
 int max_diameter=max(root_diameter,max(diameter(root->left),diameter(root->right)));
 return max_diameter;
}
    int diameterOfBinaryTree(TreeNode* root) {
         // recursion ke ander recursion
return diameter(root);
    }
};