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
int height(TreeNode* root){
    if(root==NULL)
    return 0;

    int left=height(root->left);
    int right=height(root->right);

    return 1+max(left,right);
}

bool check(TreeNode* root){
    // base case
   if(root==NULL)
   return true;
    int left=height(root->left);
    int right=height(root->right);
    int diff=abs(left-right);
  
     bool left_subtree=check(root->left);
     bool right_subtree=check(root->right);
     if(diff<=1&& left_subtree&& right_subtree)
     return true;

     return false;


}
    bool isBalanced(TreeNode* root) {
        return check(root);
    }
};